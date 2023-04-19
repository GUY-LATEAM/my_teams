/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_input
*/

#include <string.h>
#include "protocol_logic.h"
#include "libstr.h"
#include "list_lib.h"

static char **list_to_tab(list_ptr_t *ptr)
{
    char **tab = NULL;
    char *tmp_char = NULL;

    if (ptr == NULL)
        return NULL;
    if (ptr->len == 0) {
        free(ptr);
        return NULL;
    }
    tab = malloc(sizeof(char *) * (ptr->len + 1));
    for (int i = 0; i < ptr->len; i++) {
        tmp_char = get_list_i_data(ptr, i);
        tab[i] = strdup(tmp_char);
    }
    tab[ptr->len] = NULL;
    for (int i = 0; i < ptr->len; i++) {
        remove_list_element(ptr, i);
    }
    free(ptr);
    return tab;
}

static char **custom_str_word_array(char *args)
{
    int i = 0;
    char **tab = NULL;
    char *token = NULL;
    list_ptr_t *list = NULL;
    int size = 0;

    list = list_create();
    if (!list)
        return NULL;
    size = my_strlen(args);
    while (i != size) {
        if (args[i] == '"') {
            token = strtok(args + i, "\"");
            list_add_last(list, token);
            i += strlen(token);
        }
        i++;
    }
    tab = list_to_tab(list);
    return tab;
}

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
    args = custom_str_word_array(input);
    if (!net_client || !cmd ||
    !is_number_args_valid(args, cmd)) {
        display_error(cmd, args);
        return;
    }
    write_circular_buffer(net_client->write_buffer, cmd + 1);
    write_circular_buffer(net_client->write_buffer, " \"");
    apply_logic_cmd(client, cmd, args);
    write_args(net_client, args, nb_args);
    write_circular_buffer(net_client->write_buffer, GUY);
    free_parse_info(cmd, args);
}
