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

int add_in_list(network_client_t *client, user_t *user, char **tab)
{
    message_t *message_struct = NULL;
    conversation_t *conversation = NULL;

    message_struct = init_message(tab[1]);
    if (message_struct == NULL)
        return EXIT_FAILURE;
    conversation = check_is_conversation((user_t *)client->user_data, tab[0]);
    if (conversation == NULL) {
        conversation = init_conversation(user->uuid);
        if (list_add_last(((user_t *)client->user_data)\
            ->conversations, conversation) != LIST_OK)
            return EXIT_FAILURE;
    }
    if (list_add_last(conversation->messages, message_struct) != LIST_OK)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int send_message_if(network_client_t *client, user_t *user, char **tab,
int *check_bool)
{
    if (strcmp(((user_t *)client->user_data)->uuid, tab[0]) == 0) {
        if (*check_bool == 0) {
                add_in_list(client, user, tab);
                *check_bool = 1;
        }
        if (broadcast_message(client->write_buffer, tab[1],
            user->uuid) == EXIT_FAILURE)
                return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int find_write(network_client_t *client,
user_t *user, char **tab)
{
    if (strcmp(((user_t *)client->user_data)->uuid, tab[0]) == 0) {
        if (broadcast_message(client->write_buffer, tab[1],
        user->uuid) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
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
