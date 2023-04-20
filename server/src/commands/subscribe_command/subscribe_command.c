/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribe_command
*/

#include <stdio.h>
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
    team = get_team_by_uuid(tmp[0], ((server_t *) protocol_data)->teams);
    if (!team
    || list_add_last(team->subscribed_users, ((user_t *) user_data)->uuid)
    != EXIT_SUCCESS) {
        destroy_array(tmp);
        return EXIT_FAILURE;
    }
    destroy_array(tmp);
    return EXIT_SUCCESS;
}

static void broadcast_subscribe_user(
void *user_data, void *protocol_data, team_t *team)
{
    size_t len_message = 0;
    char *message = NULL;

    len_message += strlen(SUBSCRIBED_BROADCAST SP "\"");
    len_message += strlen(((user_t *) user_data)->uuid);
    len_message += strlen(":");
    len_message += strlen(team->uuid);
    len_message += strlen("\"" GUY);
    message = malloc(sizeof(char) * (len_message + 1));
    if (!message)
        return;
    sprintf(message, SUBSCRIBED_BROADCAST SP "\"%s:%s\"" GUY,
    ((user_t *) user_data)->uuid, team->uuid);
    broadcast_teams(protocol_data, team, message);
    free(message);
}

static void write_subscribe_response(user_t *user_data, char *team_uuid,
    circular_buffer_t *write_buffer)
{
    write_circular_buffer(write_buffer, "OK 200 ");
    write_circular_buffer(write_buffer, user_data->uuid);
    write_circular_buffer(write_buffer, ":");
    write_circular_buffer(write_buffer, team_uuid);
    write_circular_buffer(write_buffer, GUY);
}

int subscribe_command(void *user_data, void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    char *team_uuid = get_subscribe_team_uuid(args);

    if (check_is_user_login(protocol_data,
    user_data, write_buffer) == EXIT_FAILURE ||
        is_already_subscribed(((user_t *) user_data)->uuid,
        team_uuid, ((server_t *) protocol_data)->teams))
        return EXIT_FAILURE;
    if (subscribe_user(user_data, protocol_data, args) == EXIT_SUCCESS) {
        server_event_user_subscribed(
        ((user_t *) user_data)->uuid, team_uuid);
        broadcast_subscribe_user(user_data, protocol_data,
        get_team_by_uuid(team_uuid, ((server_t *) protocol_data)->teams));
        write_subscribe_response(user_data, team_uuid, write_buffer);
    } else
        write_error(write_buffer, CODE_404, args);
    free(team_uuid);
    return EXIT_SUCCESS;
}
