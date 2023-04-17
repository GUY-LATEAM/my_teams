/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_input
*/

#include <string.h>
#include "protocol_logic.h"
#include "libstr.h"

void free_parse_info(char *cmd, char **args)
{
    if (cmd)
        free(cmd);
    if (args) {
        destroy_array(args);
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
    args = str_to_word_array(input, "\" ");
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
