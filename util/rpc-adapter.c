//
// RPC Stub Adapter for BOF Environment
//
// Provides the necessary functions for MIDL-generated RPC stubs
// to work within a Beacon Object File context.
//

#include <windows.h>

// Import MSVCRT functions for memory management
DECLSPEC_IMPORT void* __cdecl MSVCRT$malloc(size_t size);
DECLSPEC_IMPORT void __cdecl MSVCRT$free(void* ptr);
DECLSPEC_IMPORT void* __cdecl MSVCRT$memset(void* dest, int c, size_t count);

// MIDL_user_allocate - Required by RPC runtime
// Called by NDR marshalling code to allocate memory
void* __RPC_USER MIDL_user_allocate(size_t size) {
    return MSVCRT$malloc(size);
}

// MIDL_user_free - Required by RPC runtime
// Called by NDR marshalling code to free memory
void __RPC_USER MIDL_user_free(void* ptr) {
    if (ptr) {
        MSVCRT$free(ptr);
    }
}