/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribe_command
*/

#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "logging_server.h"
#include "protocol_logic.h"

static team_t *get_team_by_uuid(char *team_uuid, list_ptr_t *teams)
{
    team_t *team = NULL;

    for (int i = 0; i < teams->len; i++) {
        team = get_list_i_data(teams, i);
        if (strcmp(team_uuid, team->uuid) == 0) {
            return team;
        }
    }
    return NULL;
}

static int subscribe_user(void *user_data, void *protocol_data, char *args)
{
    char **tmp = NULL;
    team_t *team = NULL;

    tmp = str_to_word_array(args, "\"");
    if (!tmp)
        return EXIT_FAILURE;
    if (my_arrlen(tmp) != 1) {
        destroy_array(tmp);
        return EXIT_FAILURE;
    }
    team = get_team_by_uuid(tmp[0], ((server_t *) user_data)->teams);
    if (!team
    || list_add_last(team->subscribed_users, ((user_t *) protocol_data)->uuid)
    != EXIT_SUCCESS) {
        destroy_array(tmp);
        return EXIT_FAILURE;
    }
    destroy_array(tmp);
    return EXIT_SUCCESS;
}

static char *get_subscribe_team_uuid(char *args)
{
    char **tmp = NULL;
    char *uuid = NULL;

    tmp = str_to_word_array(args, "\"");
    if (!tmp)
        return NULL;
    if (my_arrlen(tmp) != 1) {
        destroy_array(tmp);
        return NULL;
    }
    uuid = strdup(tmp[0]);
    destroy_array(tmp);
    return uuid;
}

static void broadcast_subscribe_user(
void *user_data, void *protocol_data, char *team_uuid)
{
    broadcast_teams(user_data, protocol_data, SUBSCRIBED_BROADCAST SP "\"");
    broadcast_teams(user_data, protocol_data, ((user_t *) protocol_data)->uuid);
    broadcast_teams(user_data, protocol_data, ":");
    broadcast_teams(user_data, protocol_data, team_uuid);
    broadcast_teams(user_data, protocol_data, "\"" GUY);
}

int subscribe_command(void *user_data, void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    char *team_uuid = get_subscribe_team_uuid(args);

    if (subscribe_user(user_data, protocol_data, args) == EXIT_SUCCESS) {
        server_event_user_subscribed(
        ((user_t *) protocol_data)->uuid, team_uuid);
        broadcast_subscribe_user(user_data, protocol_data, team_uuid);
        write_success(write_buffer, CODE_200, "SUCCESS");
    } else {
        write_error(write_buffer, CODE_404, args);
    }
    free(team_uuid);
    return EXIT_SUCCESS;
}
