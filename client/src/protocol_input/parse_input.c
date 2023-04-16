/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_input
*/

#include <string.h>
#include "protocol_logic.h"

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
            free_parse_info(NULL, args);
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

void parse_input(client_t *client, network_client_t *net_client, char *input)
{
    char *cmd = NULL;
    char **args = NULL;
    int nb_args = 0;

    cmd = get_cmd(input, &nb_args);
    args = get_args(nb_args);
    for (int i = 0; i < nb_args; i++) {
        printf("%s", args[i]);
    }
    if (!net_client || !cmd || !args) {
        display_error(cmd, args);
        free_parse_info(cmd, args);
        return;
    }
    apply_logic_cmd(client, cmd, args, &nb_args);
    write_circular_buffer(net_client->write_buffer, cmd + 1);
    write_circular_buffer(net_client->write_buffer, SP);
    write_args(net_client, args, nb_args);
    write_circular_buffer(net_client->write_buffer, GUY);
    free_parse_info(cmd, args);
}
