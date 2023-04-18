/*
** EPITECH PROJECT, 2023
** braodcast_all_users
** File description:
** braodcast_all_users
*/

#include "my_teams_server.h"
#include "network_structures.h"
#include "circular_buffer.h"
#include "list_lib.h"

bool broadcast_all_user(server_t *server, const char *message)
{
    network_client_t *client = NULL;

    printf("ptr server: %p\n", server);
    printf("ptr network_server: %p\n", server->network_server);
    printf("ptr clients: %p\n", server->network_server->clients);
    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client != NULL && client->user_data != NULL && client->write_buffer != NULL) {
            write_circular_buffer(client->write_buffer, message);
        }
    }
    printf("after\n");
    return true;
}
