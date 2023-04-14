/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** logic_input
*/

#include <string.h>
#include "protocol_logic.h"

static const cmd_t CMD_TAB[] = {
    {LOGIN ,"/login", 1, NULL},
    {LOGOUT, "/logout", 0, NULL},
    {USERS, "/users", 0, NULL},
    {USER ,"/user", 1, NULL},
    {SEND, "/send", 2, NULL},
    {MESSAGES, "/messages", 1, NULL},
    {SUBSCRIBE, "/subscribe", 1, NULL},
    {SUBSCRIBED, "/subscribed", 1, NULL},
    {UNSUBSCRIBE, "/unsubscribe", 1, NULL},
    {USE, "/use", 3, NULL},
    {CREATE, "/create", 0, NULL},
    {LIST, "/list", 0, NULL},
    {INFO, "/info", 0, NULL},
    {HELP, "/help", 0, NULL},
    {UNKNOWN, NULL, 0, NULL}
};

static const cmd_code_t CMD_CODE_TAB[] = {
    {LOGIN, "204"},
    {LOGOUT, "204"},
    {USERS, "200"},
    {USER, "200"},
    {SEND, "204"},
    {MESSAGES, "200"},
    {SUBSCRIBE, "204"},
    {SUBSCRIBED, "200"},
    {UNSUBSCRIBE, "200"},
    {USE, "200"},
    {CREATE, "201"},
    {LIST, "200"},
    {INFO, "200"},
    {HELP, "200"},
    {UNKNOWN, NULL}
};

char *get_cmd(char *input, int *nb_args)
{
    int i = 0;
    char *cmd_token = NULL;

    cmd_token = strtok(input, SEPARATORS);
    if (!cmd_token)
        return NULL;
    for (i = 0; CMD_TAB[i].cmd; i++) {
        if (strcasecmp(cmd_token, CMD_TAB[i].cmd) == 0) {
            *nb_args = CMD_TAB[i].nb_args;
            return strdup(cmd_token);
        }
    }
    return NULL;
}

void apply_logic_cmd(client_t *client, char *cmd, char **args)
{
    int i = 0;

    for (i = 0; CMD_TAB[i].cmd; i++) {
        if (strcasecmp(cmd, CMD_TAB[i].cmd) == 0 && CMD_TAB[i].logic) {
                CMD_TAB[i].logic(client, args);
                return;
        }
    }
}