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

network_client_t *find_circular_with_id(server_t *server, char *uuid)
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
