/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** messages_command
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "logging_server.h"
#include "init_struct.h"
#include "save_struck.h"
#include "protocol_logic.h"
#include "commands.h"

static int write_start(circular_buffer_t *write_buffer)
{
    bool ok = false;
    bool code_bool = false;

    ok = write_circular_buffer(write_buffer, "OK ");
    code_bool = write_circular_buffer(write_buffer, "200 ");
    if (ok == false || code_bool == false)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int write_messages(conversation_t *conv, circular_buffer_t *write_buffer)
{
    message_t *message = NULL;

    for (int i = 0; i < conv->messages->len; i++) {
        message = get_list_i_data(conv->messages, i);
        write_circular_buffer(write_buffer, message->uuid_create);
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer,
        time_to_string(message->timestamp));
        write_circular_buffer(write_buffer, ":");
        write_circular_buffer(write_buffer, message->content);
        write_circular_buffer(write_buffer, ":");
    }
    write_circular_buffer(write_buffer, GUY);
    return EXIT_SUCCESS;
}

static int if_find_user(conversation_t *conv, circular_buffer_t *write_buffer,
char *uuid, int *bool_check)
{
    if (strcmp(conv->uuid_create, uuid) == 0) {
        if (write_start(write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (write_messages(conv, write_buffer) == EXIT_FAILURE)
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
        *bool_check = 1;
    }
    return EXIT_FAILURE;
}

static int find_users(user_t *user, circular_buffer_t *write_buffer, char *uuid)
{
    conversation_t *conv = NULL;
    int bool_check = 0;

    for (int i = 0; i < user->conversations->len; i++) {
        conv = get_list_i_data(user->conversations, i);
        if (if_find_user(conv, write_buffer,
        uuid, &bool_check) == EXIT_SUCCESS) {
            return EXIT_SUCCESS;
        }
    }
    if (bool_check == 0) {
        write_error(write_buffer, "404" , "Not Found: The requested resource \
was not found (e.g., a user, team, channel, or thread).");
    }
    return EXIT_SUCCESS;
}

int messages_command(void *user_data, void *protocol_data,
char *args, circular_buffer_t *write_buffer)
{
    server_t *server = NULL;
    char *uuid = NULL;
    user_t *user = NULL;

    server = (server_t *) protocol_data;
    user = (user_t *) user_data;
    if (check_is_user_login(server,
    user, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    uuid = strtok(args, " \"");
    if (uuid == NULL) {
        write_error(write_buffer, "400" , "Bad Request: The received command \
is malformed or invalid.");
        return EXIT_SUCCESS;
    }
    if (find_users(user, write_buffer, uuid) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
