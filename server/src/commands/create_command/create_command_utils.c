/*
** EPITECH PROJECT, 2023
** server
** File description:
** create_command_utils
*/

#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "context_getter.h"
#include "init_struct.h"
#include "logging_server.h"

int create_team(
server_t *server, __attribute__((unused)) user_t *user, char **args)
{
    team_t *team = NULL;
    int args_len = 0;

    if (server == NULL || args == NULL) {
        return EXIT_FAILURE;
    }
    args_len = my_arrlen(args);
    if (args_len != 5)
        return EXIT_FAILURE;
    if (is_team_already_exist(server->teams, args[args_len - 2]))
        return ALREADY_EXIST;
    team = init_team(args[args_len - 2], args[args_len - 1]);
    if (team == NULL) {
        return EXIT_FAILURE;
    }
    server_event_team_created(team->uuid, team->name, user->uuid);
    send_broadcast_new_teams(server, team);
    return list_add_last(server->teams, team);
}

static team_t *get_team_from_create(
server_t *server, __attribute__((unused)) user_t *user, char **args)
{
    int args_len = 0;
    team_t *team = NULL;
    char *user_uuid = NULL;

    if (server == NULL || args == NULL) {
        return NULL;
    }
    args_len = my_arrlen(args);
    if (args_len != 5) {
        return NULL;
    }
    team = get_team_by_uuid(server->teams, args[0]);
    for (int i = 0; i < team->subscribed_users->len; i++) {
        user_uuid = get_list_i_data(team->subscribed_users, i);
        if (strcmp(user_uuid, user->uuid) == 0) {
            return team;
        }
    }
    return NULL;
}

int create_channel(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    int args_len = 0;

    team = get_team_from_create(server, user, args);
    if (team == NULL) {
        return FORBIDDEN;
    }
    args_len = my_arrlen(args);
    if (is_channel_already_exist(team->channels, args[args_len - 2])) {
        return ALREADY_EXIST;
    }
    channel = init_channel(user->uuid, args[args_len - 2], args[args_len - 1]);
    if (channel == NULL) {
        return EXIT_FAILURE;
    }
    server_event_channel_created(team->uuid, channel->uuid, channel->name);
    send_broadcast_new_channel(server, team, channel);
    return list_add_last(team->channels, channel);
}

int create_thread(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;
    int args_len = 0;

    if ((team = get_team_from_create(server, user, args)) == NULL)
        return FORBIDDEN;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    args_len = my_arrlen(args);
    if (is_thread_already_exist(channel->threads, args[args_len - 2]))
        return ALREADY_EXIST;
    thread = init_thread(user->uuid, args[args_len - 2], args[args_len - 1]);
    if (thread == NULL)
        return EXIT_FAILURE;
    server_event_thread_created(
    channel->uuid, thread->uuid, user->uuid, thread->title, thread->message);
    send_broadcast_new_thread(server, team, thread, user);
    return list_add_last(channel->threads, thread);
}

int create_reply(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;
    reply_t *reply = NULL;

    if (my_arrlen(args) != 4)
        return EXIT_FAILURE;
    if ((team = get_team_by_uuid(server->teams, args[0])) == NULL)
        return FORBIDDEN;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    if ((thread = get_thread_by_uuid(channel->threads, args[2])) == NULL)
        return EXIT_FAILURE;
    if ((reply = init_reply(user->uuid, args[my_arrlen(args) - 1])) == NULL)
        return EXIT_FAILURE;
    list_add_last(thread->replies, reply);
    server_event_reply_created(thread->uuid, user->uuid, reply->content);
    send_broadcast_new_reply(server, team, thread, user);
    return EXIT_SUCCESS;
}
