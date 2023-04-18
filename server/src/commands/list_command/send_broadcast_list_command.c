/*
** EPITECH PROJECT, 2023
** server
** File description:
** send_broadcast_list_command
*/

#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "protocol_logic.h"
#include "save_struck.h"

static void send_broadcast_list(
server_t *server, team_t *team, const char *broadcast_type, const char *args)
{
    char *message = NULL;
    size_t message_len = 0;

    if (server == NULL || team == NULL) {
        return;
    }
    message_len = strlen(broadcast_type) + strlen(SP BROADCAST_MARK)
    + strlen(args) + strlen(BROADCAST_MARK);
    message = malloc(sizeof(char) * (message_len + 1));
    if (message == NULL) {
        return;
    }
    memset(message, 0, message_len + 1);
    sprintf(message, BROADCAST "%s" SP BROADCAST_MARK "%s" BROADCAST_MARK,
    broadcast_type, args);
    broadcast_teams(server, team, message);
}

void send_response_list_teams(server_t *server)
{
    char *args = NULL;
    team_t *team = NULL;
    size_t args_len = 0;

    if (server == NULL) {
        return;
    }
    for (int i = 0; i < server->teams->len; i++) {

    }
    args_len = strlen(BROADCAST "TEAMS" SP BROADCAST_MARK) + strlen(team->uuid)
    + strlen(BROADCAST_COLON) + strlen(team->name) + strlen(BROADCAST_COLON)
    + strlen(team->description) + strlen(BROADCAST_MARK) + strlen(GUY);
    args = malloc(sizeof(char) * (args_len + 1));
    if (args == NULL) {
        return;
    }
    memset(args, 0, args_len + 1);
    sprintf(args,
    BROADCAST "TEAMS" SP BROADCAST_MARK "%s:%s:%s" BROADCAST_MARK GUY,
    team->uuid, team->name, team->description);
    write_circular_buffer(server->client->circular_buffer, args);
}

void send_response_list_channel(server_t *server, team_t *team)
{
    char *args = NULL;
    size_t args_len = 0;

    if (server == NULL || channel == NULL) {
        return;
    }
    args_len = strlen(channel->uuid) + strlen(BROADCAST_COLON)
    + strlen(channel->name) + strlen(BROADCAST_COLON)
    + strlen(channel->description) + 2;
    args = malloc(sizeof(char) * (args_len + 1));
    if (args == NULL) {
        return;
    }
    memset(args, 0, args_len + 1);
    sprintf(
    args, "%s:%s:%s", channel->uuid, channel->name, channel->description);
    send_broadcast_list(server, team, "CHANNEL", args);
}

void send_response_list_thread(server_t *server, team_t *team, user_t *user)
{
    char *args = NULL;
    size_t args_len = 0;
    char *timestamp = NULL;

    if (server == NULL || team == NULL || thread == NULL)
        return;
    timestamp = time_to_string(thread->timestamp);
    if (timestamp == NULL)
        return;
    args_len = strlen(thread->uuid) + strlen(BROADCAST_COLON)
    + strlen(user->uuid) + strlen(BROADCAST_COLON) + strlen(timestamp)
    + strlen(BROADCAST_COLON) + strlen(thread->title) + strlen(BROADCAST_COLON)
    + strlen(thread->message);
    args = malloc(sizeof(char) * (args_len + 1));
    if (args == NULL)
        return;
    memset(args, 0, args_len + 1);
    sprintf(args, "%s:%s:%s:%s:%s", thread->uuid, user->uuid, timestamp,
    thread->title, thread->message);
    send_broadcast_list(server, team, "THREAD", args);
}

void send_response_list_reply(
server_t *server, team_t *team, thread_t *thread, user_t *user)
{
    reply_t *reply = NULL;
    char *args = NULL;
    size_t args_len = 0;

    if (server == NULL || team == NULL || thread == NULL
    || thread->replies == NULL)
        return;
    reply = get_list_i_data(thread->replies, thread->replies->len - 1);
    if (reply == NULL)
        return;
    args_len = strlen(team->uuid) + strlen(BROADCAST_COLON)
    + strlen(thread->uuid) + strlen(BROADCAST_COLON) + strlen(user->uuid)
    + strlen(BROADCAST_COLON) + strlen(reply->content);
    args = malloc(sizeof(char) * (args_len + 1));
    if (args == NULL)
        return;
    memset(args, 0, args_len + 1);
    sprintf(
    args, "%s:%s:%s:%s", team->uuid, thread->uuid, user->uuid, reply->content);
    send_broadcast_list(server, team, "REPLY", args);
}
