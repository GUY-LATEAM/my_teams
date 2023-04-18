/*
** EPITECH PROJECT, 2023
** broadcast_teams
** File description:
** broadcast_teams
*/

#include <string.h>
#include "commands.h"
#include "list_lib.h"
#include "my_teams_server.h"
#include "network_structures.h"

static void applided_broadcast_team(
server_t *server, user_t *user, const char *message)
{
    network_client_t *client = NULL;

    for (int j = 0; j < server->network_server->clients->len; j++) {
        client = get_list_i_data(server->network_server->clients, j);
        if ((client->user_data) && (client->user_data == user)) {
            write_circular_buffer(client->write_buffer, message);
        }
    }
}

static void send_broadcast_to_team(
server_t *server, char *user_uuid, const char *message)
{
    network_client_t *client = NULL;
    user_t *user = NULL;

    for (int j = 0; j < server->network_server->clients->len; j++) {
        client = get_list_i_data(server->network_server->clients, j);
        if (client->user_data == NULL) {
            continue;
        }
        user = client->user_data;
        if (strcmp(user->uuid, user_uuid) == 0) {
            applided_broadcast_team(server, user, message);
        }
    }
}

int broadcast_teams(server_t *server, team_t *team, const char *message)
{
    char *user_uuid = NULL;

    for (int i = 0; i < team->subscribed_users->len; i++) {
        user_uuid = get_list_i_data(team->subscribed_users, i);
        if (user_uuid == NULL) {
            return EXIT_FAILURE;
        }
        send_broadcast_to_team(server, user_uuid, message);
    }
    return EXIT_SUCCESS;
}
