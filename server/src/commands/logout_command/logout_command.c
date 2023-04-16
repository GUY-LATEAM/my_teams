/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** logout_command
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
#include "destroy_struct.h"

static bool find_user_in_network(server_t *server, user_t *user)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client->user_data == user) {
            client->user_data = NULL;
            return true;
        }
    }
    return false;
}

static int find_user_in_users(server_t *server, user_t *user)
{
    user_t *user_tmp = NULL;

    for (int i = 0; i < server->all_users->len; i++) {
        user_tmp = get_list_i_data(server->all_users, i);
        if (user_tmp == user) {
            destroy_user(user);
            return remove_list_element(server->all_users, i);
        }
    }
    return LIST_OK;
}

static int logout_broadcast(server_t *server, user_t *user)
{
    char *message = NULL;

    message = malloc(sizeof(char) * (strlen(user->uuid) + \
    (strlen(user->name) + 19)));
    if (message == NULL)
        return EXIT_FAILURE;
    if (sprintf(message, "broadcast LOGOUT %s %s%s", user->uuid,
    user->name, GUY) < 0)
        return EXIT_FAILURE;
    broadcast_all_user(server, message);
    return EXIT_SUCCESS;
}

static int logout_command_annexe(server_t *server, user_t *user,
circular_buffer_t *write_buffer)
{
    if ((find_user_in_network(server, user) == false) ||
    (find_user_in_users(server, user) != LIST_OK) ||
            write_error(write_buffer, "500", "Internal Server Error: An \
error occurred on the server side while processing the command.") == false) {
        return EXIT_FAILURE;
    }
    if (write_success(write_buffer, "200", "OK: The command \
was successfully processed.") == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
    server_event_user_logged_out(user->uuid);
}

int logout_command(void *user_data, void *protocol_data,
__attribute__((unused)) char *args, circular_buffer_t *write_buffer)
{
    user_t *user = NULL;
    server_t *server = NULL;

    user = (user_t *) user_data;
    server = (server_t *) protocol_data;
    if (write_error(write_buffer, "400", "Bad Request: The received \
command is malformed or invalid.") == false) {
        return EXIT_FAILURE;
    }
    if ((check_is_user_login(server, user, write_buffer) == EXIT_FAILURE) ||
    (logout_command_annexe(server, user, write_buffer) == EXIT_FAILURE) ||
    (logout_broadcast(server, user) == EXIT_FAILURE))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
