/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_input
*/

#include "protocol_logic.h"

static const char GUY[] = "\x67\x75\x79";
static const char SP[] = " \n";
static const cmd_t CMD_TAB[] = {
    "login", 1,
    "user", 1,
    "send", 2,
    "messages", 1,
    "subscribe", 1,
    "subscribed", 1,
    "unsubscribe", 1,
    "use", 0,
    "create", 0,
    "list", 0,
    "info", 0,
    NULL, 0
};

char *get_cmd(char *input, int *nb_args)
{
    int i = 0;
    char *cmd_token = NULL;

    cmd_token = strtok(input, SP);
    if (!cmd_token)
        return NULL;
    for (i = 0; CMD_TAB[i].cmd; i++) {
        if (strcasecmp(cmd_token, CMD_TAB[i].cmd) == 0) {
            *nb_args = CMD_TAB[i].nb_args;
            return strdup(cmd_token);
        }   
    }
}

char **get_args(char *input, int nb_args)
{
    char **args = NULL;
    char *arg_token = NULL;

    if (nb_args == 0)
        return NULL;
    args = malloc(sizeof(char *) * (nb_args + 1));
    if (!args)
        return NULL;
    for (int i = 0; i < nb_args; i++) {
        arg_token = strtok(NULL, SP);
        if (!arg_token)
            return NULL;
        args[i] = strdup(arg_token);
    }
    args[nb_args] = NULL;
    if (strtok(NULL, SP) != NULL) {
        free(args);
        return NULL;
    }
    return args;
}

void parse_input(network_client_t *client, char *input)
{
    char *cmd = NULL;
    char **args = NULL;
    int nb_args = 0;

    cmd = get_cmd(input, &nb_args);
    args = get_args(input, nb_args);
    if (!client || !cmd || !args) {
        // Free CMD + ARGS + Say error
        return;
    }
    write_circular_buffer(client->write_buffer, cmd);
    write_circular_buffer(client->write_buffer, SP);
    for (int i = 0; i < nb_args; i++) {
        write_circular_buffer(client->write_buffer, "\"");
        write_circular_buffer(client->write_buffer, args[i]);
        write_circular_buffer(client->write_buffer, "\"");
        if (i != nb_args - 1)
            write_circular_buffer(client->write_buffer, SP);
    }
    write_circular_buffer(client->write_buffer, GUY);
}