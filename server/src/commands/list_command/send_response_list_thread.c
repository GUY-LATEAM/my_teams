/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** send_response_list_thread
*/

#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "protocol_logic.h"
#include "save_struck.h"

static void loop_reponse_list_thread(
channel_t *channel, list_ptr_t *thread_list, int i)
{
    char *args = NULL;
    size_t args_len = 0;
    thread_t *thread = NULL;
    char *timestamp = NULL;

    if ((thread = get_list_i_data(channel->threads, i)) == NULL)
        return;
    if ((timestamp = time_to_string(thread->timestamp)) == NULL)
        return;
    args_len = strlen(thread->uuid) + strlen(BROADCAST_COLON)
    + strlen(thread->uuid_create) + strlen(BROADCAST_COLON) + strlen(timestamp)
    + strlen(BROADCAST_COLON) + strlen(thread->title) + strlen(BROADCAST_COLON)
    + strlen(thread->message);
    if ((args = malloc(sizeof(char) * (args_len + 1))) != NULL) {
        memset(args, 0, args_len + 1);
        sprintf(args, "%s:%s:%s:%s:%s", thread->uuid, thread->uuid_create,
        timestamp, thread->title, thread->message);
        list_add_last(thread_list, args);
        free(timestamp);
    }
}

void send_response_list_thread(
server_t *server, channel_t *channel, circular_buffer_t *write_buffer)
{
    list_ptr_t *thread_list = NULL;

    thread_list = list_create();
    if (server == NULL || channel == NULL || channel->threads == NULL
    || thread_list == NULL)
        return;
    printf("channel->threads->len: %d\n", channel->threads->len);
    for (int i = 0; i < channel->threads->len; i++) {
        loop_reponse_list_thread(channel, thread_list, i);
    }
    send_broadcast_list(write_buffer, thread_list);
    destroy_list(thread_list);
}
