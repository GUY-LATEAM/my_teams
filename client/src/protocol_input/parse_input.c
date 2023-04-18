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

void write_args(network_client_t *client, char **args, int nb_args_max)
{
    int nb_args = 0;

    if (nb_args_max == 0 || args == NULL)
        return;
    nb_args = my_arrlen(args);
    for (int i = 0; i < nb_args_max; i++) {
        if (i < nb_args) {
            printf("arg : %s\n", args[i]);
        write_circular_buffer(client->write_buffer, args[i]);
        }
        if (i != nb_args_max - 1)
            write_circular_buffer(client->write_buffer, ":");
    }
    write_circular_buffer(client->write_buffer, "\"");
}

void parse_input(client_t *client, network_client_t *net_client, char *input)
{
    char *cmd = NULL;
    char **args = NULL;
    int nb_args = 0;

    cmd = get_cmd(input, &nb_args);
    if (cmd == NULL)
        return;
    input += strlen(cmd) + 1;
    args = str_to_word_array(input, "\" \n");
    if (!net_client || !cmd || !args) {
        display_error(cmd, args);
        free_parse_info(cmd, args);
        return;
    }
    write_circular_buffer(net_client->write_buffer, cmd + 1);
    write_circular_buffer(net_client->write_buffer, " \"");
    apply_logic_cmd(client, cmd, args, &nb_args);
    write_args(net_client, args, nb_args);
    write_circular_buffer(net_client->write_buffer, GUY);
    free_parse_info(cmd, args);
}
