/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_client
*/

#include "my_teams_client.h"
#include "init_struct.h"

client_t *init_client(void)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return NULL;
    client->network_client = create_network_client();
    client->context = init_context();
    return client;
}