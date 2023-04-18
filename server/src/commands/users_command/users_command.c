/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** users_command
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "logging_server.h"
#include "init_struct.h"
#include "libstr.h"
#include "protocol_logic.h"
#include "libstr.h"
#include "commands.h"

static int write_user_info(user_t *user, circular_buffer_t *write_buffer)
{
    bool name = false;
    bool colon = false;
    bool uuid = false;
    bool colon2 = false;
    bool nb_con = false;
    bool guy = false;

    name = write_circular_buffer(write_buffer, user->name);
    colon = write_circular_buffer(write_buffer, ":");
    uuid = write_circular_buffer(write_buffer, user->uuid);
    colon2 = write_circular_buffer(write_buffer, ":");
    nb_con = write_circular_buffer(write_buffer, int_to_string(user->nb_users));
    guy = write_circular_buffer(write_buffer, GUY);
    if (name == false || colon == false || uuid == false || colon2 == false ||
    nb_con == false || guy == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int write_first_command(int index, circular_buffer_t *write_buffer)
{
    if (index == 0) {
        if (write_circular_buffer(write_buffer, "OK 200 ") == false)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int find_users(server_t *server, circular_buffer_t *write_buffer)
{
    user_t *user = NULL;

    for (int i = 0; i < server->all_users->len; i++) {
        if (write_first_command(i, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
        user = get_list_i_data(server->all_users, i);
        if (write_user_info(user, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int users_command(__attribute__((unused)) void *user_data, void *protocol_data,
__attribute__((unused)) char *args, circular_buffer_t *write_buffer)
{
    server_t *server = NULL;

    server = (server_t *) protocol_data;
    if (check_is_user_login(server,
    (user_t *) user_data, write_buffer) == false) {
        return EXIT_SUCCESS;
    }
    if (find_users(server, write_buffer) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
