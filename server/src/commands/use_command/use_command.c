/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** use_command
*/

#include <string.h>
#include "context_getter.h"
#include "my_teams_server.h"
#include "circular_buffer.h"
#include "commands.h"
#include "protocol_logic.h"
#include "libstr.h"

static void resolve_context_thread(channel_t *channel, char **args,
char *context, bool *bad_context)
{
    thread_t *thread = NULL;

    if (my_arrlen(args) <= 2) {
        strcat(context, "UN");
        return;
    } else {
        thread = get_thread_by_uuid(channel->threads, args[2]);
        if (thread == NULL) {
            strcat(context, "KO");
            *bad_context = true;
            return;
        }
        strcat(context, "OK");
    }
}

static void resolve_context_channel(team_t *team, char **args, char *context,
bool *bad_context)
{
    channel_t *channel = NULL;

    if (my_arrlen(args) <= 1) {
        strcat(context, "UN:UN");
        return;
    } else {
        channel = get_channel_by_uuid(team->channels, args[1]);
        if (channel == NULL) {
            strcat(context, "KO:KO");
            *bad_context = true;
            return;
        }
        strcat(context, "OK:");
        resolve_context_thread(channel, args, context, bad_context);
    }
}

static void resolve_context_team(server_t *server, char **args, char *context,
bool *bad_context)
{
    team_t *team = NULL;

    if (args[0] == NULL) {
        strcat(context, "UN:UN:UN");
        return;
    } else {
        team = get_team_by_uuid(server->teams, args[0]);
        if (team == NULL) {
            strcat(context, "KO:KO:KO");
            *bad_context = true;
            return;
        } else {
            strcat(context, "OK:");
            resolve_context_channel(team, args, context, bad_context);
        }
    }
}

static char *resolve_reponse_context(server_t *server, char **args)
{
    char buffer_resp[24] = {0};
    char context[9] = {0};
    bool bad_context = false;

    resolve_context_team(server, args, context, &bad_context);
    if (bad_context)
        strcat(buffer_resp, "ERROR 404 ");
    else
        strcat(buffer_resp, "OK 200 ");
    strcat(buffer_resp, context);
    strcat(buffer_resp, GUY);
    return strdup(buffer_resp);
}

int use_command(__attribute__((unused)) void *user_data,
void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    server_t *server = NULL;
    char **args_parse = NULL;
    char *response_context = NULL;

    server = (server_t *) protocol_data;
    if (check_is_user_login(server,
    (user_t *) user_data, write_buffer) == true)
        return EXIT_SUCCESS;
    args_parse = str_to_word_array(args, "\" :");
    response_context = resolve_reponse_context(server, args_parse);
    if (response_context == NULL)
        return EXIT_SUCCESS;
    write_circular_buffer(write_buffer, response_context);
    free(response_context);
    return EXIT_SUCCESS;
}
