#ifndef BC_GAME_H
#define BC_GAME_H

#include "Account.h"
#include "Betacraft.h"
#include "Instance.h"
#include "Mod.h"
#include "Version.h"

#include <limits.h>

extern bc_progress bc_game_run_progress;

struct bc_game_data {
    bc_instance *instance;
    bc_account *account;
    bc_version *version;
    bc_mod_version_array *mods;
    char server_ip[128];
    char server_port[16];
    char natives_folder[PATH_MAX];
} typedef bc_game_data;

char *fill_properties(const char *input, bc_game_data *data);
void bc_game_run(bc_game_data *data);

#endif
