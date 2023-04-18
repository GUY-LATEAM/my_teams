/*
** EPITECH PROJECT, 2023
** braodcast_all_users
** File description:
** braodcast_all_users
*/

#include "circular_buffer.h"
#include "list_lib.h"
#include "my_teams_server.h"
#include "network_structures.h"

bool broadcast_all_user(server_t *server, const char *message)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client != NULL && client->user_data != NULL
        && client->write_buffer != NULL) {
            write_circular_buffer(client->write_buffer, message);
        }
    }
    return true;
}
