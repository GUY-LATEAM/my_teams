/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** logic_input
*/

#include <string.h>
#include "libstr.h"
#include "protocol_logic.h"

static void attribute_cmd(client_t *client, enum cmd_e cmd,
__attribute__((unused)) char **args);

static const cmd_t CMD_TAB[] = {
    {LOGIN ,"/login", 1, 1, &attribute_cmd},
    {LOGOUT, "/logout", 0, 0, attribute_cmd},
    {USERS, "/users", 0, 0, attribute_cmd},
    {USER ,"/user", 1, 1, attribute_cmd},
    {SEND, "/send", 2, 2, attribute_cmd},
    {MESSAGES, "/messages", 1, 1, attribute_cmd},
    {SUBSCRIBE, "/subscribe", 1, 1, attribute_cmd},
    {SUBSCRIBED, "/subscribed", 0, 1, subscribe_logic},
    {UNSUBSCRIBE, "/unsubscribe", 1, 1, attribute_cmd},
    {USE, "/use", 0, 3, &use_logic},
    {CREATE, "/create", 1, 2, create_logic},
    {LIST, "/list", 0, 0, list_logic},
    {INFO, "/info", 0, 1, info_logic},
    {HELP, "/help", 0, 0, attribute_cmd},
    {UNKNOWN, NULL, 0, 0, NULL}
};

static void attribute_cmd(client_t *client, enum cmd_e cmd,
__attribute__((unused)) char **args)
{
    client->requested_cmd = cmd;
}

char *get_cmd(char *input, int *nbr_args)
{
    char *cmd_token = NULL;

    cmd_token = strtok(input, "\n\" ");
    if (!cmd_token)
        return NULL;
    for (int i = 0; CMD_TAB[i].cmd; i++) {
        if (strcmp(cmd_token, CMD_TAB[i].cmd) == 0) {
            *nbr_args = CMD_TAB[i].nb_args_max;
            return strdup(cmd_token);
        }
    }
    return NULL;
}

void apply_logic_cmd(client_t *client, char *cmd, char **args)
{
    for (int i = 0; CMD_TAB[i].cmd; i++) {
        if (strcmp(cmd, CMD_TAB[i].cmd) == 0 && CMD_TAB[i].logic) {
            CMD_TAB[i].logic(client, CMD_TAB[i].id, args);
            return;
        }
    }
}

bool is_number_args_valid(char **args, char *cmd)
{
    int nbr_args = 0;

    nbr_args = my_arrlen(args);
    for (int i = 0; CMD_TAB[i].cmd; i++) {
        if (strcmp(cmd, CMD_TAB[i].cmd) == 0 &&
        (nbr_args >= CMD_TAB[i].nb_args_min &&
        nbr_args <= CMD_TAB[i].nb_args_max)) {
            return true;
        }
    }
    return false;
}
