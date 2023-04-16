/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribe_command
*/

#include <string.h>
#include "libstr.h"
#include "commands.h"
#include "circular_buffer.h"
#include "my_teams_server.h"
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
    char **tmp = str_to_word_array(args, "\"");
    char *arg_team_uuid = NULL;
    team_t *team = NULL;

    if (!tmp) {
        return EXIT_FAILURE;
    }
    if (my_arrlen(tmp) != 1) {
        destroy_array(tmp);
        return EXIT_FAILURE;
    }
    arg_team_uuid = tmp[0];
    team = get_team_by_uuid(arg_team_uuid, ((server_t *) user_data)->teams);
    if (!team) {
        destroy_array(tmp);
        return EXIT_FAILURE;
    }
    list_add_last(team->subscribed_users, ((user_t *) protocol_data)->uuid);
    destroy_array(tmp);
    return EXIT_SUCCESS;
}

static void send_response(circular_buffer_t *write_buffer)
{
    write_circular_buffer(write_buffer, OK_200 SP GUY);
}

static void send_error(circular_buffer_t *write_buffer, char *raw_args)
{
    char **args = str_to_word_array(raw_args, "\"");

    write_circular_buffer(write_buffer, ERROR_404 SP);
    if (args && my_arrlen(args) == 1) {
        write_circular_buffer(write_buffer, args[0]);
    }
    destroy_array(args);
    write_circular_buffer(write_buffer, GUY);
}

int subscribe_command(void *user_data, void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    if (subscribe_user(user_data, protocol_data, args) == EXIT_SUCCESS) {
        send_response(write_buffer);
    } else {
        send_error(write_buffer, args);
    }
    return EXIT_SUCCESS;
}
