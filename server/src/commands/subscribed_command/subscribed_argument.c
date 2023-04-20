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
#include "libstr.h"
#include "logging_server.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

static user_t *get_user_by_uuid(list_ptr_t *list, char *user_uuid)
{
    user_t *user = NULL;

    for (int i = 0; i < list->len; i++) {
        user = get_list_i_data(list, i);
        if (strcmp(user->uuid, user_uuid) == 0) {
            return user;
        }
    }
    return NULL;
}

static int print_subscribed_users(team_t *team, circular_buffer_t *write_buffer,
server_t *serv)
{
    char *uuid_user = NULL;
    user_t *user = NULL;

    write_circular_buffer(write_buffer, "OK 200 ");
    for (int j = 0; j < team->subscribed_users->len; j++) {
        uuid_user = get_list_i_data(team->subscribed_users, j);
        user = get_user_by_uuid(serv->all_users, uuid_user);
        write_circular_buffer(write_buffer, user->uuid);
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer, user->name);
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer,
        user->nb_users > 0 ? "1" : "0");
        write_circular_buffer(write_buffer, ":");
    }
    write_circular_buffer(write_buffer, GUY);
    return EXIT_FAILURE;
}

static int if_print_subscribed(team_t *team, char *uuid,
circular_buffer_t *write_buffer, server_t *serv)
{
    if (strcmp(team->uuid, uuid) == 0) {
        if (print_subscribed_users(team, write_buffer, serv)
        == EXIT_FAILURE)
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
        if (if_print_subscribed(team, uuid, write_buffer, server)
        == EXIT_FAILURE)
            return EXIT_SUCCESS;
    }
    write_error(write_buffer, "404", "Can't find team");
    return EXIT_SUCCESS;
}
