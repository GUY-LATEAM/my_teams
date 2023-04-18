/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** send_command
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

static network_client_t *find_circular_with_id(server_t *server, char *uuid)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (strcmp(((user_t *)client->user_data)->uuid, uuid) == 0) {
            return client;
        }
    }
    return NULL;
}

conversation_t *check_is_conversation(user_t *user, char *uuid)
{
    conversation_t *conversation = NULL;

    for (int i = 0; i < user->conversations->len; i++) {
        conversation = get_list_i_data(user->conversations, i);
        if (strcmp(conversation->uuid_create, uuid) == 0) {
            return conversation;
        }
    }
    return NULL;
}

int broadcast_message(circular_buffer_t *write, char *message, char *uuid)
{
    char *message_to_send = NULL;

    message_to_send = malloc(sizeof(char) * (strlen(message) + \
    strlen(uuid) + strlen(MESSAGE_BRDCAST) + strlen(GUY) + 3));
    if (message_to_send == NULL)
        return EXIT_FAILURE;
    sprintf(message_to_send, "broadcast MESSAGE \"%s:%s\"%s", uuid,
    message, GUY);
    if (write_circular_buffer(write, message_to_send) == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int add_message_struct(server_t *server, user_t *user, char *message,
char *uuid)
{
    message_t *message_struct = NULL;
    network_client_t *client = NULL;
    conversation_t *conversation = NULL;

    client = find_circular_with_id(server, uuid);
    if (client == NULL)
        return EXIT_FAILURE;
    message_struct = init_message(message);
    if (message_struct == NULL)
        return EXIT_FAILURE;
    conversation = check_is_conversation((user_t *)client->user_data, uuid);
    if (conversation == NULL)
        conversation = init_conversation(user->uuid);
    if (add_message_to_conversation(conversation, message_struct) == false ||
    broadcast_message(client->write_buffer,
    message, user->uuid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int send_command( void *user_data, void *protocol_data, char *args,
__attribute__((unused)) circular_buffer_t *write_buffer)
{
    server_t *server = NULL;
    char **tab = NULL;

    server = (server_t *) protocol_data;
    if (check_is_user_login(server,
    (user_t *) user_data, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    tab = str_to_word_array(args, "\":");
    if (tab == NULL || tab[0] == NULL || tab[1] == NULL) {
        write_error(write_buffer, "500", "Internal Server Error: An \
error occurred on the server side while processing the command.");
        return EXIT_FAILURE;
    }
    if (add_message_struct(server, (user_t *)user_data,
    tab[1], tab[0]) == EXIT_FAILURE) {
        write_error(write_buffer, "404", "Not Found: The user does not \
exist.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
