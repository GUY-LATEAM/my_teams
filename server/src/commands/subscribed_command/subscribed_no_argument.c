/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribed_command
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "logging_server.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

static int write_team(team_t *team, circular_buffer_t *write_buffer)
{
    bool uuid = false;
    bool colon = false;
    bool name = false;
    bool colon2 = false;
    bool description = false;

    uuid = write_circular_buffer(write_buffer, team->uuid);
    colon = write_circular_buffer(write_buffer, ":");
    name = write_circular_buffer(write_buffer, team->name);
    colon2 = write_circular_buffer(write_buffer, ":");
    description = write_circular_buffer(write_buffer, team->description);
    if (uuid == false || colon == false || name == false || colon2 == false ||
    description == false)
        return false;
    return true;
}

static int if_loop_team(team_t *team, user_t *user, char *uuid_user,
circular_buffer_t *write_buffer)
{
    if (uuid_user == user->uuid) {
        if (write_team(team, write_buffer) == false)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int loop_team_subscribed(team_t *team, user_t *user,
circular_buffer_t *write_buffer)
{
    char *uuid_user = NULL;

    for (int j = 0; j < team->subscribed_users->len; j++) {
        uuid_user = get_list_i_data(team->subscribed_users, j);
        if (if_loop_team(team, user, uuid_user, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int subscribed_no_argument(server_t *server, user_t *user,
circular_buffer_t *write_buffer)
{
    team_t *team = NULL;

    if (write_circular_buffer(write_buffer, "OK 200 \"") == false)
        return EXIT_FAILURE;
    for (int i = 0; i < server->teams->len; i++) {
        team = get_list_i_data(server->teams, i);
        if (loop_team_subscribed(team, user, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (write_circular_buffer(write_buffer, GUY) == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
