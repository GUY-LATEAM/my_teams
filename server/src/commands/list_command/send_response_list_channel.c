/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** send_response_list_channel
*/

#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "protocol_logic.h"
#include "save_struck.h"

static void loop_response_list_channel(
server_t *server, team_t *team, list_ptr_t *channel_list, int i)
{
    channel_t *channel = NULL;
    size_t args_len = 0;
    char *args = NULL;

    channel = get_list_i_data(team->channels, i);
    args_len = strlen(channel->uuid) + strlen(BROADCAST_COLON)
    + strlen(channel->name) + strlen(BROADCAST_COLON)
    + strlen(channel->description);
    if ((args = malloc(sizeof(char) * (args_len + 1))) != NULL) {
        memset(args, 0, args_len + 1);
        sprintf(
        args, "%s:%s:%s", channel->uuid, channel->name, channel->description);
        list_add_last(channel_list, args);
    }
}

void send_response_list_channel(
server_t *server, team_t *team, circular_buffer_t *write_buffer)
{
    list_ptr_t *channel_list = NULL;

    if (server == NULL || (channel_list = list_create()) == NULL)
        return;
    for (int i = 0; i < team->channels->len; i++) {
        loop_response_list_channel(server, team, channel_list, i);
    }
    send_broadcast_list(write_buffer, channel_list);
    destroy_list(channel_list);
}
