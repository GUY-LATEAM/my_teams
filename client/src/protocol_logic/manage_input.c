/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_input
*/

#include "select_func.h"
#include "protocol_logic.h"

void manage_input(client_t *client)
{
    char *input = NULL;

    input = read_input_select(&client->network_client->read_fds);
    if (!input)
        return;
    parse_input(client->network_client, input);
    free(input);
}
