/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** cmd_client_manager
*/

#include <string.h>
#include <stddef.h>
#include "libstr.h"
#include "cmd_client_manager.h"

static const char *broadcast_cmds[] = {
    "LOGIN",
    "LOGOUT",
    "MESSAGE",
    "SUBSCRIBED",
    "CHANNEL",
    "TEAMS",
    "THREAD",
    "REPLY",
    NULL
};

static bool is_broadcast_cmd(char *data)
{
    if (data == NULL || strstr(data, BROADCAST_CMD) != data) {
        return false;
    }
    return true;
}

static char *get_broadcast_cmd(char *data)
{
    char *tmp = NULL;
    char *type = NULL;

    tmp = my_split(data, SP, RIGHT);
    type = my_split(tmp, SP, LEFT);
    free(tmp);
    return type;
}

static int handle_broadcast_cmd(char *cmd)
{
    static int (*broadcast_funcs[])(char *cmd) = {
        BROADCAST_FUNCS,
        NULL
    };
    int result = EXIT_SUCCESS;

    for (int i = 0; broadcast_cmds[i] != NULL; i++) {
        if (strcmp(cmd, broadcast_cmds[i]) == 0) {
            result = broadcast_funcs[i](cmd);
            free(cmd);
            return result;
        }
    }
    return EXIT_FAILURE;
}

int manage_cmd_client(char *data)
{
    char *cmd = NULL;

    if (!is_broadcast_cmd(data)) {
        return EXIT_FAILURE;
    }
    cmd = get_broadcast_cmd(data);
    return handle_broadcast_cmd(cmd);
}
