/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_input
*/

#include "list_lib.h"
#include "select_func.h"
#include "protocol_logic.h"
#include <stdio.h>

void manage_input(client_t *client)
{
    char *input = NULL;
    network_client_t *cli = NULL;

    input = read_input_select(&client->network_client->read_fds);
    if (!input)
        return;
    
    printf("%d\n", client->network_client->clients->len);
    cli = get_list_i_data(client->network_client->clients, 0);
    parse_input(cli, input);
    free(input);
}
