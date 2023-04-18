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

static int print_subscribed_users(team_t *team, circular_buffer_t *write_buffer)
{
    char *uuid_user = NULL;


    if (write_circular_buffer(write_buffer, "OK 200 ") == EXIT_FAILURE)
        return EXIT_FAILURE;
    for (int j = 0; j < team->subscribed_users->len; j++) {
        uuid_user = get_list_i_data(team->subscribed_users, j);
        if (write_circular_buffer(write_buffer, uuid_user) == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (write_circular_buffer(write_buffer, ":") == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (write_circular_buffer(write_buffer, GUY) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_FAILURE;
}

static int if_print_subscribed(team_t *team, char *uuid,
circular_buffer_t *write_buffer)
{
    if (strcmp(team->uuid, uuid) == 0) {
        if (print_subscribed_users(team, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int subscribed_argument(server_t *server,
char *uuid, circular_buffer_t *write_buffer)
{
    team_t *team = NULL;

    for (int i = 0; i < server->teams->len; i++) {
        team = get_list_i_data(server->teams, i);
        if (if_print_subscribed(team, uuid, write_buffer) == EXIT_FAILURE)
            return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
