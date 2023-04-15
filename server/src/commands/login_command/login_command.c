/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** login_command
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

user_t *is_user_exist(server_t *server, char *name)
{
    user_t *user = NULL;

    for (int i = 0; i < server->all_users->len; i++) {
        user = get_list_i_data(server->all_users, i);
        if (strcmp(user->name, name) == 0) {
            return user;
        }
    }
    return NULL;
}

bool link_user_to_client(server_t *server, user_t *user)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client->user_data == NULL) {
            client->user_data = user;
            return true;
        }
    }
    return false;
}

int login_broadcast(circular_buffer_t *write_buffer, user_t *user)
{
    char *message = NULL;
    bool command = false;
    bool guy = false;

    command = write_circular_buffer(write_buffer, "200 OK: The command was\
successfully processed.");
    guy = write_circular_buffer(write_buffer, GUY);
    if (command == false || guy == false)
        return false;
    message = malloc(sizeof(char) * (strlen(user->uuid) +\
    strlen(user->name) + 19));
    if (message == NULL)
        return false;
    sprintf(message, "broadcast LOGIN %s %s%s", user->uuid, user->name, GUY);
    write_circular_buffer(write_buffer, message);
    free(message);
    return true;
}

int login_command_annexe(server_t *server, circular_buffer_t *write_buffer,
char *name)
{
    user_t *user = NULL;

    user = is_user_exist(server, name);
    if (user == NULL) {
        user = init_user(name);
        list_add_last(server->all_users, user);
        server_event_user_created(user->uuid,user->name);
    }
    server_event_user_logged_in(user->uuid);
    if ((link_user_to_client(server, user) == false) ||
    (login_broadcast(write_buffer, user) == false)) {
        write_circular_buffer(write_buffer, "400 Bad Request: The received \
command is malformed or invalid.");
        write_circular_buffer(write_buffer, GUY);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int login_command(__attribute__((unused)) void *user_data, void *protocol_data,
char *args, circular_buffer_t *write_buffer)
{
    char *name = NULL;
    server_t *server = NULL;

    server = (server_t *) protocol_data;
    name = strtok(args, "\"");
    if (name == NULL) {
        write_circular_buffer(write_buffer, "400 Bad Request: The received \
command is malformed or invalid.");
        write_circular_buffer(write_buffer, GUY);
        return EXIT_FAILURE;
    }
    if (login_command_annexe(server, write_buffer, name) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
