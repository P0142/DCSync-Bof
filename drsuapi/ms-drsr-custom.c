/*
 * Minimal RPC stub for DCSync  
 * Format strings extracted from ms-drsr_c.c (full MIDL-generated stub)
 * 
 * Key offsets (from working stub):
 *   IDL_DRSBind: 0
 *   IDL_DRSUnbind: 60  
 *   IDL_DRSReplicaSync: 104
 *   IDL_DRSGetNCChanges: 160
 */

#include <windows.h>
#include "ms-drsr.h"

// BOF compatibility
#define NdrClientCall2 RPCRT4$NdrClientCall2

DECLSPEC_IMPORT CLIENT_CALL_RETURN RPC_VAR_ENTRY RPCRT4$NdrClientCall2(
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    ...);

extern void* __RPC_USER MIDL_user_allocate(size_t);
extern void __RPC_USER MIDL_user_free(void*);

// Format string structures (exact sizes from working stub)
typedef struct _ms2Ddrsr_MIDL_TYPE_FORMAT_STRING {
    short Pad;
    unsigned char Format[7867];
} ms2Ddrsr_MIDL_TYPE_FORMAT_STRING;

typedef struct _ms2Ddrsr_MIDL_PROC_FORMAT_STRING {
    short Pad;
    unsigned char Format[2113];
} ms2Ddrsr_MIDL_PROC_FORMAT_STRING;

// Forward declarations
static const ms2Ddrsr_MIDL_TYPE_FORMAT_STRING ms2Ddrsr__MIDL_TypeFormatString;
const ms2Ddrsr_MIDL_PROC_FORMAT_STRING ms2Ddrsr__MIDL_ProcFormatString;
static RPC_BINDING_HANDLE drsuapi__MIDL_AutoBindHandle;

// RPC Client Interface (drsuapi UUID)
static const RPC_CLIENT_INTERFACE drsuapi___RpcClientInterface = {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xe3514235,0x4b06,0x11d1,{0xab,0x04,0x00,0xc0,0x4f,0xc2,0xdc,0xd2}},{4,0}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    0, 0, 0, 0, 0, 0
};

// Stub descriptor  
static const MIDL_STUB_DESC drsuapi_StubDesc = {
    (void*)&drsuapi___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &drsuapi__MIDL_AutoBindHandle,
    0, 0, 0, 0,
    ms2Ddrsr__MIDL_TypeFormatString.Format,
    1, 0x60000, 0, 0x8000253, 0, 0, 0, 0x1, 0, 0, 0
};

// Minimal wrapper functions (DCSyncer style with PROVEN offsets)
ULONG IDL_DRSBind(
    handle_t rpc_handle,
    UUID *puuidClientDsa,
    DRS_EXTENSIONS *pextClient,
    DRS_EXTENSIONS **ppextServer,
    DRS_HANDLE *phDrs)
{
    return (ULONG)NdrClientCall2(
        (PMIDL_STUB_DESC)&drsuapi_StubDesc,
        (PFORMAT_STRING)&ms2Ddrsr__MIDL_ProcFormatString.Format[0],
        rpc_handle, puuidClientDsa, pextClient, ppextServer, phDrs
    ).Simple;
}

ULONG IDL_DRSUnbind(DRS_HANDLE *phDrs)
{
    return (ULONG)NdrClientCall2(
        (PMIDL_STUB_DESC)&drsuapi_StubDesc,
        (PFORMAT_STRING)&ms2Ddrsr__MIDL_ProcFormatString.Format[60],
        phDrs
    ).Simple;
}

ULONG IDL_DRSReplicaSync(
    DRS_HANDLE hDrs,
    DWORD dwVersion,
    DRS_MSG_REPSYNC *pmsgSync)
{
    return (ULONG)NdrClientCall2(
        (PMIDL_STUB_DESC)&drsuapi_StubDesc,
        (PFORMAT_STRING)&ms2Ddrsr__MIDL_ProcFormatString.Format[104],
        hDrs, dwVersion, pmsgSync
    ).Simple;
}

ULONG IDL_DRSGetNCChanges(
    DRS_HANDLE hDrs,
    DWORD dwInVersion,
    DRS_MSG_GETCHGREQ *pmsgIn,
    DWORD *pdwOutVersion,
    DRS_MSG_GETCHGREPLY *pmsgOut)
{
    return (ULONG)NdrClientCall2(
        (PMIDL_STUB_DESC)&drsuapi_StubDesc,
        (PFORMAT_STRING)&ms2Ddrsr__MIDL_ProcFormatString.Format[160],
        hDrs, dwInVersion, pmsgIn, pdwOutVersion, pmsgOut
    ).Simple;
}

// PROC Format String (extracted from WORKING ms-drsr_c.c)
const ms2Ddrsr_MIDL_PROC_FORMAT_STRING ms2Ddrsr__MIDL_ProcFormatString =
    {
        0,
        {
	/* Procedure IDL_DRSBind */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x44 ),	/* 68 */
/* 16 */	NdrFcShort( 0x40 ),	/* 64 */
/* 18 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 20 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 22 */	NdrFcShort( 0x1 ),	/* 1 */
/* 24 */	NdrFcShort( 0x1 ),	/* 1 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter puuidClientDsa */

/* 30 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pextClient */

/* 36 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 38 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 40 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter ppextServer */

/* 42 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 44 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 46 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter phDrs */

/* 48 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 50 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 52 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 54 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 56 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 58 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSUnbind */

/* 60 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 62 */	NdrFcLong( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x1 ),	/* 1 */
/* 68 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 70 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 72 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 74 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 76 */	NdrFcShort( 0x38 ),	/* 56 */
/* 78 */	NdrFcShort( 0x40 ),	/* 64 */
/* 80 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phDrs */

/* 92 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 94 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 96 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Return value */

/* 98 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaSync */

/* 104 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x2 ),	/* 2 */
/* 112 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 114 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 116 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 118 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 120 */	NdrFcShort( 0x2c ),	/* 44 */
/* 122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 124 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 126 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 136 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 138 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 140 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 144 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgSync */

/* 148 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 152 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 156 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetNCChanges */

/* 160 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x3 ),	/* 3 */
/* 168 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 170 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 172 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 174 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 176 */	NdrFcShort( 0x2c ),	/* 44 */
/* 178 */	NdrFcShort( 0x24 ),	/* 36 */
/* 180 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 182 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 184 */	NdrFcShort( 0x1 ),	/* 1 */
/* 186 */	NdrFcShort( 0x1 ),	/* 1 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 192 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 194 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 196 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 204 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 208 */	NdrFcShort( 0x114 ),	/* Type Offset=276 */

	/* Parameter pdwOutVersion */

/* 210 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 212 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 216 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 218 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 220 */	NdrFcShort( 0x382 ),	/* Type Offset=898 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSUpdateRefs */

/* 228 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x4 ),	/* 4 */
/* 236 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 238 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 240 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 242 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0x2c ),	/* 44 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 250 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 260 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 262 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 264 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgUpdRefs */

/* 272 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 276 */	NdrFcShort( 0x6ac ),	/* Type Offset=1708 */

	/* Return value */

/* 278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 280 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaAdd */

/* 284 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x5 ),	/* 5 */
/* 292 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 294 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 296 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 298 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 300 */	NdrFcShort( 0x2c ),	/* 44 */
/* 302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 304 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 306 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x1 ),	/* 1 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 316 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 318 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 320 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 324 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgAdd */

/* 328 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 330 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 332 */	NdrFcShort( 0x712 ),	/* Type Offset=1810 */

	/* Return value */

/* 334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 336 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaDel */

/* 340 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x6 ),	/* 6 */
/* 348 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 350 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 352 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 354 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 356 */	NdrFcShort( 0x2c ),	/* 44 */
/* 358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 360 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 362 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x1 ),	/* 1 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 372 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 374 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 376 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgDel */

/* 384 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 386 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 388 */	NdrFcShort( 0x7b8 ),	/* Type Offset=1976 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaModify */

/* 396 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x7 ),	/* 7 */
/* 404 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 406 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 408 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 410 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 412 */	NdrFcShort( 0x2c ),	/* 44 */
/* 414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 416 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 418 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x1 ),	/* 1 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 428 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 430 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 432 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgMod */

/* 440 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 442 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 444 */	NdrFcShort( 0x7f2 ),	/* Type Offset=2034 */

	/* Return value */

/* 446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 448 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSVerifyNames */

/* 452 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 460 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 462 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 464 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 466 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 468 */	NdrFcShort( 0x2c ),	/* 44 */
/* 470 */	NdrFcShort( 0x24 ),	/* 36 */
/* 472 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 474 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 476 */	NdrFcShort( 0x1 ),	/* 1 */
/* 478 */	NdrFcShort( 0x1 ),	/* 1 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 484 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 486 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 488 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 492 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 496 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 498 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 500 */	NdrFcShort( 0x834 ),	/* Type Offset=2100 */

	/* Parameter pdwOutVersion */

/* 502 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 504 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 508 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 510 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 512 */	NdrFcShort( 0x89a ),	/* Type Offset=2202 */

	/* Return value */

/* 514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 516 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetMemberships */

/* 520 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x9 ),	/* 9 */
/* 528 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 530 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 532 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 534 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 536 */	NdrFcShort( 0x2c ),	/* 44 */
/* 538 */	NdrFcShort( 0x24 ),	/* 36 */
/* 540 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 542 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 544 */	NdrFcShort( 0x1 ),	/* 1 */
/* 546 */	NdrFcShort( 0x1 ),	/* 1 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 552 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 554 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 556 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 564 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 566 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 568 */	NdrFcShort( 0x8fc ),	/* Type Offset=2300 */

	/* Parameter pdwOutVersion */

/* 570 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 572 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 576 */	NdrFcShort( 0xa113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=40 */
/* 578 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 580 */	NdrFcShort( 0x96e ),	/* Type Offset=2414 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSInterDomainMove */

/* 588 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0xa ),	/* 10 */
/* 596 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 598 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 600 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 602 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 604 */	NdrFcShort( 0x2c ),	/* 44 */
/* 606 */	NdrFcShort( 0x24 ),	/* 36 */
/* 608 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 610 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 612 */	NdrFcShort( 0x1 ),	/* 1 */
/* 614 */	NdrFcShort( 0x1 ),	/* 1 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 620 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 622 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 624 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 632 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 634 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 636 */	NdrFcShort( 0xa18 ),	/* Type Offset=2584 */

	/* Parameter pdwOutVersion */

/* 638 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 640 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 644 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 646 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 648 */	NdrFcShort( 0xad2 ),	/* Type Offset=2770 */

	/* Return value */

/* 650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 652 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetNT4ChangeLog */

/* 656 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0xb ),	/* 11 */
/* 664 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 666 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 668 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 670 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 672 */	NdrFcShort( 0x2c ),	/* 44 */
/* 674 */	NdrFcShort( 0x24 ),	/* 36 */
/* 676 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 678 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 680 */	NdrFcShort( 0x1 ),	/* 1 */
/* 682 */	NdrFcShort( 0x1 ),	/* 1 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 688 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 690 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 692 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 694 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 696 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 700 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 702 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 704 */	NdrFcShort( 0xb28 ),	/* Type Offset=2856 */

	/* Parameter pdwOutVersion */

/* 706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 708 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 712 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 714 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 716 */	NdrFcShort( 0xb74 ),	/* Type Offset=2932 */

	/* Return value */

/* 718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 720 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSCrackNames */

/* 724 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0xc ),	/* 12 */
/* 732 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 734 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 736 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 738 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 740 */	NdrFcShort( 0x2c ),	/* 44 */
/* 742 */	NdrFcShort( 0x24 ),	/* 36 */
/* 744 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 746 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 748 */	NdrFcShort( 0x1 ),	/* 1 */
/* 750 */	NdrFcShort( 0x1 ),	/* 1 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 756 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 758 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 760 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 768 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 772 */	NdrFcShort( 0xbfe ),	/* Type Offset=3070 */

	/* Parameter pdwOutVersion */

/* 774 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 776 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 780 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 782 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 784 */	NdrFcShort( 0xc60 ),	/* Type Offset=3168 */

	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSWriteSPN */

/* 792 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0xd ),	/* 13 */
/* 800 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 802 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 804 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 806 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 808 */	NdrFcShort( 0x2c ),	/* 44 */
/* 810 */	NdrFcShort( 0x24 ),	/* 36 */
/* 812 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 814 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 816 */	NdrFcShort( 0x1 ),	/* 1 */
/* 818 */	NdrFcShort( 0x1 ),	/* 1 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 824 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 826 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 828 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 830 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 832 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 836 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 838 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 840 */	NdrFcShort( 0xce2 ),	/* Type Offset=3298 */

	/* Parameter pdwOutVersion */

/* 842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 844 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 848 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 850 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 852 */	NdrFcShort( 0xd48 ),	/* Type Offset=3400 */

	/* Return value */

/* 854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 856 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSRemoveDsServer */

/* 860 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0xe ),	/* 14 */
/* 868 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 870 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 872 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 874 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 876 */	NdrFcShort( 0x2c ),	/* 44 */
/* 878 */	NdrFcShort( 0x24 ),	/* 36 */
/* 880 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 882 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 884 */	NdrFcShort( 0x1 ),	/* 1 */
/* 886 */	NdrFcShort( 0x1 ),	/* 1 */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 892 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 894 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 896 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 900 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 904 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 906 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 908 */	NdrFcShort( 0xd72 ),	/* Type Offset=3442 */

	/* Parameter pdwOutVersion */

/* 910 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 912 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 916 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 918 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 920 */	NdrFcShort( 0xdac ),	/* Type Offset=3500 */

	/* Return value */

/* 922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 924 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSRemoveDsDomain */

/* 928 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0xf ),	/* 15 */
/* 936 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 938 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 940 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 942 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 944 */	NdrFcShort( 0x2c ),	/* 44 */
/* 946 */	NdrFcShort( 0x24 ),	/* 36 */
/* 948 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 950 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 952 */	NdrFcShort( 0x1 ),	/* 1 */
/* 954 */	NdrFcShort( 0x1 ),	/* 1 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 960 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 962 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 964 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 972 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 974 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 976 */	NdrFcShort( 0xdd0 ),	/* Type Offset=3536 */

	/* Parameter pdwOutVersion */

/* 978 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 980 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 984 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 986 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 988 */	NdrFcShort( 0xe02 ),	/* Type Offset=3586 */

	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSDomainControllerInfo */

/* 996 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1004 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1006 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1008 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1010 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1012 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1014 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1016 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1018 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1022 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1028 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1030 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1032 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1040 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1042 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1044 */	NdrFcShort( 0xe26 ),	/* Type Offset=3622 */

	/* Parameter pdwOutVersion */

/* 1046 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1048 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1052 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1054 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1056 */	NdrFcShort( 0xe5a ),	/* Type Offset=3674 */

	/* Return value */

/* 1058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1060 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSAddEntry */

/* 1064 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1072 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1074 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1076 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1078 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1080 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1082 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1084 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1086 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1088 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1090 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1096 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1098 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1100 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1108 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1112 */	NdrFcShort( 0x1030 ),	/* Type Offset=4144 */

	/* Parameter pdwOutVersion */

/* 1114 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1116 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1120 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1122 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1124 */	NdrFcShort( 0x10a4 ),	/* Type Offset=4260 */

	/* Return value */

/* 1126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1128 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSExecuteKCC */

/* 1132 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1140 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1142 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1144 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1146 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1148 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1154 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1164 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1166 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1168 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1176 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1178 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1180 */	NdrFcShort( 0x12de ),	/* Type Offset=4830 */

	/* Return value */

/* 1182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1184 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetReplInfo */

/* 1188 */	0x0,		/* 0 */
			0x49,		/* Old Flags:  full ptr, */
/* 1190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1196 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1198 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1200 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1202 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1204 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1206 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1208 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1210 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1214 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1220 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1222 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1224 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1232 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1234 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1236 */	NdrFcShort( 0x130a ),	/* Type Offset=4874 */

	/* Parameter pdwOutVersion */

/* 1238 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1240 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1244 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1246 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1248 */	NdrFcShort( 0x136a ),	/* Type Offset=4970 */

	/* Return value */

/* 1250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1252 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSAddSidHistory */

/* 1256 */	0x0,		/* 0 */
			0x49,		/* Old Flags:  full ptr, */
/* 1258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1264 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1266 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1268 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1270 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1272 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1274 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1276 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1278 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1280 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1282 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1288 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1290 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1292 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1294 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1300 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1302 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1304 */	NdrFcShort( 0x17e8 ),	/* Type Offset=6120 */

	/* Parameter pdwOutVersion */

/* 1306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1308 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1312 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1314 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1316 */	NdrFcShort( 0x1888 ),	/* Type Offset=6280 */

	/* Return value */

/* 1318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1320 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetMemberships2 */

/* 1324 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1332 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1334 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1336 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1338 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1340 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1342 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1344 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1346 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1348 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1350 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1356 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1358 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1360 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1362 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1368 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1370 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1372 */	NdrFcShort( 0x18ac ),	/* Type Offset=6316 */

	/* Parameter pdwOutVersion */

/* 1374 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1376 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1380 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1382 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1384 */	NdrFcShort( 0x190a ),	/* Type Offset=6410 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaVerifyObjects */

/* 1392 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1400 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1402 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1404 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1406 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1408 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1414 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1424 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1426 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1428 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwVersion */

/* 1430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgVerify */

/* 1436 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1438 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1440 */	NdrFcShort( 0x1968 ),	/* Type Offset=6504 */

	/* Return value */

/* 1442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1444 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSGetObjectExistence */

/* 1448 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1456 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1458 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1460 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1462 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1464 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1466 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1468 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1470 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1480 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1482 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1484 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1492 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1496 */	NdrFcShort( 0x19a0 ),	/* Type Offset=6560 */

	/* Parameter pdwOutVersion */

/* 1498 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1500 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1504 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1506 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1508 */	NdrFcShort( 0x19e8 ),	/* Type Offset=6632 */

	/* Return value */

/* 1510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1512 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSQuerySitesByCost */

/* 1516 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1524 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1526 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1528 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1530 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1532 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1534 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1536 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1538 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1540 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1542 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1548 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1550 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1552 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1560 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1564 */	NdrFcShort( 0x1a46 ),	/* Type Offset=6726 */

	/* Parameter pdwOutVersion */

/* 1566 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1568 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1572 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1574 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1576 */	NdrFcShort( 0x1aac ),	/* Type Offset=6828 */

	/* Return value */

/* 1578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1580 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSInitDemotion */

/* 1584 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1592 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1594 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1596 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1598 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1600 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1602 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1604 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1606 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1610 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1616 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1618 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1620 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1624 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1628 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1630 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1632 */	NdrFcShort( 0x1b0c ),	/* Type Offset=6924 */

	/* Parameter pdwOutVersion */

/* 1634 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1636 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1640 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1642 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1644 */	NdrFcShort( 0x1b30 ),	/* Type Offset=6960 */

	/* Return value */

/* 1646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1648 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReplicaDemotion */

/* 1652 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1658 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1660 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1662 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1664 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1666 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1668 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1670 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1672 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1674 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1676 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1684 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1686 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1688 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1696 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1698 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1700 */	NdrFcShort( 0x1b54 ),	/* Type Offset=6996 */

	/* Parameter pdwOutVersion */

/* 1702 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1704 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1708 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1710 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1712 */	NdrFcShort( 0x1b8c ),	/* Type Offset=7052 */

	/* Return value */

/* 1714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1716 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSFinishDemotion */

/* 1720 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1728 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1730 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1732 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1734 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1736 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1738 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1740 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1742 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1744 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1752 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1754 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1756 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1760 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1764 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1766 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1768 */	NdrFcShort( 0x1bb0 ),	/* Type Offset=7088 */

	/* Parameter pdwOutVersion */

/* 1770 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1772 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1776 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1778 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1780 */	NdrFcShort( 0x1be8 ),	/* Type Offset=7144 */

	/* Return value */

/* 1782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1784 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSAddCloneDC */

/* 1788 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1796 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1798 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1800 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1802 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1804 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1806 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1808 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1810 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1812 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1814 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1820 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1822 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1824 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1826 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1832 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1834 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1836 */	NdrFcShort( 0x1c14 ),	/* Type Offset=7188 */

	/* Parameter pdwOutVersion */

/* 1838 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1840 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1844 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 1846 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1848 */	NdrFcShort( 0x1c4c ),	/* Type Offset=7244 */

	/* Return value */

/* 1850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1852 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSWriteNgcKey */

/* 1856 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1862 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1864 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1866 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1868 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1870 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1872 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1874 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1876 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1878 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1880 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1882 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1888 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1890 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1892 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1900 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1902 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1904 */	NdrFcShort( 0x1ca0 ),	/* Type Offset=7328 */

	/* Parameter pdwOutVersion */

/* 1906 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1908 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1912 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1914 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1916 */	NdrFcShort( 0x1cf0 ),	/* Type Offset=7408 */

	/* Return value */

/* 1918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1920 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DRSReadNgcKey */

/* 1924 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1932 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1934 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1936 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1938 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1940 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1942 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1944 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1946 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1948 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1950 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hDrs */

/* 1956 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1958 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1960 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter dwInVersion */

/* 1962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 1968 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1970 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1972 */	NdrFcShort( 0x1d14 ),	/* Type Offset=7444 */

	/* Parameter pdwOutVersion */

/* 1974 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1976 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 1980 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1982 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1984 */	NdrFcShort( 0x1d46 ),	/* Type Offset=7494 */

	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DSAPrepareScript */

/* 1992 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2002 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2004 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2008 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2010 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2012 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2016 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwInVersion */

/* 2022 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 2028 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2030 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2032 */	NdrFcShort( 0x1d90 ),	/* Type Offset=7568 */

	/* Parameter pdwOutVersion */

/* 2034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2036 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 2040 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2042 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2044 */	NdrFcShort( 0x1db4 ),	/* Type Offset=7604 */

	/* Return value */

/* 2046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2048 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IDL_DSAExecuteScript */

/* 2052 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2060 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2062 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2064 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2068 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2070 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2072 */	0xa,		/* 10 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2074 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwInVersion */

/* 2082 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgIn */

/* 2088 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2090 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2092 */	NdrFcShort( 0x1e40 ),	/* Type Offset=7744 */

	/* Parameter pdwOutVersion */

/* 2094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2096 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmsgOut */

/* 2100 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2102 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2104 */	NdrFcShort( 0x1e8a ),	/* Type Offset=7818 */

	/* Return value */

/* 2106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2108 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

// TYPE Format String (extracted from WORKING ms-drsr_c.c)
static const ms2Ddrsr_MIDL_TYPE_FORMAT_STRING ms2Ddrsr__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */
			0x12, 0x0,	/* FC_UP */
/* 26 */	NdrFcShort( 0x18 ),	/* Offset= 24 (50) */
/* 28 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 30 */	NdrFcShort( 0x1 ),	/* 1 */
/* 32 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 34 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 36 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 38 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 40 */	NdrFcLong( 0x1 ),	/* 1 */
/* 44 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 48 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 50 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 52 */	NdrFcShort( 0x4 ),	/* 4 */
/* 54 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (28) */
/* 56 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 58 */
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 60 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (24) */
/* 62 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	0x30,		/* FC_BIND_CONTEXT */
			0xa0,		/* Ctxt flags:  via ptr, out, */
/* 68 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 70 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 72 */	NdrFcShort( 0x2 ),	/* Offset= 2 (74) */
/* 74 */	0x30,		/* FC_BIND_CONTEXT */
			0xe1,		/* Ctxt flags:  via ptr, in, out, can't be null */
/* 76 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 78 */	0x30,		/* FC_BIND_CONTEXT */
			0x41,		/* Ctxt flags:  in, can't be null */
/* 80 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 82 */
			0x11, 0x0,	/* FC_RP */
/* 84 */	NdrFcShort( 0x2 ),	/* Offset= 2 (86) */
/* 86 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 88 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 90 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 92 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 94 */	0x0 ,
			0x0,		/* 0 */
/* 96 */	NdrFcLong( 0x0 ),	/* 0 */
/* 100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x2 ),	/* Offset= 2 (106) */
/* 106 */	NdrFcShort( 0x40 ),	/* 64 */
/* 108 */	NdrFcShort( 0x2 ),	/* 2 */
/* 110 */	NdrFcLong( 0x1 ),	/* 1 */
/* 114 */	NdrFcShort( 0x42 ),	/* Offset= 66 (180) */
/* 116 */	NdrFcLong( 0x2 ),	/* 2 */
/* 120 */	NdrFcShort( 0x76 ),	/* Offset= 118 (238) */
/* 122 */	NdrFcShort( 0xffff ),	/* Offset= -1 (121) */
/* 124 */
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 126 */	NdrFcShort( 0x1c ),	/* 28 */
/* 128 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 130 */
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 132 */	NdrFcShort( 0x1c ),	/* 28 */
/* 134 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 136 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (124) */
/* 138 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 140 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 142 */	NdrFcShort( 0x2 ),	/* 2 */
/* 144 */	0x9,		/* Corr desc: FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 146 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 148 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 150 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcLong( 0xa00001 ),	/* 10485761 */
/* 160 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 162 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 164 */	NdrFcShort( 0x38 ),	/* 56 */
/* 166 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (140) */
/* 168 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 170 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 172 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (12) */
/* 174 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 176 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (130) */
/* 178 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 180 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 182 */	NdrFcShort( 0x28 ),	/* 40 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* Offset= 12 (198) */
/* 188 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 190 */	0x0,		/* 0 */
			NdrFcShort( 0xff4d ),	/* Offset= -179 (12) */
			0x36,		/* FC_POINTER */
/* 194 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 196 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 198 */
			0x11, 0x0,	/* FC_RP */
/* 200 */	NdrFcShort( 0xffda ),	/* Offset= -38 (162) */
/* 202 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 204 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 206 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 210 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 212 */	NdrFcShort( 0xfff4 ),	/* -12 */
/* 214 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 216 */	0x0 ,
			0x0,		/* 0 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 226 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 228 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 230 */	NdrFcShort( 0x10 ),	/* 16 */
/* 232 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (206) */
/* 234 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 236 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 238 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 240 */	NdrFcShort( 0x40 ),	/* 64 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x10 ),	/* Offset= 16 (260) */
/* 246 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 248 */	0x0,		/* 0 */
			NdrFcShort( 0xff13 ),	/* Offset= -237 (12) */
			0x36,		/* FC_POINTER */
/* 252 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 254 */	0x0,		/* 0 */
			NdrFcShort( 0xff0d ),	/* Offset= -243 (12) */
			0x40,		/* FC_STRUCTPAD4 */
/* 258 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 260 */
			0x11, 0x0,	/* FC_RP */
/* 262 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (162) */
/* 264 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 266 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 268 */
			0x12, 0x0,	/* FC_UP */
/* 270 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (228) */
/* 272 */
			0x11, 0x0,	/* FC_RP */
/* 274 */	NdrFcShort( 0x2 ),	/* Offset= 2 (276) */
/* 276 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 278 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 282 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 284 */	0x0 ,
			0x0,		/* 0 */
/* 286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x2 ),	/* Offset= 2 (296) */
/* 296 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 298 */	NdrFcShort( 0x6 ),	/* 6 */
/* 300 */	NdrFcLong( 0x4 ),	/* 4 */
/* 304 */	NdrFcShort( 0x134 ),	/* Offset= 308 (612) */
/* 306 */	NdrFcLong( 0x5 ),	/* 5 */
/* 310 */	NdrFcShort( 0x14a ),	/* Offset= 330 (640) */
/* 312 */	NdrFcLong( 0x7 ),	/* 7 */
/* 316 */	NdrFcShort( 0x16c ),	/* Offset= 364 (680) */
/* 318 */	NdrFcLong( 0x8 ),	/* 8 */
/* 322 */	NdrFcShort( 0x18a ),	/* Offset= 394 (716) */
/* 324 */	NdrFcLong( 0xa ),	/* 10 */
/* 328 */	NdrFcShort( 0x1ba ),	/* Offset= 442 (770) */
/* 330 */	NdrFcLong( 0xb ),	/* 11 */
/* 334 */	NdrFcShort( 0x1ec ),	/* Offset= 492 (826) */
/* 336 */	NdrFcShort( 0xffff ),	/* Offset= -1 (335) */
/* 338 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 340 */	NdrFcShort( 0x18 ),	/* 24 */
/* 342 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 344 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 346 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 348 */	NdrFcShort( 0x1 ),	/* 1 */
/* 350 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 356 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 362 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 366 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 368 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 370 */	NdrFcShort( 0x10 ),	/* 16 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x6 ),	/* Offset= 6 (380) */
/* 376 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 378 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 380 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 382 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (346) */
/* 384 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 386 */	NdrFcShort( 0x18 ),	/* 24 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x0 ),	/* Offset= 0 (390) */
/* 392 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 394 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 396 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (368) */
/* 398 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 400 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 410 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 416 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 420 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 424 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 426 */	0x0 ,
			0x0,		/* 0 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 436 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 438 */	NdrFcShort( 0xffca ),	/* Offset= -54 (384) */
/* 440 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 442 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 444 */	NdrFcShort( 0x10 ),	/* 16 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x6 ),	/* Offset= 6 (454) */
/* 450 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 452 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 454 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 456 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (400) */
/* 458 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 460 */	NdrFcShort( 0x18 ),	/* 24 */
/* 462 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 464 */	NdrFcShort( 0xfe3c ),	/* Offset= -452 (12) */
/* 466 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 468 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 470 */	NdrFcShort( 0x18 ),	/* 24 */
/* 472 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 474 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 476 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 478 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 484 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 488 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 490 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (458) */
/* 492 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 494 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 496 */	NdrFcShort( 0x10 ),	/* 16 */
/* 498 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (468) */
/* 500 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 502 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 504 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 506 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x4 ),	/* 4 */
/* 510 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 512 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 514 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 516 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 518 */	NdrFcLong( 0x1 ),	/* 1 */
/* 522 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 526 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 528 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 530 */	NdrFcShort( 0xc ),	/* 12 */
/* 532 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (506) */
/* 534 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 536 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 538 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 540 */	NdrFcShort( 0x70 ),	/* 112 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x1a ),	/* Offset= 26 (570) */
/* 546 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 548 */	NdrFcShort( 0xfde8 ),	/* Offset= -536 (12) */
/* 550 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 552 */	NdrFcShort( 0xfde4 ),	/* Offset= -540 (12) */
/* 554 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 556 */	0x0,		/* 0 */
			NdrFcShort( 0xff25 ),	/* Offset= -219 (338) */
			0x36,		/* FC_POINTER */
/* 560 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 562 */	0x0,		/* 0 */
			NdrFcShort( 0xff87 ),	/* Offset= -121 (442) */
			0x8,		/* FC_LONG */
/* 566 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 568 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 570 */
			0x11, 0x0,	/* FC_RP */
/* 572 */	NdrFcShort( 0xfe66 ),	/* Offset= -410 (162) */
/* 574 */
			0x12, 0x0,	/* FC_UP */
/* 576 */	NdrFcShort( 0xffae ),	/* Offset= -82 (494) */
/* 578 */
			0x12, 0x0,	/* FC_UP */
/* 580 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (528) */
/* 582 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 584 */	NdrFcShort( 0x1 ),	/* 1 */
/* 586 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 588 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 590 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 592 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 594 */	NdrFcLong( 0x1 ),	/* 1 */
/* 598 */	NdrFcLong( 0x100 ),	/* 256 */
/* 602 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 604 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 606 */	NdrFcShort( 0x4 ),	/* 4 */
/* 608 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (582) */
/* 610 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 612 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 614 */	NdrFcShort( 0x88 ),	/* 136 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0xc ),	/* Offset= 12 (630) */
/* 620 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 622 */	NdrFcShort( 0xfd9e ),	/* Offset= -610 (12) */
/* 624 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 626 */	0x0,		/* 0 */
			NdrFcShort( 0xffa7 ),	/* Offset= -89 (538) */
			0x5b,		/* FC_END */
/* 630 */
			0x11, 0x0,	/* FC_RP */
/* 632 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (604) */
/* 634 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 640 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 642 */	NdrFcShort( 0x60 ),	/* 96 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x1a ),	/* Offset= 26 (672) */
/* 648 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 650 */	NdrFcShort( 0xfd82 ),	/* Offset= -638 (12) */
/* 652 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 654 */	NdrFcShort( 0xfd7e ),	/* Offset= -642 (12) */
/* 656 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 658 */	0x0,		/* 0 */
			NdrFcShort( 0xfebf ),	/* Offset= -321 (338) */
			0x36,		/* FC_POINTER */
/* 662 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 664 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 666 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 668 */	NdrFcShort( 0xffde ),	/* Offset= -34 (634) */
/* 670 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 672 */
			0x11, 0x0,	/* FC_RP */
/* 674 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (162) */
/* 676 */
			0x12, 0x0,	/* FC_UP */
/* 678 */	NdrFcShort( 0xff48 ),	/* Offset= -184 (494) */
/* 680 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 682 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x12 ),	/* Offset= 18 (704) */
/* 688 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 690 */	NdrFcShort( 0xfd5a ),	/* Offset= -678 (12) */
/* 692 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 694 */	0x0,		/* 0 */
			NdrFcShort( 0xff63 ),	/* Offset= -157 (538) */
			0x36,		/* FC_POINTER */
/* 698 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 700 */	0x0,		/* 0 */
			NdrFcShort( 0xfefd ),	/* Offset= -259 (442) */
			0x5b,		/* FC_END */
/* 704 */
			0x11, 0x0,	/* FC_RP */
/* 706 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (604) */
/* 708 */
			0x12, 0x0,	/* FC_UP */
/* 710 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (528) */
/* 712 */
			0x12, 0x0,	/* FC_UP */
/* 714 */	NdrFcShort( 0xff46 ),	/* Offset= -186 (528) */
/* 716 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 718 */	NdrFcShort( 0x80 ),	/* 128 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x20 ),	/* Offset= 32 (754) */
/* 724 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 726 */	NdrFcShort( 0xfd36 ),	/* Offset= -714 (12) */
/* 728 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 730 */	NdrFcShort( 0xfd32 ),	/* Offset= -718 (12) */
/* 732 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 734 */	0x0,		/* 0 */
			NdrFcShort( 0xfe73 ),	/* Offset= -397 (338) */
			0x36,		/* FC_POINTER */
/* 738 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 740 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 742 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 744 */	NdrFcShort( 0xff92 ),	/* Offset= -110 (634) */
/* 746 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 748 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 750 */	NdrFcShort( 0xfecc ),	/* Offset= -308 (442) */
/* 752 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 754 */
			0x11, 0x0,	/* FC_RP */
/* 756 */	NdrFcShort( 0xfdae ),	/* Offset= -594 (162) */
/* 758 */
			0x12, 0x0,	/* FC_UP */
/* 760 */	NdrFcShort( 0xfef6 ),	/* Offset= -266 (494) */
/* 762 */
			0x12, 0x0,	/* FC_UP */
/* 764 */	NdrFcShort( 0xff14 ),	/* Offset= -236 (528) */
/* 766 */
			0x12, 0x0,	/* FC_UP */
/* 768 */	NdrFcShort( 0xff10 ),	/* Offset= -240 (528) */
/* 770 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 772 */	NdrFcShort( 0x88 ),	/* 136 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x22 ),	/* Offset= 34 (810) */
/* 778 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 780 */	NdrFcShort( 0xfd00 ),	/* Offset= -768 (12) */
/* 782 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 784 */	NdrFcShort( 0xfcfc ),	/* Offset= -772 (12) */
/* 786 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 788 */	0x0,		/* 0 */
			NdrFcShort( 0xfe3d ),	/* Offset= -451 (338) */
			0x36,		/* FC_POINTER */
/* 792 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 794 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 796 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 798 */	NdrFcShort( 0xff5c ),	/* Offset= -164 (634) */
/* 800 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 802 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 804 */	NdrFcShort( 0xfe96 ),	/* Offset= -362 (442) */
/* 806 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 808 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 810 */
			0x11, 0x0,	/* FC_RP */
/* 812 */	NdrFcShort( 0xfd76 ),	/* Offset= -650 (162) */
/* 814 */
			0x12, 0x0,	/* FC_UP */
/* 816 */	NdrFcShort( 0xfebe ),	/* Offset= -322 (494) */
/* 818 */
			0x12, 0x0,	/* FC_UP */
/* 820 */	NdrFcShort( 0xfedc ),	/* Offset= -292 (528) */
/* 822 */
			0x12, 0x0,	/* FC_UP */
/* 824 */	NdrFcShort( 0xfed8 ),	/* Offset= -296 (528) */
/* 826 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 828 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x26 ),	/* Offset= 38 (870) */
/* 834 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 836 */	NdrFcShort( 0xfcc8 ),	/* Offset= -824 (12) */
/* 838 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 840 */	NdrFcShort( 0xfcc4 ),	/* Offset= -828 (12) */
/* 842 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 844 */	0x0,		/* 0 */
			NdrFcShort( 0xfe05 ),	/* Offset= -507 (338) */
			0x36,		/* FC_POINTER */
/* 848 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 850 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 852 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0xff24 ),	/* Offset= -220 (634) */
/* 856 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 858 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 860 */	NdrFcShort( 0xfe5e ),	/* Offset= -418 (442) */
/* 862 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 864 */	0x0,		/* 0 */
			NdrFcShort( 0xfcab ),	/* Offset= -853 (12) */
			0x40,		/* FC_STRUCTPAD4 */
/* 868 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 870 */
			0x11, 0x0,	/* FC_RP */
/* 872 */	NdrFcShort( 0xfd3a ),	/* Offset= -710 (162) */
/* 874 */
			0x12, 0x0,	/* FC_UP */
/* 876 */	NdrFcShort( 0xfe82 ),	/* Offset= -382 (494) */
/* 878 */
			0x12, 0x0,	/* FC_UP */
/* 880 */	NdrFcShort( 0xfea0 ),	/* Offset= -352 (528) */
/* 882 */
			0x12, 0x0,	/* FC_UP */
/* 884 */	NdrFcShort( 0xfe9c ),	/* Offset= -356 (528) */
/* 886 */
			0x12, 0x0,	/* FC_UP */
/* 888 */	NdrFcShort( 0xfd6c ),	/* Offset= -660 (228) */
/* 890 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 892 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 894 */
			0x11, 0x0,	/* FC_RP */
/* 896 */	NdrFcShort( 0x2 ),	/* Offset= 2 (898) */
/* 898 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 900 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 902 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 904 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 906 */	0x0 ,
			0x0,		/* 0 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x2 ),	/* Offset= 2 (918) */
/* 918 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 920 */	NdrFcShort( 0x5 ),	/* 5 */
/* 922 */	NdrFcLong( 0x1 ),	/* 1 */
/* 926 */	NdrFcShort( 0x140 ),	/* Offset= 320 (1246) */
/* 928 */	NdrFcLong( 0x2 ),	/* 2 */
/* 932 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1334) */
/* 934 */	NdrFcLong( 0x6 ),	/* 6 */
/* 938 */	NdrFcShort( 0x21e ),	/* Offset= 542 (1480) */
/* 940 */	NdrFcLong( 0x7 ),	/* 7 */
/* 944 */	NdrFcShort( 0x254 ),	/* Offset= 596 (1540) */
/* 946 */	NdrFcLong( 0x9 ),	/* 9 */
/* 950 */	NdrFcShort( 0x2b6 ),	/* Offset= 694 (1644) */
/* 952 */	NdrFcShort( 0xffff ),	/* Offset= -1 (951) */
/* 954 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 956 */	NdrFcShort( 0x1 ),	/* 1 */
/* 958 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 964 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 970 */	NdrFcLong( 0x1900000 ),	/* 26214400 */
/* 974 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 976 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 978 */	NdrFcShort( 0x10 ),	/* 16 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x6 ),	/* Offset= 6 (988) */
/* 984 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 986 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 988 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 990 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (954) */
/* 992 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1002 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 1012 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1016 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1018 */	0x0 ,
			0x0,		/* 0 */
/* 1020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1028 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1030 */	NdrFcShort( 0xffca ),	/* Offset= -54 (976) */
/* 1032 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1034 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1036 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1046) */
/* 1042 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1044 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1046 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1048 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (992) */
/* 1050 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1052 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1056) */
/* 1058 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1060 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1062 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (1034) */
/* 1064 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1066 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1070 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1076 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1082 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 1086 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1090 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1092 */	0x0 ,
			0x0,		/* 0 */
/* 1094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1102 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1104 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1050) */
/* 1106 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1108 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1110 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1120) */
/* 1116 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1118 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1120 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1122 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1066) */
/* 1124 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1126 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0xa ),	/* Offset= 10 (1140) */
/* 1132 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1134 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1136 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (1108) */
			0x5b,		/* FC_END */
/* 1140 */
			0x12, 0x0,	/* FC_UP */
/* 1142 */	NdrFcShort( 0xfc2c ),	/* Offset= -980 (162) */
/* 1144 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1146 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1150) */
/* 1152 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1154 */	0xb,		/* FC_HYPER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1156 */	0x0,		/* 0 */
			NdrFcShort( 0xfb87 ),	/* Offset= -1145 (12) */
			0xb,		/* FC_HYPER */
/* 1160 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1162 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 1168 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1170 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1172 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1178 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 1182 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1186 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1188 */	0x0 ,
			0x0,		/* 0 */
/* 1190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1198 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1200 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1144) */
/* 1202 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1204 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1162) */
/* 1210 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1210) */
/* 1212 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1214 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1216 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1218 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0xc ),	/* Offset= 12 (1234) */
/* 1224 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1226 */	0x0,		/* 0 */
			NdrFcShort( 0xff99 ),	/* Offset= -103 (1124) */
			0x8,		/* FC_LONG */
/* 1230 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 1232 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1234 */
			0x12, 0x0,	/* FC_UP */
/* 1236 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1216) */
/* 1238 */
			0x12, 0x0,	/* FC_UP */
/* 1240 */	NdrFcShort( 0xfb34 ),	/* Offset= -1228 (12) */
/* 1242 */
			0x12, 0x0,	/* FC_UP */
/* 1244 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (1204) */
/* 1246 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1248 */	NdrFcShort( 0x90 ),	/* 144 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x20 ),	/* Offset= 32 (1284) */
/* 1254 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1256 */	NdrFcShort( 0xfb24 ),	/* Offset= -1244 (12) */
/* 1258 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1260 */	NdrFcShort( 0xfb20 ),	/* Offset= -1248 (12) */
/* 1262 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1264 */	0x0,		/* 0 */
			NdrFcShort( 0xfc61 ),	/* Offset= -927 (338) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1268 */	0x0,		/* 0 */
			NdrFcShort( 0xfc5d ),	/* Offset= -931 (338) */
			0x36,		/* FC_POINTER */
/* 1272 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1274 */	NdrFcShort( 0xfcc0 ),	/* Offset= -832 (442) */
/* 1276 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1278 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1280 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1282 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 1284 */
			0x12, 0x0,	/* FC_UP */
/* 1286 */	NdrFcShort( 0xfb9c ),	/* Offset= -1124 (162) */
/* 1288 */
			0x12, 0x0,	/* FC_UP */
/* 1290 */	NdrFcShort( 0xfce4 ),	/* Offset= -796 (494) */
/* 1292 */
			0x12, 0x0,	/* FC_UP */
/* 1294 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (1216) */
/* 1296 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1298 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1300 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1302 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1304 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1306 */	0x0 ,
			0x0,		/* 0 */
/* 1308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1316 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1318 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1320 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1330) */
/* 1326 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1328 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1330 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1332 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1296) */
/* 1334 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1340) */
/* 1342 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1344 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1318) */
/* 1346 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1348 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1350 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1352 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1354 */	NdrFcShort( 0xfac2 ),	/* Offset= -1342 (12) */
/* 1356 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 1358 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1360 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1362 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1364 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 1366 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1368 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1370 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1376 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 1380 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1382 */	NdrFcShort( 0xffde ),	/* Offset= -34 (1348) */
/* 1384 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1386 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 1388 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1390 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1360) */
/* 1392 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1394 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1396 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1398 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1400 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1404) */
/* 1406 */	0xb,		/* FC_HYPER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1408 */	0x0,		/* 0 */
			NdrFcShort( 0xfef7 ),	/* Offset= -265 (1144) */
			0x5b,		/* FC_END */
/* 1412 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1414 */	NdrFcShort( 0x58 ),	/* 88 */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1434) */
/* 1420 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1422 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1424 */	0x0,		/* 0 */
			NdrFcShort( 0xfe3f ),	/* Offset= -449 (976) */
			0x8,		/* FC_LONG */
/* 1428 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1430 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (1398) */
			0x5b,		/* FC_END */
/* 1434 */
			0x12, 0x0,	/* FC_UP */
/* 1436 */	NdrFcShort( 0xfb06 ),	/* Offset= -1274 (162) */
/* 1438 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1444 */	NdrFcShort( 0x94 ),	/* 148 */
/* 1446 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1448 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1454 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 1458 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1462 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1464 */	0x0 ,
			0x0,		/* 0 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1474 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1476 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (1412) */
/* 1478 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1480 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1482 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x26 ),	/* Offset= 38 (1524) */
/* 1488 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1490 */	NdrFcShort( 0xfa3a ),	/* Offset= -1478 (12) */
/* 1492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1494 */	NdrFcShort( 0xfa36 ),	/* Offset= -1482 (12) */
/* 1496 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1498 */	0x0,		/* 0 */
			NdrFcShort( 0xfb77 ),	/* Offset= -1161 (338) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1502 */	0x0,		/* 0 */
			NdrFcShort( 0xfb73 ),	/* Offset= -1165 (338) */
			0x36,		/* FC_POINTER */
/* 1506 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1508 */	NdrFcShort( 0xfbd6 ),	/* Offset= -1066 (442) */
/* 1510 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1512 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1514 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1516 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1518 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1520 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1522 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1524 */
			0x12, 0x0,	/* FC_UP */
/* 1526 */	NdrFcShort( 0xfaac ),	/* Offset= -1364 (162) */
/* 1528 */
			0x12, 0x0,	/* FC_UP */
/* 1530 */	NdrFcShort( 0xff70 ),	/* Offset= -144 (1386) */
/* 1532 */
			0x12, 0x0,	/* FC_UP */
/* 1534 */	NdrFcShort( 0xfec2 ),	/* Offset= -318 (1216) */
/* 1536 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1538 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (1438) */
/* 1540 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1542 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1546) */
/* 1548 */	0x8,		/* FC_LONG */
			0xd,		/* FC_ENUM16 */
/* 1550 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1552 */	NdrFcShort( 0xff16 ),	/* Offset= -234 (1318) */
/* 1554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1556 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1558 */	NdrFcShort( 0x48 ),	/* 72 */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1562) */
/* 1564 */	0xb,		/* FC_HYPER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1566 */	0x0,		/* 0 */
			NdrFcShort( 0xfe59 ),	/* Offset= -423 (1144) */
			0x8,		/* FC_LONG */
/* 1570 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1572 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 1574 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1576 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1578 */	NdrFcShort( 0x70 ),	/* 112 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1598) */
/* 1584 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1586 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1588 */	0x0,		/* 0 */
			NdrFcShort( 0xfd9b ),	/* Offset= -613 (976) */
			0x8,		/* FC_LONG */
/* 1592 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1594 */	0x0,		/* 0 */
			NdrFcShort( 0xffd9 ),	/* Offset= -39 (1556) */
			0x5b,		/* FC_END */
/* 1598 */
			0x12, 0x0,	/* FC_UP */
/* 1600 */	NdrFcShort( 0xfa62 ),	/* Offset= -1438 (162) */
/* 1602 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1608 */	NdrFcShort( 0x94 ),	/* 148 */
/* 1610 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1612 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1618 */	NdrFcLong( 0x100000 ),	/* 1048576 */
/* 1622 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1626 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1628 */	0x0 ,
			0x0,		/* 0 */
/* 1630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1640 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (1576) */
/* 1642 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1644 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1646 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x26 ),	/* Offset= 38 (1688) */
/* 1652 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1654 */	NdrFcShort( 0xf996 ),	/* Offset= -1642 (12) */
/* 1656 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1658 */	NdrFcShort( 0xf992 ),	/* Offset= -1646 (12) */
/* 1660 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1662 */	0x0,		/* 0 */
			NdrFcShort( 0xfad3 ),	/* Offset= -1325 (338) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1666 */	0x0,		/* 0 */
			NdrFcShort( 0xfacf ),	/* Offset= -1329 (338) */
			0x36,		/* FC_POINTER */
/* 1670 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1672 */	NdrFcShort( 0xfb32 ),	/* Offset= -1230 (442) */
/* 1674 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1676 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1678 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1680 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1682 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1684 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1686 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1688 */
			0x12, 0x0,	/* FC_UP */
/* 1690 */	NdrFcShort( 0xfa08 ),	/* Offset= -1528 (162) */
/* 1692 */
			0x12, 0x0,	/* FC_UP */
/* 1694 */	NdrFcShort( 0xfecc ),	/* Offset= -308 (1386) */
/* 1696 */
			0x12, 0x0,	/* FC_UP */
/* 1698 */	NdrFcShort( 0xfe1e ),	/* Offset= -482 (1216) */
/* 1700 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1702 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (1602) */
/* 1704 */
			0x11, 0x0,	/* FC_RP */
/* 1706 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1708) */
/* 1708 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 1710 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1714 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1716 */	0x0 ,
			0x0,		/* 0 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1728) */
/* 1728 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1730 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1732 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1736 */	NdrFcShort( 0xa ),	/* Offset= 10 (1746) */
/* 1738 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1742 */	NdrFcShort( 0x1e ),	/* Offset= 30 (1772) */
/* 1744 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1743) */
/* 1746 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1748 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0xc ),	/* Offset= 12 (1764) */
/* 1754 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1756 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1758 */	NdrFcShort( 0xf92e ),	/* Offset= -1746 (12) */
/* 1760 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1762 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1764 */
			0x11, 0x0,	/* FC_RP */
/* 1766 */	NdrFcShort( 0xf9bc ),	/* Offset= -1604 (162) */
/* 1768 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1770 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1772 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1774 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1778 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1794) */
/* 1780 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1782 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1784 */	NdrFcShort( 0xf914 ),	/* Offset= -1772 (12) */
/* 1786 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1788 */	0x0,		/* 0 */
			NdrFcShort( 0xf90f ),	/* Offset= -1777 (12) */
			0x40,		/* FC_STRUCTPAD4 */
/* 1792 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1794 */
			0x11, 0x0,	/* FC_RP */
/* 1796 */	NdrFcShort( 0xf99e ),	/* Offset= -1634 (162) */
/* 1798 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1800 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1802 */
			0x12, 0x0,	/* FC_UP */
/* 1804 */	NdrFcShort( 0xf9d8 ),	/* Offset= -1576 (228) */
/* 1806 */
			0x11, 0x0,	/* FC_RP */
/* 1808 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1810) */
/* 1810 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 1812 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1818 */	0x0 ,
			0x0,		/* 0 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1830) */
/* 1830 */	NdrFcShort( 0x90 ),	/* 144 */
/* 1832 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1834 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1838 */	NdrFcShort( 0x20 ),	/* Offset= 32 (1870) */
/* 1840 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1844 */	NdrFcShort( 0x32 ),	/* Offset= 50 (1894) */
/* 1846 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1850 */	NdrFcShort( 0x4e ),	/* Offset= 78 (1928) */
/* 1852 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1851) */
/* 1854 */
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 1856 */	NdrFcShort( 0x54 ),	/* 84 */
/* 1858 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1860 */
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 1862 */	NdrFcShort( 0x54 ),	/* 84 */
/* 1864 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1866 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1854) */
/* 1868 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1870 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1872 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0xa ),	/* Offset= 10 (1886) */
/* 1878 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1880 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1882 */	NdrFcShort( 0xffea ),	/* Offset= -22 (1860) */
/* 1884 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1886 */
			0x11, 0x0,	/* FC_RP */
/* 1888 */	NdrFcShort( 0xf942 ),	/* Offset= -1726 (162) */
/* 1890 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1892 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1894 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1896 */	NdrFcShort( 0x78 ),	/* 120 */
/* 1898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0xc ),	/* Offset= 12 (1912) */
/* 1902 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1904 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1906 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1908 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (1860) */
/* 1910 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1912 */
			0x11, 0x0,	/* FC_RP */
/* 1914 */	NdrFcShort( 0xf928 ),	/* Offset= -1752 (162) */
/* 1916 */
			0x12, 0x0,	/* FC_UP */
/* 1918 */	NdrFcShort( 0xf924 ),	/* Offset= -1756 (162) */
/* 1920 */
			0x12, 0x0,	/* FC_UP */
/* 1922 */	NdrFcShort( 0xf920 ),	/* Offset= -1760 (162) */
/* 1924 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1926 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1928 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1930 */	NdrFcShort( 0x90 ),	/* 144 */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x12 ),	/* Offset= 18 (1952) */
/* 1936 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1938 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1940 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1942 */	NdrFcShort( 0xffae ),	/* Offset= -82 (1860) */
/* 1944 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1946 */	0x0,		/* 0 */
			NdrFcShort( 0xf871 ),	/* Offset= -1935 (12) */
			0x36,		/* FC_POINTER */
/* 1950 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1952 */
			0x11, 0x0,	/* FC_RP */
/* 1954 */	NdrFcShort( 0xf900 ),	/* Offset= -1792 (162) */
/* 1956 */
			0x12, 0x0,	/* FC_UP */
/* 1958 */	NdrFcShort( 0xf8fc ),	/* Offset= -1796 (162) */
/* 1960 */
			0x12, 0x0,	/* FC_UP */
/* 1962 */	NdrFcShort( 0xf8f8 ),	/* Offset= -1800 (162) */
/* 1964 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1966 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1968 */
			0x12, 0x0,	/* FC_UP */
/* 1970 */	NdrFcShort( 0xf932 ),	/* Offset= -1742 (228) */
/* 1972 */
			0x11, 0x0,	/* FC_RP */
/* 1974 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1976) */
/* 1976 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 1978 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1982 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1984 */	0x0 ,
			0x0,		/* 0 */
/* 1986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1994 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1996) */
/* 1996 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1998 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2000 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2004 */	NdrFcShort( 0x4 ),	/* Offset= 4 (2008) */
/* 2006 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2005) */
/* 2008 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2010 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x8 ),	/* Offset= 8 (2022) */
/* 2016 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2018 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2020 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2022 */
			0x11, 0x0,	/* FC_RP */
/* 2024 */	NdrFcShort( 0xf8ba ),	/* Offset= -1862 (162) */
/* 2026 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2028 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 2030 */
			0x11, 0x0,	/* FC_RP */
/* 2032 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2034) */
/* 2034 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2036 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2038 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2040 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2042 */	0x0 ,
			0x0,		/* 0 */
/* 2044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2054) */
/* 2054 */	NdrFcShort( 0x80 ),	/* 128 */
/* 2056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2058 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2062 */	NdrFcShort( 0x4 ),	/* Offset= 4 (2066) */
/* 2064 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2063) */
/* 2066 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2068 */	NdrFcShort( 0x80 ),	/* 128 */
/* 2070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2072 */	NdrFcShort( 0x10 ),	/* Offset= 16 (2088) */
/* 2074 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2076 */	0x0,		/* 0 */
			NdrFcShort( 0xf7ef ),	/* Offset= -2065 (12) */
			0x36,		/* FC_POINTER */
/* 2080 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2082 */	NdrFcShort( 0xff22 ),	/* Offset= -222 (1860) */
/* 2084 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2086 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2088 */
			0x11, 0x0,	/* FC_RP */
/* 2090 */	NdrFcShort( 0xf878 ),	/* Offset= -1928 (162) */
/* 2092 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2094 */
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 2096 */
			0x11, 0x0,	/* FC_RP */
/* 2098 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2100) */
/* 2100 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2102 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2106 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2108 */	0x0 ,
			0x0,		/* 0 */
/* 2110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2120) */
/* 2120 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2122 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2124 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2128 */	NdrFcShort( 0x2e ),	/* Offset= 46 (2174) */
/* 2130 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2129) */
/* 2132 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2136 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2138 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2140 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2142 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2144 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2148 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2152 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2156 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2158 */	0x0 ,
			0x0,		/* 0 */
/* 2160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2168 */
			0x12, 0x0,	/* FC_UP */
/* 2170 */	NdrFcShort( 0xf828 ),	/* Offset= -2008 (162) */
/* 2172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2174 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2176 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0xe ),	/* Offset= 14 (2194) */
/* 2182 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2184 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2186 */	0x0,		/* 0 */
			NdrFcShort( 0xfbc9 ),	/* Offset= -1079 (1108) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2190 */	0x0,		/* 0 */
			NdrFcShort( 0xf92b ),	/* Offset= -1749 (442) */
			0x5b,		/* FC_END */
/* 2194 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2196 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (2132) */
/* 2198 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2200 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2202) */
/* 2202 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2204 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2206 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2208 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2210 */	0x0 ,
			0x0,		/* 0 */
/* 2212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2222) */
/* 2222 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2224 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2226 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2230 */	NdrFcShort( 0x2e ),	/* Offset= 46 (2276) */
/* 2232 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2231) */
/* 2234 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2240 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2242 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2244 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2254 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2258 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2260 */	0x0 ,
			0x0,		/* 0 */
/* 2262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2270 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2272 */	NdrFcShort( 0xfb84 ),	/* Offset= -1148 (1124) */
/* 2274 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2276 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2278 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0xa ),	/* Offset= 10 (2292) */
/* 2284 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2286 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2288 */	0x0,		/* 0 */
			NdrFcShort( 0xf8c9 ),	/* Offset= -1847 (442) */
			0x5b,		/* FC_END */
/* 2292 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2294 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (2234) */
/* 2296 */
			0x11, 0x0,	/* FC_RP */
/* 2298 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2300) */
/* 2300 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2302 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2306 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2308 */	0x0 ,
			0x0,		/* 0 */
/* 2310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2320) */
/* 2320 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2322 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2324 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2328 */	NdrFcShort( 0x38 ),	/* Offset= 56 (2384) */
/* 2330 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2329) */
/* 2332 */	0xb7,		/* FC_RANGE */
			0xd,		/* 13 */
/* 2334 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2338 */	NdrFcLong( 0x7 ),	/* 7 */
/* 2342 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2346 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2352 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2354 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2358 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2362 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2366 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2368 */	0x0 ,
			0x0,		/* 0 */
/* 2370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2378 */
			0x12, 0x0,	/* FC_UP */
/* 2380 */	NdrFcShort( 0xf756 ),	/* Offset= -2218 (162) */
/* 2382 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2384 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2386 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0xc ),	/* Offset= 12 (2402) */
/* 2392 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2394 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 2396 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2398 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (2332) */
/* 2400 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2402 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2404 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (2342) */
/* 2406 */
			0x12, 0x0,	/* FC_UP */
/* 2408 */	NdrFcShort( 0xf73a ),	/* Offset= -2246 (162) */
/* 2410 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2412 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2414) */
/* 2414 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2416 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2418 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2420 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2422 */	0x0 ,
			0x0,		/* 0 */
/* 2424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2432 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2434) */
/* 2434 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2436 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2438 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2442 */	NdrFcShort( 0x6e ),	/* Offset= 110 (2552) */
/* 2444 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2443) */
/* 2446 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2450 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2452 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2454 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2456 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2462 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2466 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2470 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2472 */	0x0 ,
			0x0,		/* 0 */
/* 2474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2482 */
			0x12, 0x0,	/* FC_UP */
/* 2484 */	NdrFcShort( 0xf6ee ),	/* Offset= -2322 (162) */
/* 2486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2488 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2490 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2492 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2494 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2496 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2498 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2504 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2508 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2510 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2514 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2518 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2520 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2526 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2530 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2534 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2536 */	0x0 ,
			0x0,		/* 0 */
/* 2538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2546 */
			0x12, 0x0,	/* FC_UP */
/* 2548 */	NdrFcShort( 0xf68e ),	/* Offset= -2418 (130) */
/* 2550 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2552 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2554 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0xa ),	/* Offset= 10 (2568) */
/* 2560 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2562 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2564 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2566 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2568 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2570 */	NdrFcShort( 0xff84 ),	/* Offset= -124 (2446) */
/* 2572 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2574 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (2488) */
/* 2576 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2578 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (2510) */
/* 2580 */
			0x11, 0x0,	/* FC_RP */
/* 2582 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2584) */
/* 2584 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2586 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2588 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2590 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2592 */	0x0 ,
			0x0,		/* 0 */
/* 2594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2602 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2604) */
/* 2604 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2606 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2608 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2612 */	NdrFcShort( 0xa ),	/* Offset= 10 (2622) */
/* 2614 */	NdrFcLong( 0x2 ),	/* 2 */
/* 2618 */	NdrFcShort( 0x6c ),	/* Offset= 108 (2726) */
/* 2620 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2619) */
/* 2622 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2624 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0xc ),	/* Offset= 12 (2640) */
/* 2630 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2632 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2634 */	0x0,		/* 0 */
			NdrFcShort( 0xf76f ),	/* Offset= -2193 (442) */
			0x8,		/* FC_LONG */
/* 2638 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 2640 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2642 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 2644 */
			0x12, 0x0,	/* FC_UP */
/* 2646 */	NdrFcShort( 0xfa0e ),	/* Offset= -1522 (1124) */
/* 2648 */
			0x12, 0x0,	/* FC_UP */
/* 2650 */	NdrFcShort( 0xf5b2 ),	/* Offset= -2638 (12) */
/* 2652 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2654 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2658 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2664) */
/* 2660 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2662 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2664 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2666 */	NdrFcShort( 0xf6f0 ),	/* Offset= -2320 (346) */
/* 2668 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2672 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2674 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2676 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2678 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2684 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 2688 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2692 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2694 */	0x0 ,
			0x0,		/* 0 */
/* 2696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2704 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2706 */	NdrFcShort( 0xffca ),	/* Offset= -54 (2652) */
/* 2708 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2710 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2712 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2716 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2722) */
/* 2718 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2720 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2722 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2724 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (2668) */
/* 2726 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2728 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0xe ),	/* Offset= 14 (2746) */
/* 2734 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2736 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2738 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2740 */	0x0,		/* 0 */
			NdrFcShort( 0xf705 ),	/* Offset= -2299 (442) */
			0x8,		/* FC_LONG */
/* 2744 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 2746 */
			0x12, 0x0,	/* FC_UP */
/* 2748 */	NdrFcShort( 0xf5e6 ),	/* Offset= -2586 (162) */
/* 2750 */
			0x12, 0x0,	/* FC_UP */
/* 2752 */	NdrFcShort( 0xf9a4 ),	/* Offset= -1628 (1124) */
/* 2754 */
			0x12, 0x0,	/* FC_UP */
/* 2756 */	NdrFcShort( 0xf5de ),	/* Offset= -2594 (162) */
/* 2758 */
			0x12, 0x0,	/* FC_UP */
/* 2760 */	NdrFcShort( 0xf5da ),	/* Offset= -2598 (162) */
/* 2762 */
			0x12, 0x0,	/* FC_UP */
/* 2764 */	NdrFcShort( 0xffca ),	/* Offset= -54 (2710) */
/* 2766 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2768 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2770) */
/* 2770 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2772 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2774 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2776 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2778 */	0x0 ,
			0x0,		/* 0 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2790) */
/* 2790 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2792 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2794 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2798 */	NdrFcShort( 0xe ),	/* Offset= 14 (2812) */
/* 2800 */	NdrFcLong( 0x2 ),	/* 2 */
/* 2804 */	NdrFcShort( 0x20 ),	/* Offset= 32 (2836) */
/* 2806 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2805) */
/* 2808 */
			0x12, 0x0,	/* FC_UP */
/* 2810 */	NdrFcShort( 0xf96a ),	/* Offset= -1686 (1124) */
/* 2812 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2814 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2818 */	NdrFcShort( 0xa ),	/* Offset= 10 (2828) */
/* 2820 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2822 */	0x0,		/* 0 */
			NdrFcShort( 0xf6b3 ),	/* Offset= -2381 (442) */
			0x36,		/* FC_POINTER */
/* 2826 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2828 */
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 2830 */	NdrFcShort( 0xffea ),	/* Offset= -22 (2808) */
/* 2832 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2834 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 2836 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2838 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2848) */
/* 2844 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2846 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2848 */
			0x12, 0x0,	/* FC_UP */
/* 2850 */	NdrFcShort( 0xf580 ),	/* Offset= -2688 (162) */
/* 2852 */
			0x11, 0x0,	/* FC_RP */
/* 2854 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2856) */
/* 2856 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2858 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2862 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2864 */	0x0 ,
			0x0,		/* 0 */
/* 2866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2876) */
/* 2876 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2878 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2880 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2884 */	NdrFcShort( 0x1a ),	/* Offset= 26 (2910) */
/* 2886 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2885) */
/* 2888 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2890 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2892 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2896 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2898 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2904 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 2908 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2910 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2912 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x8 ),	/* Offset= 8 (2924) */
/* 2918 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2920 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2922 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2924 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2926 */	NdrFcShort( 0xffda ),	/* Offset= -38 (2888) */
/* 2928 */
			0x11, 0x0,	/* FC_RP */
/* 2930 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2932) */
/* 2932 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 2934 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2936 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2938 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2940 */	0x0 ,
			0x0,		/* 0 */
/* 2942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2952) */
/* 2952 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2954 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2956 */	NdrFcLong( 0x1 ),	/* 1 */
/* 2960 */	NdrFcShort( 0x4e ),	/* Offset= 78 (3038) */
/* 2962 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2961) */
/* 2964 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 2966 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2968 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2970 */	NdrFcShort( 0xf6e0 ),	/* Offset= -2336 (634) */
/* 2972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2974 */	NdrFcShort( 0xf6dc ),	/* Offset= -2340 (634) */
/* 2976 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2978 */	NdrFcShort( 0xf6d8 ),	/* Offset= -2344 (634) */
/* 2980 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2982 */	NdrFcShort( 0xf6d4 ),	/* Offset= -2348 (634) */
/* 2984 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2986 */	NdrFcShort( 0xf6d0 ),	/* Offset= -2352 (634) */
/* 2988 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2990 */	NdrFcShort( 0xf6cc ),	/* Offset= -2356 (634) */
/* 2992 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2994 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2996 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2998 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3004 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3010 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 3014 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 3016 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3020 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3022 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3024 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3026 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3032 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 3036 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 3038 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 3040 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3044 */	NdrFcShort( 0xe ),	/* Offset= 14 (3058) */
/* 3046 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3048 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3050 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (2964) */
/* 3052 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3054 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3056 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3058 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3060 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (2994) */
/* 3062 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3064 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (3016) */
/* 3066 */
			0x11, 0x0,	/* FC_RP */
/* 3068 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3070) */
/* 3070 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3072 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3074 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3076 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3078 */	0x0 ,
			0x0,		/* 0 */
/* 3080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3088 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3090) */
/* 3090 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3092 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3094 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3098 */	NdrFcShort( 0x2e ),	/* Offset= 46 (3144) */
/* 3100 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3099) */
/* 3102 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3106 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3108 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3110 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3112 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3114 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3118 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 3122 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3126 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3128 */	0x0 ,
			0x0,		/* 0 */
/* 3130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3140 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3142 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3144 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3146 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0xa ),	/* Offset= 10 (3160) */
/* 3152 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3154 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3156 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3158 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3160 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3162 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (3102) */
/* 3164 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3166 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3168) */
/* 3168 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3170 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3172 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3174 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3176 */	0x0 ,
			0x0,		/* 0 */
/* 3178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3188) */
/* 3188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3190 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3192 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3196 */	NdrFcShort( 0x54 ),	/* Offset= 84 (3280) */
/* 3198 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3197) */
/* 3200 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3202 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3206 */	NdrFcShort( 0x8 ),	/* Offset= 8 (3214) */
/* 3208 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3210 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3212 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3214 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3216 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3218 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3220 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3222 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3226 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3232 */	0x0 ,
			0x0,		/* 0 */
/* 3234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3242 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3246 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3248 */	0x0 ,
			0x0,		/* 0 */
/* 3250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3258 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3260 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (3200) */
/* 3262 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3264 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3266 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x6 ),	/* Offset= 6 (3276) */
/* 3272 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3274 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3276 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3278 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3222) */
/* 3280 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3290) */
/* 3288 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3290 */
			0x12, 0x0,	/* FC_UP */
/* 3292 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (3264) */
/* 3294 */
			0x11, 0x0,	/* FC_RP */
/* 3296 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3298) */
/* 3298 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3300 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3304 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3306 */	0x0 ,
			0x0,		/* 0 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3318) */
/* 3318 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3320 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3322 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3326 */	NdrFcShort( 0x2e ),	/* Offset= 46 (3372) */
/* 3328 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3327) */
/* 3330 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3334 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3338 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3340 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3346 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 3350 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3354 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3356 */	0x0 ,
			0x0,		/* 0 */
/* 3358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3366 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3368 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3370 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3372 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3374 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0xa ),	/* Offset= 10 (3388) */
/* 3380 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3382 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3384 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 3386 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3388 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3390 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3392 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3394 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (3330) */
/* 3396 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3398 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3400) */
/* 3400 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3402 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3404 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3406 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3408 */	0x0 ,
			0x0,		/* 0 */
/* 3410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3418 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3420) */
/* 3420 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3422 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3424 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3428 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3432) */
/* 3430 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3429) */
/* 3432 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 3434 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3436 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3438 */
			0x11, 0x0,	/* FC_RP */
/* 3440 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3442) */
/* 3442 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3444 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3448 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3450 */	0x0 ,
			0x0,		/* 0 */
/* 3452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3460 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3462) */
/* 3462 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3464 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3466 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3470 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3474) */
/* 3472 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3471) */
/* 3474 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3476 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x8 ),	/* Offset= 8 (3488) */
/* 3482 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3484 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3488 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3490 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3492 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3494 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3496 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3498 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3500) */
/* 3500 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3502 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3504 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3506 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3508 */	0x0 ,
			0x0,		/* 0 */
/* 3510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3518 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3520) */
/* 3520 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3522 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3524 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3528 */	NdrFcShort( 0xffa0 ),	/* Offset= -96 (3432) */
/* 3530 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3529) */
/* 3532 */
			0x11, 0x0,	/* FC_RP */
/* 3534 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3536) */
/* 3536 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3538 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3540 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3542 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3544 */	0x0 ,
			0x0,		/* 0 */
/* 3546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3554 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3556) */
/* 3556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3558 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3560 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3564 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3568) */
/* 3566 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3565) */
/* 3568 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3574 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3578) */
/* 3576 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3578 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3580 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3582 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3584 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3586) */
/* 3586 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3588 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3590 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3592 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3594 */	0x0 ,
			0x0,		/* 0 */
/* 3596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3606) */
/* 3606 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3610 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3614 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (3432) */
/* 3616 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3615) */
/* 3618 */
			0x11, 0x0,	/* FC_RP */
/* 3620 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3622) */
/* 3622 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3624 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3628 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3630 */	0x0 ,
			0x0,		/* 0 */
/* 3632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3640 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3642) */
/* 3642 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3644 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3646 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3650 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3654) */
/* 3652 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3651) */
/* 3654 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3656 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0x6 ),	/* Offset= 6 (3666) */
/* 3662 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3664 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 3666 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3668 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3670 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3674) */
/* 3674 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 3676 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3678 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3680 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3682 */	0x0 ,
			0x0,		/* 0 */
/* 3684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3692 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3694) */
/* 3694 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3696 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3698 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3702 */	NdrFcShort( 0x64 ),	/* Offset= 100 (3802) */
/* 3704 */	NdrFcLong( 0x2 ),	/* 2 */
/* 3708 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (3924) */
/* 3710 */	NdrFcLong( 0x3 ),	/* 3 */
/* 3714 */	NdrFcShort( 0x14c ),	/* Offset= 332 (4046) */
/* 3716 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3720 */	NdrFcShort( 0x194 ),	/* Offset= 404 (4124) */
/* 3722 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3721) */
/* 3724 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3726 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3730 */	NdrFcShort( 0xa ),	/* Offset= 10 (3740) */
/* 3732 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3734 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3736 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3738 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3740 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3742 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3744 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3746 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3748 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3750 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3752 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3754 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3756 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3758 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3760 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3764 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3768 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3770 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3776 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 3780 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3784 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3786 */	0x0 ,
			0x0,		/* 0 */
/* 3788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3796 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3798 */	NdrFcShort( 0xffb6 ),	/* Offset= -74 (3724) */
/* 3800 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3802 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3804 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3808 */	NdrFcShort( 0x6 ),	/* Offset= 6 (3814) */
/* 3810 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3812 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3814 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3816 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3760) */
/* 3818 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3820 */	NdrFcShort( 0x88 ),	/* 136 */
/* 3822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3824 */	NdrFcShort( 0x1e ),	/* Offset= 30 (3854) */
/* 3826 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3828 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3830 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3832 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3834 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3836 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3838 */	NdrFcShort( 0xf10e ),	/* Offset= -3826 (12) */
/* 3840 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3842 */	NdrFcShort( 0xf10a ),	/* Offset= -3830 (12) */
/* 3844 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3846 */	NdrFcShort( 0xf106 ),	/* Offset= -3834 (12) */
/* 3848 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3850 */	NdrFcShort( 0xf102 ),	/* Offset= -3838 (12) */
/* 3852 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 3854 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3856 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3858 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3860 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3862 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3864 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3866 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3868 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3870 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3872 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3874 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3876 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3878 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3880 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3882 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3886 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3892 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3898 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 3902 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3906 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3908 */	0x0 ,
			0x0,		/* 0 */
/* 3910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3918 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3920 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (3818) */
/* 3922 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3924 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3926 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x6 ),	/* Offset= 6 (3936) */
/* 3932 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3934 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 3936 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3938 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3882) */
/* 3940 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3942 */	NdrFcShort( 0x88 ),	/* 136 */
/* 3944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3946 */	NdrFcShort( 0x1e ),	/* Offset= 30 (3976) */
/* 3948 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3950 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3952 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3954 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3956 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3958 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3960 */	0x0,		/* 0 */
			NdrFcShort( 0xf093 ),	/* Offset= -3949 (12) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3964 */	0x0,		/* 0 */
			NdrFcShort( 0xf08f ),	/* Offset= -3953 (12) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3968 */	0x0,		/* 0 */
			NdrFcShort( 0xf08b ),	/* Offset= -3957 (12) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3972 */	0x0,		/* 0 */
			NdrFcShort( 0xf087 ),	/* Offset= -3961 (12) */
			0x5b,		/* FC_END */
/* 3976 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3978 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3980 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3982 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3984 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3986 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3988 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3990 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3992 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3994 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3996 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3998 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4000 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4002 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4004 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4008 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4012 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4014 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4020 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 4024 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4028 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4030 */	0x0 ,
			0x0,		/* 0 */
/* 4032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4040 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4042 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (3940) */
/* 4044 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4046 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4048 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4052 */	NdrFcShort( 0x6 ),	/* Offset= 6 (4058) */
/* 4054 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4056 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4058 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4060 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (4004) */
/* 4062 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4064 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4068 */	NdrFcShort( 0xa ),	/* Offset= 10 (4078) */
/* 4070 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4072 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4074 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4076 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4078 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4080 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4082 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 4084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4086 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4090 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4092 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4098 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 4102 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4106 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4108 */	0x0 ,
			0x0,		/* 0 */
/* 4110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4118 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4120 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (4062) */
/* 4122 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4124 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4126 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4130 */	NdrFcShort( 0x6 ),	/* Offset= 6 (4136) */
/* 4132 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4134 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4136 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4138 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (4082) */
/* 4140 */
			0x11, 0x0,	/* FC_RP */
/* 4142 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4144) */
/* 4144 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4146 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 4148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4150 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4152 */	0x0 ,
			0x0,		/* 0 */
/* 4154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4162 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4164) */
/* 4164 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4166 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4168 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4172 */	NdrFcShort( 0x10 ),	/* Offset= 16 (4188) */
/* 4174 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4178 */	NdrFcShort( 0x2e ),	/* Offset= 46 (4224) */
/* 4180 */	NdrFcLong( 0x3 ),	/* 3 */
/* 4184 */	NdrFcShort( 0x36 ),	/* Offset= 54 (4238) */
/* 4186 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4185) */
/* 4188 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4190 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4194 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4202) */
/* 4196 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4198 */	0x0,		/* 0 */
			NdrFcShort( 0xf3ed ),	/* Offset= -3091 (1108) */
			0x5b,		/* FC_END */
/* 4202 */
			0x11, 0x0,	/* FC_RP */
/* 4204 */	NdrFcShort( 0xf036 ),	/* Offset= -4042 (162) */
/* 4206 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4208 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4220) */
/* 4214 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4216 */	0x0,		/* 0 */
			NdrFcShort( 0xf3eb ),	/* Offset= -3093 (1124) */
			0x5b,		/* FC_END */
/* 4220 */
			0x12, 0x0,	/* FC_UP */
/* 4222 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (4206) */
/* 4224 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4226 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4230 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4230) */
/* 4232 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4234 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (4206) */
/* 4236 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4238 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4240 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4244 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4252) */
/* 4246 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4248 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (4206) */
/* 4250 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4252 */
			0x12, 0x0,	/* FC_UP */
/* 4254 */	NdrFcShort( 0xf9f8 ),	/* Offset= -1544 (2710) */
/* 4256 */
			0x11, 0x0,	/* FC_RP */
/* 4258 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4260) */
/* 4260 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4262 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 4264 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4266 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4268 */	0x0 ,
			0x0,		/* 0 */
/* 4270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4280) */
/* 4280 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4282 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4284 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4288 */	NdrFcShort( 0x10 ),	/* Offset= 16 (4304) */
/* 4290 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4294 */	NdrFcShort( 0x5a ),	/* Offset= 90 (4384) */
/* 4296 */	NdrFcLong( 0x3 ),	/* 3 */
/* 4300 */	NdrFcShort( 0x1f2 ),	/* Offset= 498 (4798) */
/* 4302 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4301) */
/* 4304 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4306 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4310 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4310) */
/* 4312 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4314 */	NdrFcShort( 0xef32 ),	/* Offset= -4302 (12) */
/* 4316 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4318 */	NdrFcShort( 0xefa4 ),	/* Offset= -4188 (130) */
/* 4320 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4322 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4324 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 4326 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4328 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 4330 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4332 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4334 */	NdrFcShort( 0xef1e ),	/* Offset= -4322 (12) */
/* 4336 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4338 */	NdrFcShort( 0xef90 ),	/* Offset= -4208 (130) */
/* 4340 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4342 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 4344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4346 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4348 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4350 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4352 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4358 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 4362 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4366 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4368 */	0x0 ,
			0x0,		/* 0 */
/* 4370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4378 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4380 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (4328) */
/* 4382 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4384 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4386 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4390 */	NdrFcShort( 0xc ),	/* Offset= 12 (4402) */
/* 4392 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 4394 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4396 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4398 */	0x3e,		/* FC_STRUCTPAD2 */
			0x8,		/* FC_LONG */
/* 4400 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4402 */
			0x12, 0x0,	/* FC_UP */
/* 4404 */	NdrFcShort( 0xef6e ),	/* Offset= -4242 (162) */
/* 4406 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4408 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (4342) */
/* 4410 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4412 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4416 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4418 */	0x0 ,
			0x0,		/* 0 */
/* 4420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4430) */
/* 4430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4434 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4438 */	NdrFcShort( 0x12e ),	/* Offset= 302 (4740) */
/* 4440 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4439) */
/* 4442 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4444 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4448 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4450 */	0x0 ,
			0x0,		/* 0 */
/* 4452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4460 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4462) */
/* 4462 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4464 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4466 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4470 */	NdrFcShort( 0x4e ),	/* Offset= 78 (4548) */
/* 4472 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4476 */	NdrFcShort( 0x5c ),	/* Offset= 92 (4568) */
/* 4478 */	NdrFcLong( 0x3 ),	/* 3 */
/* 4482 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (4708) */
/* 4484 */	NdrFcLong( 0x4 ),	/* 4 */
/* 4488 */	NdrFcShort( 0xee ),	/* Offset= 238 (4726) */
/* 4490 */	NdrFcLong( 0x5 ),	/* 5 */
/* 4494 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (4726) */
/* 4496 */	NdrFcLong( 0x6 ),	/* 6 */
/* 4500 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (4726) */
/* 4502 */	NdrFcLong( 0x7 ),	/* 7 */
/* 4506 */	NdrFcShort( 0xdc ),	/* Offset= 220 (4726) */
/* 4508 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4507) */
/* 4510 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4512 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4516 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4516) */
/* 4518 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4520 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4522 */	0x3e,		/* FC_STRUCTPAD2 */
			0x8,		/* FC_LONG */
/* 4524 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4526 */	0x0,		/* 0 */
			NdrFcShort( 0xf221 ),	/* Offset= -3551 (976) */
			0x5b,		/* FC_END */
/* 4530 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4532 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4536 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4544) */
/* 4538 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4540 */	0x0,		/* 0 */
			NdrFcShort( 0xffe1 ),	/* Offset= -31 (4510) */
			0x5b,		/* FC_END */
/* 4544 */
			0x12, 0x0,	/* FC_UP */
/* 4546 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (4530) */
/* 4548 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4550 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4554 */	NdrFcShort( 0xa ),	/* Offset= 10 (4564) */
/* 4556 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 4558 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4560 */	0x0,		/* 0 */
			NdrFcShort( 0xffe1 ),	/* Offset= -31 (4530) */
			0x5b,		/* FC_END */
/* 4564 */
			0x12, 0x0,	/* FC_UP */
/* 4566 */	NdrFcShort( 0xeecc ),	/* Offset= -4404 (162) */
/* 4568 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4570 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4574 */	NdrFcShort( 0xa ),	/* Offset= 10 (4584) */
/* 4576 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4578 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4580 */	0x3e,		/* FC_STRUCTPAD2 */
			0x36,		/* FC_POINTER */
/* 4582 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4584 */
			0x12, 0x0,	/* FC_UP */
/* 4586 */	NdrFcShort( 0xeeb8 ),	/* Offset= -4424 (162) */
/* 4588 */
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 4590 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4592 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 4594 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 4596 */
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 4598 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4600 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 4602 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4604 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4606 */	0x0 ,
			0x0,		/* 0 */
/* 4608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4616 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 4618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4620 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4622 */	0x0 ,
			0x0,		/* 0 */
/* 4624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4632 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 4634 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4636 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4640 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4648) */
/* 4642 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 4644 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 4646 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4648 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4650 */	NdrFcShort( 0xffca ),	/* Offset= -54 (4596) */
/* 4652 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4654 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4658 */	NdrFcShort( 0x6 ),	/* Offset= 6 (4664) */
/* 4660 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 4662 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4664 */
			0x12, 0x0,	/* FC_UP */
/* 4666 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (4652) */
/* 4668 */
			0x12, 0x0,	/* FC_UP */
/* 4670 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (4634) */
/* 4672 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4674 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4678 */	NdrFcShort( 0x12 ),	/* Offset= 18 (4696) */
/* 4680 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4682 */	0x0,		/* 0 */
			NdrFcShort( 0xffa1 ),	/* Offset= -95 (4588) */
			0x6,		/* FC_SHORT */
/* 4686 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 4688 */	0x6,		/* FC_SHORT */
			0x40,		/* FC_STRUCTPAD4 */
/* 4690 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 4692 */	0x8,		/* FC_LONG */
			0x2,		/* FC_CHAR */
/* 4694 */	0x3f,		/* FC_STRUCTPAD3 */
			0x5b,		/* FC_END */
/* 4696 */
			0x12, 0x0,	/* FC_UP */
/* 4698 */	NdrFcShort( 0xee48 ),	/* Offset= -4536 (162) */
/* 4700 */
			0x12, 0x0,	/* FC_UP */
/* 4702 */	NdrFcShort( 0xffce ),	/* Offset= -50 (4652) */
/* 4704 */
			0x12, 0x0,	/* FC_UP */
/* 4706 */	NdrFcShort( 0xffde ),	/* Offset= -34 (4672) */
/* 4708 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4710 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4714 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4714) */
/* 4716 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4718 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4720 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4722 */	NdrFcShort( 0xffce ),	/* Offset= -50 (4672) */
/* 4724 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4726 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4728 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4732 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4732) */
/* 4734 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4736 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4738 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 4740 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4742 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4746 */	NdrFcShort( 0x6 ),	/* Offset= 6 (4752) */
/* 4748 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4750 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4752 */
			0x12, 0x0,	/* FC_UP */
/* 4754 */	NdrFcShort( 0xfec8 ),	/* Offset= -312 (4442) */
/* 4756 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 4758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4760 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 4762 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4764 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4766 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4772 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 4776 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4780 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4782 */	0x0 ,
			0x0,		/* 0 */
/* 4784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4792 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4794 */	NdrFcShort( 0xfe2e ),	/* Offset= -466 (4328) */
/* 4796 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4798 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4800 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4804 */	NdrFcShort( 0xa ),	/* Offset= 10 (4814) */
/* 4806 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 4808 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 4810 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4812 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4814 */
			0x12, 0x0,	/* FC_UP */
/* 4816 */	NdrFcShort( 0xedd2 ),	/* Offset= -4654 (162) */
/* 4818 */
			0x12, 0x0,	/* FC_UP */
/* 4820 */	NdrFcShort( 0xfe66 ),	/* Offset= -410 (4410) */
/* 4822 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4824 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (4756) */
/* 4826 */
			0x11, 0x0,	/* FC_RP */
/* 4828 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4830) */
/* 4830 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4832 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 4834 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4836 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4838 */	0x0 ,
			0x0,		/* 0 */
/* 4840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4848 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4850) */
/* 4850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4852 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4854 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4858 */	NdrFcShort( 0x4 ),	/* Offset= 4 (4862) */
/* 4860 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4859) */
/* 4862 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 4864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4866 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4868 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4870 */
			0x11, 0x0,	/* FC_RP */
/* 4872 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4874) */
/* 4874 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4876 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 4878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4880 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4882 */	0x0 ,
			0x0,		/* 0 */
/* 4884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4892 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4894) */
/* 4894 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4896 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4898 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4902 */	NdrFcShort( 0xa ),	/* Offset= 10 (4912) */
/* 4904 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4908 */	NdrFcShort( 0x18 ),	/* Offset= 24 (4932) */
/* 4910 */	NdrFcShort( 0xffff ),	/* Offset= -1 (4909) */
/* 4912 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4914 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4918 */	NdrFcShort( 0xa ),	/* Offset= 10 (4928) */
/* 4920 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4922 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4924 */	0x0,		/* 0 */
			NdrFcShort( 0xeccf ),	/* Offset= -4913 (12) */
			0x5b,		/* FC_END */
/* 4928 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4930 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4932 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4934 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4938 */	NdrFcShort( 0x10 ),	/* Offset= 16 (4954) */
/* 4940 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 4942 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4944 */	0x0,		/* 0 */
			NdrFcShort( 0xecbb ),	/* Offset= -4933 (12) */
			0x8,		/* FC_LONG */
/* 4948 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 4950 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 4952 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 4954 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4956 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4958 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4960 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4962 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 4964 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 4966 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 4968 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4970) */
/* 4970 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 4972 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 4974 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4976 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4978 */	0x0 ,
			0x0,		/* 0 */
/* 4980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4988 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4990) */
/* 4990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4992 */	NdrFcShort( 0xf ),	/* 15 */
/* 4994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4998 */	NdrFcShort( 0x58 ),	/* Offset= 88 (5086) */
/* 5000 */	NdrFcLong( 0x1 ),	/* 1 */
/* 5004 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (5204) */
/* 5006 */	NdrFcLong( 0x2 ),	/* 2 */
/* 5010 */	NdrFcShort( 0xea ),	/* Offset= 234 (5244) */
/* 5012 */	NdrFcLong( 0x3 ),	/* 3 */
/* 5016 */	NdrFcShort( 0x138 ),	/* Offset= 312 (5328) */
/* 5018 */	NdrFcLong( 0x4 ),	/* 4 */
/* 5022 */	NdrFcShort( 0x132 ),	/* Offset= 306 (5328) */
/* 5024 */	NdrFcLong( 0x5 ),	/* 5 */
/* 5028 */	NdrFcShort( 0x17e ),	/* Offset= 382 (5410) */
/* 5030 */	NdrFcLong( 0x6 ),	/* 6 */
/* 5034 */	NdrFcShort( 0x1de ),	/* Offset= 478 (5512) */
/* 5036 */	NdrFcLong( 0x7 ),	/* 7 */
/* 5040 */	NdrFcShort( 0x256 ),	/* Offset= 598 (5638) */
/* 5042 */	NdrFcLong( 0x8 ),	/* 8 */
/* 5046 */	NdrFcShort( 0x286 ),	/* Offset= 646 (5692) */
/* 5048 */	NdrFcLong( 0x9 ),	/* 9 */
/* 5052 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (5774) */
/* 5054 */	NdrFcLong( 0xa ),	/* 10 */
/* 5058 */	NdrFcShort( 0x326 ),	/* Offset= 806 (5864) */
/* 5060 */	NdrFcLong( 0xfffffffa ),	/* -6 */
/* 5064 */	NdrFcShort( 0x38e ),	/* Offset= 910 (5974) */
/* 5066 */	NdrFcLong( 0xfffffffb ),	/* -5 */
/* 5070 */	NdrFcShort( 0x3da ),	/* Offset= 986 (6056) */
/* 5072 */	NdrFcLong( 0xfffffffc ),	/* -4 */
/* 5076 */	NdrFcShort( 0x3d8 ),	/* Offset= 984 (6060) */
/* 5078 */	NdrFcLong( 0xfffffffe ),	/* -2 */
/* 5082 */	NdrFcShort( 0x4 ),	/* Offset= 4 (5086) */
/* 5084 */	NdrFcShort( 0xffff ),	/* Offset= -1 (5083) */
/* 5086 */
			0x12, 0x0,	/* FC_UP */
/* 5088 */	NdrFcShort( 0x68 ),	/* Offset= 104 (5192) */
/* 5090 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5092 */	NdrFcShort( 0x90 ),	/* 144 */
/* 5094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5096 */	NdrFcShort( 0x26 ),	/* Offset= 38 (5134) */
/* 5098 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 5100 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 5102 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5104 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5106 */	NdrFcShort( 0xec1a ),	/* Offset= -5094 (12) */
/* 5108 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5110 */	NdrFcShort( 0xec16 ),	/* Offset= -5098 (12) */
/* 5112 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5114 */	NdrFcShort( 0xec12 ),	/* Offset= -5102 (12) */
/* 5116 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5118 */	NdrFcShort( 0xec0e ),	/* Offset= -5106 (12) */
/* 5120 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 5122 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5124 */	NdrFcShort( 0xfefa ),	/* Offset= -262 (4862) */
/* 5126 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5128 */	NdrFcShort( 0xfef6 ),	/* Offset= -266 (4862) */
/* 5130 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5132 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5134 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5136 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5138 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5140 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5142 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5144 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5146 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5148 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5150 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5154 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5156 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5158 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5160 */	0x0 ,
			0x0,		/* 0 */
/* 5162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5170 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5174 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5176 */	0x0 ,
			0x0,		/* 0 */
/* 5178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5188 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (5090) */
/* 5190 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5192 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5196 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5150) */
/* 5198 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5198) */
/* 5200 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5202 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5204 */
			0x12, 0x0,	/* FC_UP */
/* 5206 */	NdrFcShort( 0x1c ),	/* Offset= 28 (5234) */
/* 5208 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 5210 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5212 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5214 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5216 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5218 */	0x0 ,
			0x0,		/* 0 */
/* 5220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5228 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5230 */	NdrFcShort( 0xed5c ),	/* Offset= -4772 (458) */
/* 5232 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5234 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 5236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5238 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (5208) */
/* 5240 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5242 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5244 */
			0x12, 0x0,	/* FC_UP */
/* 5246 */	NdrFcShort( 0x46 ),	/* Offset= 70 (5316) */
/* 5248 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5250 */	NdrFcShort( 0x38 ),	/* 56 */
/* 5252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5254 */	NdrFcShort( 0x10 ),	/* Offset= 16 (5270) */
/* 5256 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 5258 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5260 */	NdrFcShort( 0xfe72 ),	/* Offset= -398 (4862) */
/* 5262 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5264 */	NdrFcShort( 0xeb7c ),	/* Offset= -5252 (12) */
/* 5266 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 5268 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 5270 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5272 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5274 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5280 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5282 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5284 */	0x0 ,
			0x0,		/* 0 */
/* 5286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5294 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5298 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5300 */	0x0 ,
			0x0,		/* 0 */
/* 5302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5310 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5312 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (5248) */
/* 5314 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5316 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5320 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5274) */
/* 5322 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5322) */
/* 5324 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5326 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5328 */
			0x12, 0x0,	/* FC_UP */
/* 5330 */	NdrFcShort( 0x44 ),	/* Offset= 68 (5398) */
/* 5332 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 5334 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5338 */	NdrFcShort( 0xe ),	/* Offset= 14 (5352) */
/* 5340 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5342 */	0x0,		/* 0 */
			NdrFcShort( 0xeb2d ),	/* Offset= -5331 (12) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5346 */	0x0,		/* 0 */
			NdrFcShort( 0xfe1b ),	/* Offset= -485 (4862) */
			0x8,		/* FC_LONG */
/* 5350 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5352 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5354 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5356 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 5358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5360 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5362 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5364 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5366 */	0x0 ,
			0x0,		/* 0 */
/* 5368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5376 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5380 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5382 */	0x0 ,
			0x0,		/* 0 */
/* 5384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5392 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5394 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (5332) */
/* 5396 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5398 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 5400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5402 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5356) */
/* 5404 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5404) */
/* 5406 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5408 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5410 */
			0x12, 0x0,	/* FC_UP */
/* 5412 */	NdrFcShort( 0x54 ),	/* Offset= 84 (5496) */
/* 5414 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 5416 */	NdrFcShort( 0x50 ),	/* 80 */
/* 5418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5420 */	NdrFcShort( 0x16 ),	/* Offset= 22 (5442) */
/* 5422 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5424 */	NdrFcShort( 0xfdce ),	/* Offset= -562 (4862) */
/* 5426 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5428 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 5430 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 5432 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5434 */	0x0,		/* 0 */
			NdrFcShort( 0xead1 ),	/* Offset= -5423 (12) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5438 */	0x0,		/* 0 */
			NdrFcShort( 0xeacd ),	/* Offset= -5427 (12) */
			0x5b,		/* FC_END */
/* 5442 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5444 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5446 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5448 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5450 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5452 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5454 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 5456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5458 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5460 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5462 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5464 */	0x0 ,
			0x0,		/* 0 */
/* 5466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5474 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5478 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5480 */	0x0 ,
			0x0,		/* 0 */
/* 5482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5490 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5492 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (5414) */
/* 5494 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5496 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 5498 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5500 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5454) */
/* 5502 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5502) */
/* 5504 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5506 */	NdrFcShort( 0xfd7c ),	/* Offset= -644 (4862) */
/* 5508 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 5510 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5512 */
			0x12, 0x0,	/* FC_UP */
/* 5514 */	NdrFcShort( 0x70 ),	/* Offset= 112 (5626) */
/* 5516 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5518 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5520 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 5522 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5524 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5526 */	0x0 ,
			0x0,		/* 0 */
/* 5528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5536 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5538 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5540 */	NdrFcShort( 0x60 ),	/* 96 */
/* 5542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5544 */	NdrFcShort( 0x1c ),	/* Offset= 28 (5572) */
/* 5546 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 5548 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 5550 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5552 */	0x0,		/* 0 */
			NdrFcShort( 0xfd4d ),	/* Offset= -691 (4862) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5556 */	0x0,		/* 0 */
			NdrFcShort( 0xfd49 ),	/* Offset= -695 (4862) */
			0x8,		/* FC_LONG */
/* 5560 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5562 */	NdrFcShort( 0xfd44 ),	/* Offset= -700 (4862) */
/* 5564 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5566 */	NdrFcShort( 0xea4e ),	/* Offset= -5554 (12) */
/* 5568 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 5570 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 5572 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5574 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5576 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5578 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5580 */
			0x14, 0x20,	/* FC_FP [maybenull_sizeis] */
/* 5582 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (5516) */
/* 5584 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5588 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5590 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5592 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5594 */	0x0 ,
			0x0,		/* 0 */
/* 5596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5604 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5608 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5610 */	0x0 ,
			0x0,		/* 0 */
/* 5612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5620 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5622 */	NdrFcShort( 0xffac ),	/* Offset= -84 (5538) */
/* 5624 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5626 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5630 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5584) */
/* 5632 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5632) */
/* 5634 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5636 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5638 */
			0x12, 0x0,	/* FC_UP */
/* 5640 */	NdrFcShort( 0x2a ),	/* Offset= 42 (5682) */
/* 5642 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 5644 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5646 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5648 */	NdrFcShort( 0xe9fc ),	/* Offset= -5636 (12) */
/* 5650 */	0xb,		/* FC_HYPER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5652 */	0x0,		/* 0 */
			NdrFcShort( 0xfce9 ),	/* Offset= -791 (4862) */
			0x5b,		/* FC_END */
/* 5656 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 5658 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5660 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5662 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5664 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5666 */	0x0 ,
			0x0,		/* 0 */
/* 5668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5676 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5678 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (5642) */
/* 5680 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5682 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 5684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5686 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (5656) */
/* 5688 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5690 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5692 */
			0x12, 0x0,	/* FC_UP */
/* 5694 */	NdrFcShort( 0x44 ),	/* Offset= 68 (5762) */
/* 5696 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5698 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5702 */	NdrFcShort( 0xe ),	/* Offset= 14 (5716) */
/* 5704 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5706 */	NdrFcShort( 0xe9c2 ),	/* Offset= -5694 (12) */
/* 5708 */	0xb,		/* FC_HYPER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5710 */	0x0,		/* 0 */
			NdrFcShort( 0xfcaf ),	/* Offset= -849 (4862) */
			0x36,		/* FC_POINTER */
/* 5714 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5716 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5718 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5720 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5724 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5726 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5728 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5730 */	0x0 ,
			0x0,		/* 0 */
/* 5732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5740 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5744 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5746 */	0x0 ,
			0x0,		/* 0 */
/* 5748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5756 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5758 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (5696) */
/* 5760 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5762 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5766 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5720) */
/* 5768 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5768) */
/* 5770 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5772 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5774 */
			0x12, 0x0,	/* FC_UP */
/* 5776 */	NdrFcShort( 0x4c ),	/* Offset= 76 (5852) */
/* 5778 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5780 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5784 */	NdrFcShort( 0x12 ),	/* Offset= 18 (5802) */
/* 5786 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 5788 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5790 */	NdrFcShort( 0xfc60 ),	/* Offset= -928 (4862) */
/* 5792 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5794 */	NdrFcShort( 0xe96a ),	/* Offset= -5782 (12) */
/* 5796 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 5798 */	0xb,		/* FC_HYPER */
			0x36,		/* FC_POINTER */
/* 5800 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5802 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5804 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5806 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5808 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5810 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5814 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5816 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5818 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5820 */	0x0 ,
			0x0,		/* 0 */
/* 5822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5830 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5834 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5836 */	0x0 ,
			0x0,		/* 0 */
/* 5838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5846 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5848 */	NdrFcShort( 0xffba ),	/* Offset= -70 (5778) */
/* 5850 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5852 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5856 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5810) */
/* 5858 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5858) */
/* 5860 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5862 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5864 */
			0x12, 0x0,	/* FC_UP */
/* 5866 */	NdrFcShort( 0x60 ),	/* Offset= 96 (5962) */
/* 5868 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5870 */	NdrFcShort( 0x68 ),	/* 104 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5874 */	NdrFcShort( 0x1e ),	/* Offset= 30 (5904) */
/* 5876 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 5878 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 5880 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5882 */	0x0,		/* 0 */
			NdrFcShort( 0xfc03 ),	/* Offset= -1021 (4862) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5886 */	0x0,		/* 0 */
			NdrFcShort( 0xfbff ),	/* Offset= -1025 (4862) */
			0x8,		/* FC_LONG */
/* 5890 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5892 */	NdrFcShort( 0xfbfa ),	/* Offset= -1030 (4862) */
/* 5894 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5896 */	NdrFcShort( 0xe904 ),	/* Offset= -5884 (12) */
/* 5898 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 5900 */	0xb,		/* FC_HYPER */
			0x36,		/* FC_POINTER */
/* 5902 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5904 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5906 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5908 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5910 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5912 */
			0x14, 0x20,	/* FC_FP [maybenull_sizeis] */
/* 5914 */	NdrFcShort( 0xfe72 ),	/* Offset= -398 (5516) */
/* 5916 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 5918 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 5920 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 5922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5924 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 5926 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 5928 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5930 */	0x0 ,
			0x0,		/* 0 */
/* 5932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5936 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5940 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 5944 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5946 */	0x0 ,
			0x0,		/* 0 */
/* 5948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5956 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5958 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (5868) */
/* 5960 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5962 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5966 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (5920) */
/* 5968 */	NdrFcShort( 0x0 ),	/* Offset= 0 (5968) */
/* 5970 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5974 */
			0x12, 0x0,	/* FC_UP */
/* 5976 */	NdrFcShort( 0x44 ),	/* Offset= 68 (6044) */
/* 5978 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 5980 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5984 */	NdrFcShort( 0xe ),	/* Offset= 14 (5998) */
/* 5986 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 5988 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5990 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5992 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 5994 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 5996 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5998 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6000 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6002 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 6004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6006 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 6008 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 6010 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6012 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6018 */	NdrFcLong( 0x100 ),	/* 256 */
/* 6022 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6026 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6028 */	0x0 ,
			0x0,		/* 0 */
/* 6030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6038 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6040 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (5978) */
/* 6042 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6044 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 6046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6048 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (6002) */
/* 6050 */	NdrFcShort( 0x0 ),	/* Offset= 0 (6050) */
/* 6052 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 6054 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6056 */
			0x12, 0x0,	/* FC_UP */
/* 6058 */	NdrFcShort( 0xea44 ),	/* Offset= -5564 (494) */
/* 6060 */
			0x12, 0x0,	/* FC_UP */
/* 6062 */	NdrFcShort( 0x2c ),	/* Offset= 44 (6106) */
/* 6064 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 6066 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6068 */	0xb,		/* FC_HYPER */
			0x8,		/* FC_LONG */
/* 6070 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 6072 */	0x0,		/* 0 */
			NdrFcShort( 0xe853 ),	/* Offset= -6061 (12) */
			0xb,		/* FC_HYPER */
/* 6076 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 6078 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6080 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 6082 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6084 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 6086 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 6088 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6090 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6096 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 6100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6102 */	NdrFcShort( 0xffda ),	/* Offset= -38 (6064) */
/* 6104 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6106 */
			0x17,		/* FC_CSTRUCT */
			0x7,		/* 7 */
/* 6108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6110 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (6080) */
/* 6112 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 6114 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6116 */
			0x11, 0x0,	/* FC_RP */
/* 6118 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6120) */
/* 6120 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6122 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6124 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6126 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6128 */	0x0 ,
			0x0,		/* 0 */
/* 6130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6138 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6140) */
/* 6140 */	NdrFcShort( 0x60 ),	/* 96 */
/* 6142 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6144 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6148 */	NdrFcShort( 0x46 ),	/* Offset= 70 (6218) */
/* 6150 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6149) */
/* 6152 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 6154 */	NdrFcShort( 0x2 ),	/* 2 */
/* 6156 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6158 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6160 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6162 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6168 */	NdrFcLong( 0x100 ),	/* 256 */
/* 6172 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 6174 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 6176 */	NdrFcShort( 0x2 ),	/* 2 */
/* 6178 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6180 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6182 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6184 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6190 */	NdrFcLong( 0x100 ),	/* 256 */
/* 6194 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 6196 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 6198 */	NdrFcShort( 0x2 ),	/* 2 */
/* 6200 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6202 */	NdrFcShort( 0x40 ),	/* 64 */
/* 6204 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6206 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6212 */	NdrFcLong( 0x100 ),	/* 256 */
/* 6216 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 6218 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6220 */	NdrFcShort( 0x60 ),	/* 96 */
/* 6222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6224 */	NdrFcShort( 0x14 ),	/* Offset= 20 (6244) */
/* 6226 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6228 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 6230 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 6232 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 6234 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6236 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 6238 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 6240 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 6242 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6244 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6246 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6248 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6250 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6252 */
			0x14, 0x8,	/* FC_FP [simple_pointer] */
/* 6254 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6256 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6258 */	NdrFcShort( 0xff96 ),	/* Offset= -106 (6152) */
/* 6260 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6262 */	NdrFcShort( 0xffa8 ),	/* Offset= -88 (6174) */
/* 6264 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6266 */	NdrFcShort( 0xffba ),	/* Offset= -70 (6196) */
/* 6268 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6270 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6272 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6274 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6276 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 6278 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6280) */
/* 6280 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6282 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 6284 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6286 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6288 */	0x0 ,
			0x0,		/* 0 */
/* 6290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6298 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6300) */
/* 6300 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6302 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6304 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6308 */	NdrFcShort( 0xf4c4 ),	/* Offset= -2876 (3432) */
/* 6310 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6309) */
/* 6312 */
			0x11, 0x0,	/* FC_RP */
/* 6314 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6316) */
/* 6316 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6318 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6322 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6324 */	0x0 ,
			0x0,		/* 0 */
/* 6326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6334 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6336) */
/* 6336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6338 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6340 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6344 */	NdrFcShort( 0x2e ),	/* Offset= 46 (6390) */
/* 6346 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6345) */
/* 6348 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 6350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6352 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6356 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6358 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6360 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6364 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 6368 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6372 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6374 */	0x0 ,
			0x0,		/* 0 */
/* 6376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6384 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6386 */	NdrFcShort( 0xf05e ),	/* Offset= -4002 (2384) */
/* 6388 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6390 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6396 */	NdrFcShort( 0x6 ),	/* Offset= 6 (6402) */
/* 6398 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6400 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 6402 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6404 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (6348) */
/* 6406 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 6408 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6410) */
/* 6410 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6412 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 6414 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6416 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6418 */	0x0 ,
			0x0,		/* 0 */
/* 6420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6428 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6430) */
/* 6430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6434 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6438 */	NdrFcShort( 0x2e ),	/* Offset= 46 (6484) */
/* 6440 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6439) */
/* 6442 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 6444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6446 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6450 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6452 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6458 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 6462 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6466 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6468 */	0x0 ,
			0x0,		/* 0 */
/* 6470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6478 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6480 */	NdrFcShort( 0xf0a8 ),	/* Offset= -3928 (2552) */
/* 6482 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6484 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6486 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6490 */	NdrFcShort( 0x6 ),	/* Offset= 6 (6496) */
/* 6492 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6494 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 6496 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6498 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (6442) */
/* 6500 */
			0x11, 0x0,	/* FC_RP */
/* 6502 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6504) */
/* 6504 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6506 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6510 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6512 */	0x0 ,
			0x0,		/* 0 */
/* 6514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6522 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6524) */
/* 6524 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6526 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6528 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6532 */	NdrFcShort( 0x4 ),	/* Offset= 4 (6536) */
/* 6534 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6533) */
/* 6536 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6538 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6542 */	NdrFcShort( 0xa ),	/* Offset= 10 (6552) */
/* 6544 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 6546 */	0x0,		/* 0 */
			NdrFcShort( 0xe679 ),	/* Offset= -6535 (12) */
			0x8,		/* FC_LONG */
/* 6550 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 6552 */
			0x11, 0x0,	/* FC_RP */
/* 6554 */	NdrFcShort( 0xe708 ),	/* Offset= -6392 (162) */
/* 6556 */
			0x11, 0x0,	/* FC_RP */
/* 6558 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6560) */
/* 6560 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6562 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6566 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6568 */	0x0 ,
			0x0,		/* 0 */
/* 6570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6578 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6580) */
/* 6580 */	NdrFcShort( 0x38 ),	/* 56 */
/* 6582 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6584 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6588 */	NdrFcShort( 0xa ),	/* Offset= 10 (6598) */
/* 6590 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6589) */
/* 6592 */
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 6594 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6596 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 6598 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6600 */	NdrFcShort( 0x38 ),	/* 56 */
/* 6602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6604 */	NdrFcShort( 0x10 ),	/* Offset= 16 (6620) */
/* 6606 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6608 */	NdrFcShort( 0xe63c ),	/* Offset= -6596 (12) */
/* 6610 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6612 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 6614 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6616 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (6592) */
/* 6618 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6620 */
			0x12, 0x0,	/* FC_UP */
/* 6622 */	NdrFcShort( 0xe6c4 ),	/* Offset= -6460 (162) */
/* 6624 */
			0x12, 0x0,	/* FC_UP */
/* 6626 */	NdrFcShort( 0xe80c ),	/* Offset= -6132 (494) */
/* 6628 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 6630 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6632) */
/* 6632 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6634 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 6636 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6638 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6640 */	0x0 ,
			0x0,		/* 0 */
/* 6642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6650 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6652) */
/* 6652 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6654 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6656 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6660 */	NdrFcShort( 0x2e ),	/* Offset= 46 (6706) */
/* 6662 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6661) */
/* 6664 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 6666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6668 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6670 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6672 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6674 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6680 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 6684 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6688 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6690 */	0x0 ,
			0x0,		/* 0 */
/* 6692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6700 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6702 */	NdrFcShort( 0xe5de ),	/* Offset= -6690 (12) */
/* 6704 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6706 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6708 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6712 */	NdrFcShort( 0x6 ),	/* Offset= 6 (6718) */
/* 6714 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 6716 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 6718 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6720 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (6664) */
/* 6722 */
			0x11, 0x0,	/* FC_RP */
/* 6724 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6726) */
/* 6726 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6728 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6732 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6734 */	0x0 ,
			0x0,		/* 0 */
/* 6736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6744 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6746) */
/* 6746 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6748 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6750 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6754 */	NdrFcShort( 0x2e ),	/* Offset= 46 (6800) */
/* 6756 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6755) */
/* 6758 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 6760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6762 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6766 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6768 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6770 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6774 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 6778 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6782 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6784 */	0x0 ,
			0x0,		/* 0 */
/* 6786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6794 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6796 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6798 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6800 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6802 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6806 */	NdrFcShort( 0xa ),	/* Offset= 10 (6816) */
/* 6808 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 6810 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 6812 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6814 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6816 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 6818 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 6820 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6822 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (6758) */
/* 6824 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 6826 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6828) */
/* 6828 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6830 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 6832 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6834 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6836 */	0x0 ,
			0x0,		/* 0 */
/* 6838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6846 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6848) */
/* 6848 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6850 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6852 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6856 */	NdrFcShort( 0x2e ),	/* Offset= 46 (6902) */
/* 6858 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6857) */
/* 6860 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 6862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6864 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 6866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6868 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6870 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6876 */	NdrFcLong( 0x2710 ),	/* 10000 */
/* 6880 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 6884 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 6886 */	0x0 ,
			0x0,		/* 0 */
/* 6888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6896 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 6898 */	NdrFcShort( 0xf80c ),	/* Offset= -2036 (4862) */
/* 6900 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6902 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 6904 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6908 */	NdrFcShort( 0x8 ),	/* Offset= 8 (6916) */
/* 6910 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 6912 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 6914 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 6916 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6918 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (6860) */
/* 6920 */
			0x11, 0x0,	/* FC_RP */
/* 6922 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6924) */
/* 6924 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6926 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 6928 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6930 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6932 */	0x0 ,
			0x0,		/* 0 */
/* 6934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6942 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6944) */
/* 6944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6946 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6948 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6952 */	NdrFcShort( 0xf240 ),	/* Offset= -3520 (3432) */
/* 6954 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6953) */
/* 6956 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 6958 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6960) */
/* 6960 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6962 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 6964 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6966 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6968 */	0x0 ,
			0x0,		/* 0 */
/* 6970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6978 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6980) */
/* 6980 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6982 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6984 */	NdrFcLong( 0x1 ),	/* 1 */
/* 6988 */	NdrFcShort( 0xf21c ),	/* Offset= -3556 (3432) */
/* 6990 */	NdrFcShort( 0xffff ),	/* Offset= -1 (6989) */
/* 6992 */
			0x11, 0x0,	/* FC_RP */
/* 6994 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6996) */
/* 6996 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 6998 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7002 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7004 */	0x0 ,
			0x0,		/* 0 */
/* 7006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7014 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7016) */
/* 7016 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7020 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7024 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7028) */
/* 7026 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7025) */
/* 7028 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7030 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7034 */	NdrFcShort( 0xa ),	/* Offset= 10 (7044) */
/* 7036 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 7038 */	0x0,		/* 0 */
			NdrFcShort( 0xe48d ),	/* Offset= -7027 (12) */
			0x40,		/* FC_STRUCTPAD4 */
/* 7042 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7044 */
			0x11, 0x0,	/* FC_RP */
/* 7046 */	NdrFcShort( 0xe51c ),	/* Offset= -6884 (162) */
/* 7048 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7050 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7052) */
/* 7052 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7054 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7056 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7058 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7060 */	0x0 ,
			0x0,		/* 0 */
/* 7062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7070 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7072) */
/* 7072 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7074 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7076 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7080 */	NdrFcShort( 0xf1c0 ),	/* Offset= -3648 (3432) */
/* 7082 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7081) */
/* 7084 */
			0x11, 0x0,	/* FC_RP */
/* 7086 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7088) */
/* 7088 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7090 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7092 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7094 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7096 */	0x0 ,
			0x0,		/* 0 */
/* 7098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7108) */
/* 7108 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7110 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7112 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7116 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7120) */
/* 7118 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7117) */
/* 7120 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7122 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7126 */	NdrFcShort( 0xa ),	/* Offset= 10 (7136) */
/* 7128 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 7130 */	0x0,		/* 0 */
			NdrFcShort( 0xe431 ),	/* Offset= -7119 (12) */
			0x40,		/* FC_STRUCTPAD4 */
/* 7134 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7136 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7138 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7140 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7142 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7144) */
/* 7144 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7146 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7148 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7150 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7152 */	0x0 ,
			0x0,		/* 0 */
/* 7154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7162 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7164) */
/* 7164 */	NdrFcShort( 0xc ),	/* 12 */
/* 7166 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7168 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7172 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7176) */
/* 7174 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7173) */
/* 7176 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 7178 */	NdrFcShort( 0xc ),	/* 12 */
/* 7180 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 7182 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 7184 */
			0x11, 0x0,	/* FC_RP */
/* 7186 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7188) */
/* 7188 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7190 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7194 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7196 */	0x0 ,
			0x0,		/* 0 */
/* 7198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7206 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7208) */
/* 7208 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7212 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7216 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7220) */
/* 7218 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7217) */
/* 7220 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7222 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7226 */	NdrFcShort( 0x6 ),	/* Offset= 6 (7232) */
/* 7228 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 7230 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 7232 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7234 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7236 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7238 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7240 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7244) */
/* 7244 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7246 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7248 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7250 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7252 */	0x0 ,
			0x0,		/* 0 */
/* 7254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7262 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7264) */
/* 7264 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7266 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7268 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7272 */	NdrFcShort( 0x1a ),	/* Offset= 26 (7298) */
/* 7274 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7273) */
/* 7276 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 7278 */	NdrFcShort( 0x2 ),	/* 2 */
/* 7280 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7282 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7284 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7286 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7292 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 7296 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 7298 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7300 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7304 */	NdrFcShort( 0x8 ),	/* Offset= 8 (7312) */
/* 7306 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 7308 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 7310 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7312 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7314 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7316 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7318 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7320 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7322 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (7276) */
/* 7324 */
			0x11, 0x0,	/* FC_RP */
/* 7326 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7328) */
/* 7328 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7330 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7334 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7336 */	0x0 ,
			0x0,		/* 0 */
/* 7338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7346 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7348) */
/* 7348 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7350 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7352 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7356 */	NdrFcShort( 0x1a ),	/* Offset= 26 (7382) */
/* 7358 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7357) */
/* 7360 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7362 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7364 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7368 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7370 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7376 */	NdrFcLong( 0xffff ),	/* 65535 */
/* 7380 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7382 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7384 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7388 */	NdrFcShort( 0x8 ),	/* Offset= 8 (7396) */
/* 7390 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 7392 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 7394 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 7396 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7398 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7400 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7402 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (7360) */
/* 7404 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7406 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7408) */
/* 7408 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7410 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7412 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7414 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7416 */	0x0 ,
			0x0,		/* 0 */
/* 7418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7426 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7428) */
/* 7428 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7430 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7432 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7436 */	NdrFcShort( 0xf05c ),	/* Offset= -4004 (3432) */
/* 7438 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7437) */
/* 7440 */
			0x11, 0x0,	/* FC_RP */
/* 7442 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7444) */
/* 7444 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7446 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7450 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7452 */	0x0 ,
			0x0,		/* 0 */
/* 7454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7462 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7464) */
/* 7464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7466 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7468 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7472 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7476) */
/* 7474 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7473) */
/* 7476 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7482 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7486) */
/* 7484 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7486 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7488 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7490 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7492 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7494) */
/* 7494 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7496 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7498 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7500 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7502 */	0x0 ,
			0x0,		/* 0 */
/* 7504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7512 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7514) */
/* 7514 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7516 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7518 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7522 */	NdrFcShort( 0x1a ),	/* Offset= 26 (7548) */
/* 7524 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7523) */
/* 7526 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7528 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7530 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7532 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7534 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7536 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7542 */	NdrFcLong( 0xffff ),	/* 65535 */
/* 7546 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7548 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7550 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7554 */	NdrFcShort( 0x6 ),	/* Offset= 6 (7560) */
/* 7556 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 7558 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7560 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7562 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (7526) */
/* 7564 */
			0x11, 0x0,	/* FC_RP */
/* 7566 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7568) */
/* 7568 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7570 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7574 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7576 */	0x0 ,
			0x0,		/* 0 */
/* 7578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7586 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7588) */
/* 7588 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7592 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7596 */	NdrFcShort( 0xefbc ),	/* Offset= -4164 (3432) */
/* 7598 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7597) */
/* 7600 */
			0x11, 0x0,	/* FC_RP */
/* 7602 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7604) */
/* 7604 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7606 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7608 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7610 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7612 */	0x0 ,
			0x0,		/* 0 */
/* 7614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7622 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7624) */
/* 7624 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7626 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7628 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7632 */	NdrFcShort( 0x46 ),	/* Offset= 70 (7702) */
/* 7634 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7633) */
/* 7636 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7638 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7640 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7642 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7644 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7646 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7652 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 7656 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7658 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7660 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7662 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7664 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7666 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7668 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7674 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 7678 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7680 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7682 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7684 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7686 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7688 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7690 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7696 */	NdrFcLong( 0xa00000 ),	/* 10485760 */
/* 7700 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7702 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7704 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7708 */	NdrFcShort( 0x10 ),	/* Offset= 16 (7724) */
/* 7710 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 7712 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 7714 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 7716 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 7718 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 7720 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 7722 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 7724 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7726 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 7728 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7730 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (7636) */
/* 7732 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7734 */	NdrFcShort( 0xffb4 ),	/* Offset= -76 (7658) */
/* 7736 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7738 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (7680) */
/* 7740 */
			0x11, 0x0,	/* FC_RP */
/* 7742 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7744) */
/* 7744 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7746 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 7748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7750 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7752 */	0x0 ,
			0x0,		/* 0 */
/* 7754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7762 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7764) */
/* 7764 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7766 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7768 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7772 */	NdrFcShort( 0x1a ),	/* Offset= 26 (7798) */
/* 7774 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7773) */
/* 7776 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 7778 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7780 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 7782 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7784 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 7786 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 7788 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7792 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 7796 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 7798 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7800 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7804 */	NdrFcShort( 0x6 ),	/* Offset= 6 (7810) */
/* 7806 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 7808 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7810 */
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 7812 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (7776) */
/* 7814 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 7816 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7818) */
/* 7818 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 7820 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 7822 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7824 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 7826 */	0x0 ,
			0x0,		/* 0 */
/* 7828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7836 */	NdrFcShort( 0x2 ),	/* Offset= 2 (7838) */
/* 7838 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7840 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7842 */	NdrFcLong( 0x1 ),	/* 1 */
/* 7846 */	NdrFcShort( 0x4 ),	/* Offset= 4 (7850) */
/* 7848 */	NdrFcShort( 0xffff ),	/* Offset= -1 (7847) */
/* 7850 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 7852 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7856 */	NdrFcShort( 0x6 ),	/* Offset= 6 (7862) */
/* 7858 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 7860 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 7862 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 7864 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };
