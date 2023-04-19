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

int create_team(
server_t *server, __attribute__((unused)) user_t *user, char **args)
{
    team_t *team = NULL;
    int args_len = 0;

    if (server == NULL || args == NULL) {
        return EXIT_FAILURE;
    }
    args_len = my_arrlen(args);
    if (args_len != 5) {
        return EXIT_FAILURE;
    }
    team = init_team(args[args_len - 2], args[args_len - 1]);
    if (team == NULL) {
        return EXIT_FAILURE;
    }
    send_broadcast_new_teams(server, team);
    return list_add_last(server->teams, team);
}

static team_t *get_team_from_create(server_t *server, user_t *user, char **args)
{
    int args_len = 0;

    if (server == NULL || args == NULL) {
        return NULL;
    }
    args_len = my_arrlen(args);
    if (args_len != 5) {
        return NULL;
    }
    return get_team_by_uuid(server->teams, args[0]);
}

int create_channel(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    int args_len = 0;

    team = get_team_from_create(server, user, args);
    if (team == NULL) {
        return EXIT_FAILURE;
    }
    args_len = my_arrlen(args);
    channel = init_channel(user->uuid, args[args_len - 2], args[args_len - 1]);
    if (channel == NULL) {
        return EXIT_FAILURE;
    }
    send_broadcast_new_channel(server, team, channel);
    return list_add_last(team->channels, channel);
}

int create_thread(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;
    int args_len = 0;

    team = get_team_from_create(server, user, args);
    if (team == NULL)
        return EXIT_FAILURE;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    args_len = my_arrlen(args);
    thread = init_thread(user->uuid, args[args_len - 2], args[args_len - 1]);
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
    team = get_team_by_uuid(server->teams, args[0]);
    if (team == NULL)
        return EXIT_FAILURE;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    if ((thread = get_thread_by_uuid(channel->threads, args[2])) == NULL)
        return EXIT_FAILURE;
    if ((reply = init_reply(user->uuid, args[my_arrlen(args) - 1])) == NULL)
        return EXIT_FAILURE;
    list_add_last(thread->replies, reply);
    send_broadcast_new_reply(server, team, thread, user);
    return EXIT_SUCCESS;
}
