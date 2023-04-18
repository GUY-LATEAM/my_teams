/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** get_info_current_channel
*/

#include <string.h>
#include "libstr.h"
#include "my_teams_server.h"
#include "protocol_logic.h"
#include "commands.h"

channel_t *get_channel_by_context(char **context, team_t *team)
{
    channel_t *tmp_team = NULL;

    for (int i = 0; i < team->channels->len; i++) {
        tmp_team = get_list_i_data(team->channels, i);
        if (strcmp(tmp_team->uuid, context[1]) == 0)
            return tmp_team;
    }
    return NULL;
}

bool is_context_channel(char **context)
{
    if (my_arrlen(context) != 3)
        return false;
    if (strcmp(context[0], "UN") != 0
    && strcmp(context[1], "UN") != 0
    && strcmp(context[2], "UN") == 0) {
        return true;
    }
    return false;
}

void send_info_current_channel(server_t *serv, char **context,
circular_buffer_t *write)
{
    channel_t *channel_ctx = NULL;

    channel_ctx = get_channel_by_context(context,
    get_team_by_context(context, serv));
    if (!channel_ctx)
        return;
    write_circular_buffer(write, "OK");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "200");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, channel_ctx->uuid);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, channel_ctx->name);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, channel_ctx->description);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, GUY);
}
