/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** unsubscribe_command
*/

#include <string.h>
#include <stdio.h>
#include "context_getter.h"
#include "my_teams_server.h"
#include "logging_server.h"
#include "commands.h"
#include "protocol_logic.h"
#include "circular_buffer.h"

static void write_success_unsubscribe(circular_buffer_t *write,
char *user, char *team)
{
    write_circular_buffer(write, "OK 200 ");
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, user);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, team);
    write_circular_buffer(write, GUY);
}

static int check_bad_team_uuid(list_ptr_t *teams, char *uuid, team_t **team)
{
    *team = get_team_by_uuid(teams, uuid);
    if (*team == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int unsubscribe_user(user_t *client,
team_t *team)
{
    char *tmp_uuid = NULL;

    for (int i = 0; i < team->subscribed_users->len; i++) {
        tmp_uuid = get_list_i_data(team->subscribed_users, i);
        if (strcmp(tmp_uuid, client->uuid) == 0) {
            remove_list_element(team->subscribed_users, i);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

static void broadcast_unsubscribe_user(
void *user_data, void *protocol_data, team_t *team)
{
    size_t len_message = 0;
    char *message = NULL;

    len_message += strlen(UNSUBSCRIBED_BROADCAST SP "\"");
    len_message += strlen(((user_t *) user_data)->uuid);
    len_message += strlen(":");
    len_message += strlen(team->uuid);
    len_message += strlen("\"" GUY);
    message = malloc(sizeof(char) * (len_message + 1));
    if (!message)
        return;
    sprintf(message, UNSUBSCRIBED_BROADCAST SP "\"%s:%s\"" GUY,
    ((user_t *) user_data)->uuid, team->uuid);
    broadcast_teams(protocol_data, team, message);
    free(message);
}

int unsubscribe_command(void *user_data,
void *protocol_data, char *args, circular_buffer_t *write_buffer)
{
    server_t *serv = NULL;
    team_t *team = NULL;
    char *uuid = NULL;

    if (check_is_user_login(protocol_data,
    user_data, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    serv = protocol_data;
    uuid = strtok(args, ":\""SP);
    if (check_bad_team_uuid(serv->teams, uuid,
    &team) == EXIT_SUCCESS && unsubscribe_user(user_data, team)
    == EXIT_SUCCESS) {
        server_event_user_unsubscribed(team->uuid, ((user_t *)user_data)->uuid);
        broadcast_unsubscribe_user(user_data, protocol_data, team);
        write_success_unsubscribe(write_buffer, ((user_t *)
        user_data)->uuid, team->uuid);
    } else
        write_error(write_buffer, CODE_404, args);
    return EXIT_SUCCESS;
}
