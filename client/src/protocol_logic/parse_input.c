/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_input
*/

#include <stdio.h>
#include <string.h>
#include "protocol_logic.h"

static const cmd_t CMD_TAB[] = {
    {"/login", 1},
    {"/user", 1},
    {"/send", 2},
    {"/messages", 1},
    {"/subscribe", 1},
    {"/subscribed", 1},
    {"/unsubscribe", 1},
    {"/use", 0},
    {"/create", 0},
    {"/list", 0},
    {"/info", 0},
    {NULL, 0}
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
    return NULL;
}

char **get_args(int nb_args)
{
    char **args = NULL;
    char *arg_token = NULL;

    if (nb_args == 0)
        return NULL;
    args = malloc(sizeof(char *) * (nb_args + 1));
    if (!args)
        return NULL;
    for (int i = 0; i < nb_args; i++) {
        arg_token = strtok(NULL, SEPARATORS);
        if (!arg_token) {
            for (int j = 0; j < i; j++)
                free(args[j]);
            free(args);
            return NULL;
        }
        args[i] = strdup(arg_token);
    }
    args[nb_args] = NULL;
    return args;
}

void free_parse_info(char *cmd, char **args)
{
    if (cmd)
        free(cmd);
    if (args) {
        for (int i = 0; args[i]; i++)
            free(args[i]);
        free(args);
    }
}

void write_args(network_client_t *client, char **args, int nb_args)
{
    for (int i = 0; i < nb_args; i++) {
        write_circular_buffer(client->write_buffer, "\"");
        write_circular_buffer(client->write_buffer, args[i]);
        write_circular_buffer(client->write_buffer, "\"");
        if (i != nb_args - 1)
            write_circular_buffer(client->write_buffer, SP);
    }
}

void parse_input(network_client_t *client, char *input)
{
    char *cmd = NULL;
    char **args = NULL;
    int nb_args = 0;

    cmd = get_cmd(input, &nb_args);
    args = get_args(nb_args);
    if (!client || !cmd || !args) {
        display_error(cmd, args);
        free_parse_info(cmd, args);
        return;
    }
    write_circular_buffer(client->write_buffer, cmd);
    write_circular_buffer(client->write_buffer, SP);
    write_args(client, args, nb_args);
    write_circular_buffer(client->write_buffer, GUY);
    free_parse_info(cmd, args);
}
