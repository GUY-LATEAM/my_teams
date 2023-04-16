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

static int logout_command_annexe(server_t *server, user_t *user,
circular_buffer_t *write_buffer, char *name)
{
    if ((find_user_in_network(server, user) == false) ||
    (find_user_in_users(server, user) != LIST_OK)) {
        write_circular_buffer(write_buffer, "400 Bad Request: The received \
command is malformed or invalid.");
        write_circular_buffer(write_buffer, GUY);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int logout_command(void *user_data, void *protocol_data,
char *args, circular_buffer_t *write_buffer)
{
    char *name = NULL;
    user_t *user = NULL;
    server_t *server = NULL;

    user = (user_t *) user_data;
    server = (server_t *) protocol_data;
    name = strtok(args, "\"");
    if (name == NULL) {
        write_circular_buffer(write_buffer, "400 Bad Request: The received \
command is malformed or invalid.");
        write_circular_buffer(write_buffer, GUY);
        return EXIT_FAILURE;
    }
    if (logout_command_annexe(server, user, write_buffer, name) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
