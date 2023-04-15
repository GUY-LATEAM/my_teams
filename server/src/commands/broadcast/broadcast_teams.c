/*
** EPITECH PROJECT, 2023
** broadcast_teams
** File description:
** broadcast_teams
*/

#include <string.h>
#include "my_teams_server.h"
#include "network_structures.h"
#include "list_lib.h"
#include "commands.h"

static bool is_user_subcribed_to_team(user_t *user, team_t *team)
{
    char *subscribed_user = NULL;

    for (int i = 0; i < team->subscribed_users->len; i++) {
        subscribed_user = get_list_i_data(team->subscribed_users, i);
        if (strcmp(subscribed_user, user->uuid) == 0) {
            return true;
        }
    }
    return false;
}

static void applided_broadcast_team(server_t *server, user_t *user,
const char *message)
{
    network_client_t *client = NULL;

    for (int j = 0; j < server->network_server->clients->len; j++) {
        client = get_list_i_data(server->network_server->clients, j);
        if ((client->user_data) && (client->user_data == user)) {
            write_circular_buffer(client->write_buffer, message);
        }
    }
}

static bool find_broadcast_team(server_t *server, team_t *team,
const char *message)
{
    char *client_sub_uuid = NULL;
    user_t *user = NULL;

    for (int i = 0; i < team->subscribed_users->len; i++) {
        client_sub_uuid = get_list_i_data(team->subscribed_users, i);
        user = find_user(server, client_sub_uuid);
        if (user == NULL) {
            return false;
        }
        applided_broadcast_team(server, user, message);
    }
    return true;
}

static bool if_find_team(server_t *server, team_t *team, user_t *user,
const char *message)
{
    if (is_user_subcribed_to_team(user, team)) {
        if (find_broadcast_team(server, team, message) == false) {
            return false;
        }
    }
    return true;
}

bool broadcast_teams(server_t *server, user_t *user, const char *message)
{
    team_t *team = NULL;

    for (int i = 0; i < server->teams->len; i++) {
        team = get_list_i_data(server->teams, i);
        if (if_find_team(server, team, user, message) == false) {
            return false;
        }
    }
    return true;
}
