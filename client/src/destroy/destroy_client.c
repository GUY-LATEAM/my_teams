/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_client
*/

#include "my_teams_client.h"
#include "destroy_struct.h"
#include "server_func.h"

void destroy_client(client_t *client)
{
    destroy_server_network(client->network_client);
    destroy_context(client->context);
    if (client) {
        free(client);
    }
}
