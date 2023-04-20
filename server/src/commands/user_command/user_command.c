/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** user_command
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

static int write_user_info(user_t *user, circular_buffer_t *write_buffer,
char *uuid, int *bool_check)
{
    if (strcmp(user->uuid, uuid) == 0) {
        write_circular_buffer(write_buffer, "OK 200 ");
        write_circular_buffer(write_buffer, user->uuid);
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer, user->name);
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer, user->nb_users > 1 ? "1" : "0");
        write_circular_buffer(write_buffer, GUY);
        *bool_check = 1;
    }
    return EXIT_SUCCESS;
}

static int find_users(server_t *server, circular_buffer_t *write_buffer,
char *uuid)
{
    user_t *user = NULL;
    int bool_check = 0;

    for (int i = 0; i < server->all_users->len; i++) {
        user = get_list_i_data(server->all_users, i);
        if (write_user_info(user, write_buffer, uuid,
        &bool_check) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (bool_check == 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int user_command(__attribute__((unused)) void *user_data, void *protocol_data,
char *args, circular_buffer_t *write_buffer)
{
    server_t *server = NULL;
    char *uuid = NULL;

    server = (server_t *) protocol_data;
    if (check_is_user_login(server,
    (user_t *) user_data, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    uuid = strtok(args, " \"");
    if (uuid == NULL) {
        write_error(write_buffer, "400" , "Bad Request: The received command \
is malformed or invalid.");
        return EXIT_SUCCESS;
    }
    if (find_users(server, write_buffer, uuid) == EXIT_FAILURE) {
        write_error(write_buffer, "404" , uuid);
    }
    return EXIT_SUCCESS;
}
