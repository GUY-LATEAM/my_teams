/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** get_info_current_thread
*/

#include <string.h>
#include "libstr.h"
#include "commands.h"
#include "my_teams_server.h"
#include "protocol_logic.h"
#include "save_struck.h"

thread_t *get_thread_by_context(char **context, channel_t *channel)
{
    thread_t *tmp_thread = NULL;

    for (int i = 0; i < channel->threads->len; i++) {
        tmp_thread = get_list_i_data(channel->threads, i);
        if (strcmp(tmp_thread->uuid, context[2]) == 0)
            return tmp_thread;
    }
    return NULL;
}

bool is_context_thread(char **context)
{
     if (my_arrlen(context) != 3)
        return false;
    if (strcmp(context[0], "UN") != 0
    && strcmp(context[1], "UN") != 0
    && strcmp(context[2], "UN") != 0) {
        return true;
    }
    return false;
}

void send_info_current_thread(server_t *serv, char **context,
circular_buffer_t *write)
{
    thread_t *thread_ctx = NULL;

    thread_ctx = get_thread_by_context(context,
    get_channel_by_context(context, get_team_by_context(context, serv)));
    if (!thread_ctx)
        return;
    write_circular_buffer(write, "OK");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "200");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, thread_ctx->uuid);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, thread_ctx->uuid_create);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, time_to_string(thread_ctx->timestamp));
    write_circular_buffer(write, ":");
    write_circular_buffer(write, thread_ctx->message);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, GUY);
}
