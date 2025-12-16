# DCSync BOF

A Beacon Object File (BOF) implementation of the DCSync attack for extracting credential material from Active Directory domain controllers.

## Overview

This project was created for use with the Adaptix C2, and has a mapping file which registers commands under the `dcsync` prefix. To see usage for any command, run `help dcsync {command}`. That being said, any C2 with any agent capable of running bofs and passing arguments to them should be capable of running these.

### Features

- Single User Targeting - Extract credentials for a specific domain user
- Bulk Extraction - Dump all users from a domain or organizational unit
- Flexible LDAP Options - Support for custom DCs, OUs, and LDAPS connections

### Requirements
- Adaptix C2 Framework
- Windows x64 target (BOFs compiled for x64 architecture)
- Authenticated domain context (commands execute as current user)
- MinGW-w64 cross-compiler (for building from source)

## Installation

Clone the repository and compile the BOF:

```sh
git clone https://github.com/p0142/DCSync-Bof
cd DCSync-Bof
make
```

Compiled object files will be placed in the `_bin/` directory.

Next:
1. Navigate to the AxScript tab -> Script Manager
2. Right-click -> Load New -> Select `dcsync.axs`
3. The client automatically registers all commands under the `dcsync` namespace
4. Run `help dcsync <command>` for usage information

## Usage

### Command Reference

| Command | Description | Usage |
|---------|-------------|-------|
| `single` | Extract credentials for a specific user | `dcsync single <target> [-ou <path>] [-dc <fqdn>] [--ldaps]` |
| `all` | Extract credentials for all domain users | `dcsync all [-ou <path>] [-dc <fqdn>] [--ldaps]` |

### Examples

Extract credentials for a single user:
```sh
dcsync single jane.doe
```

Search for target user in a specific OU using LDAPS:
```sh
dcsync single john.smith -ou "OU=Admins,DC=corp,DC=local" --ldaps
```

Dump all users from the domain:
```sh
dcsync all
```

Target a specific domain controller:
```sh
dcsync all -dc dc01.corp.local
```

## Project Structure

```
DCSync-Bof/
├── dcsync.axs             # Adaptix C2 command registration script
├── Makefile               # Build configuration
├── _bin/                  # Compiled BOF object files (x64)
├── _include/              # Shared header files
│   ├── beacon.h           # BOF API definitions
│   ├── dcsync.h           # DCSync data structures
│   └── ldap_common.h      # LDAP utility declarations
├── drsuapi/               # Directory Replication Service API
│   ├── ms-drsr.h          # DRSUAPI headers (modified from Microsoft specs)
│   └── ms-drsr-custom.c   # Optimized RPC stub implementation
├── src/                   # Main BOF implementations
│   ├── dcsync-single.c    # Single user credential extraction
│   └── dcsync-all.c       # Bulk user credential extraction
└── util/                  # Helper utilities
    ├── ldap_common.c      # LDAP connection and query functions
    ├── ldap_syncall.c     # LDAP queries for bulk operations
    └── rpc-adapter.c      # RPC adapter layer
```

## Credits

This project builds upon research and code from:
- [DCSyncer](https://github.com/notsoshant/DCSyncer)
- [DCsyncer Write-up](https://www.notsoshant.io/tools/dcsyncer/)
- [Mimikatz](https://github.com/gentilkiwi/mimikatz)

## Authors Note

Mimikatz and similar programs parse supplemental credentials for offsets, then map to a struct to extract AES keys. This project identifies the salt then uses heuristic detection to locate and extract the AES keys. There will always be edge cases where this approach won't work, however I have yet to encounter a case like that in testing. I have also run into situations where accounts didn't actually have any supplemental credentials, so if you do encounter such an edge case I ask that you test with a different tool, such as impacket's secretsdump, before creating an issue. At the very least it should always return the nthash of the target user.

## Disclaimer

For Authorized Use Only - Unauthorized access to computer systems is illegal. This tool should only be used in environments where you have explicit permission to conduct security testing.
