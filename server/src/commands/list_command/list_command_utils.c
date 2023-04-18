/*
** EPITECH PROJECT, 2023
** server
** File description:
** list_command_utils
*/

#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "context_getter.h"
#include "init_struct.h"
g
int list_team(
server_t *server, __attribute__((unused)) user_t *user, char **args)
{
    int args_len = 0;

    if (server == NULL || args == NULL) {
        return EXIT_FAILURE;
    }
    args_len = my_arrlen(args);
    if (args_len != 3) {
        return EXIT_FAILURE;
    }
    send_response_list_teams(server);
    return EXIT_SUCCESS;
}

static team_t *get_team_from_list(server_t *server, user_t *user, char **args)
{
    int args_len = 0;

    if (server == NULL || args == NULL) {
        return NULL;
    }
    args_len = my_arrlen(args);
    if (args_len != 3) {
        return NULL;
    }
    return get_team_by_uuid(server->teams, args[0]);
}

int list_channel(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    int args_len = 0;

    team = get_team_from_list(server, user, args);
    if (team == NULL) {
        return EXIT_FAILURE;
    }
    send_response_list_channel(server, team);
    return EXIT_SUCCESS;
}

int list_thread(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    int args_len = 0;

    team = get_team_from_list(server, user, args);
    if (team == NULL)
        return EXIT_FAILURE;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    send_response_list_thread(server, team, user);
    return EXIT_SUCCESS;
}

int list_reply(server_t *server, user_t *user, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;

    team = get_team_from_list(server, user, args);
    if (team == NULL)
        return EXIT_FAILURE;
    channel = get_channel_by_uuid(team->channels, args[1]);
    if (channel == NULL)
        return EXIT_FAILURE;
    thread = get_thread_by_uuid(channel->threads, args[2]);
    if (thread == NULL)
        return EXIT_FAILURE;
    send_response_list_reply(server, team, thread, user);
    return EXIT_SUCCESS;
}
