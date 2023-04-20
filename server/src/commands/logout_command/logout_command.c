/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** logout_command
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "add_struct.h"
#include "circular_buffer.h"
#include "destroy_struct.h"
#include "init_struct.h"
#include "logging_server.h"
#include "my_teams_server.h"
#include "protocol_logic.h"

static network_client_t *get_client_by_write_buffer(
server_t *server, circular_buffer_t *buffer)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client->write_buffer == buffer)
            return client;
    }
    return NULL;
}

static bool find_user_in_network(
server_t *server, circular_buffer_t *write_buffer)
{
    network_client_t *client = NULL;

    client = get_client_by_write_buffer(server, write_buffer);

    if (client == NULL)
        return false;
    client->user_data = NULL;
    return true;
}

static int logout_broadcast(server_t *server, user_t *user)
{
    char *message = NULL;

    message = malloc(sizeof(char)
    * (strlen(user->uuid)
    + (strlen(user->name) + (strlen(GUY)) + strlen(LOGOUT_BROADCAST)
    + strlen(BROADCAST_MARK) + strlen(BROADCAST_COLON) + 1)));
    if (message == NULL)
        return EXIT_FAILURE;
    if (sprintf(
        message, "broadcast LOGOUT \"%s:%s\"%s", user->uuid, user->name, GUY)
    < 0)
        return EXIT_FAILURE;
    if (broadcast_all_user(server, message) == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int logout_command_annexe(server_t *server,
__attribute__((unused)) user_t *user, circular_buffer_t *write_buffer)
{
    if ((find_user_in_network(server, write_buffer) == false)) {
        write_error(write_buffer, "500",
        "Internal Server Error: An \
error occurred on the server side while processing the command.");
        return EXIT_FAILURE;
    }
    if (write_success(write_buffer, "200",
        "OK: The command \
was successfully processed.")
    == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int logout_command(void *user_data, void *protocol_data,
__attribute__((unused)) char *args, circular_buffer_t *write_buffer)
{
    user_t *user = NULL;
    server_t *server = NULL;

    user = (user_t *) user_data;
    server = (server_t *) protocol_data;
    if (user == NULL) {
        write_success(write_buffer, "200", "Goodbye");
        return EXIT_SUCCESS;
    }
    server_event_user_logged_out(user->uuid);
    user->nb_users--;
    if ((logout_broadcast(server, user) == EXIT_FAILURE)
    || (logout_command_annexe(server, user, write_buffer) == EXIT_FAILURE))
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
