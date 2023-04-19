/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** send_response_list_team
*/

#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "protocol_logic.h"
#include "save_struck.h"

static void loop_response_list_reply(
thread_t *thread, list_ptr_t *reply_list, int i)
{
    reply_t *reply = NULL;
    char *timestamp = NULL;
    size_t args_len = 0;
    char *args = NULL;

    reply = get_list_i_data(thread->replies, i);
    timestamp = time_to_string(thread->timestamp);
    if (reply == NULL || timestamp == NULL)
        return;
    args_len = strlen(thread->uuid) + strlen(BROADCAST_COLON)
    + strlen(reply->uuid_create) + strlen(BROADCAST_COLON) + strlen(timestamp)
    + strlen(BROADCAST_COLON) + strlen(reply->content);
    if ((args = malloc(sizeof(char) * (args_len + 1))) == NULL)
        return;
    memset(args, 0, args_len + 1);
    sprintf(args, "%s:%s:%s:%s", thread->uuid, reply->uuid_create, timestamp,
    reply->content);
    list_add_last(reply_list, args);
    free(timestamp);
}

void send_response_list_reply(
server_t *server, thread_t *thread, circular_buffer_t *write_buffer)
{
    list_ptr_t *reply_list = NULL;

    reply_list = list_create();
    if (server == NULL || thread == NULL || thread->replies == NULL
    || reply_list == NULL)
        return;
    for (int i = 0; i < thread->replies->len; i++) {
        loop_response_list_reply(thread, reply_list, i);
    }
    send_broadcast_list(write_buffer, reply_list);
    destroy_list(reply_list);
}
