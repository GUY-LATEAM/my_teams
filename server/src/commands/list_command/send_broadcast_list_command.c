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

void send_broadcast_list(circular_buffer_t *write_buffer, list_ptr_t *args_list)
{
    char *args = NULL;

    if (args_list == NULL || write_buffer == NULL) {
        return;
    }
    write_circular_buffer(write_buffer, RESPONSE "200" SP BROADCAST_MARK);
    for (int i = 0; i < args_list->len; i++) {
        args = get_list_i_data(args_list, i);
        if (args == NULL)
            continue;
        write_circular_buffer(write_buffer, args);
        write_circular_buffer(write_buffer, BROADCAST_COLON);
    }
    write_circular_buffer(write_buffer, BROADCAST_MARK GUY);
}

static void loop_reponse_list_team(
server_t *server, list_ptr_t *teams_list, int i)
{
    team_t *team = NULL;
    size_t args_len = 0;
    char *args = NULL;

    team = get_list_i_data(server->teams, i);
    args_len = strlen(team->uuid) + strlen(BROADCAST_COLON) + strlen(team->name)
    + strlen(BROADCAST_COLON) + strlen(team->description);
    args = malloc(sizeof(char) * (args_len + 1));
    if (args != NULL) {
        memset(args, 0, args_len + 1);
        sprintf(args, "%s:%s:%s", team->uuid, team->name, team->description);
        list_add_last(teams_list, args);
    }
}

void send_response_list_teams(server_t *server, circular_buffer_t *write_buffer)
{
    list_ptr_t *teams_list = NULL;

    teams_list = list_create();
    if (server == NULL || teams_list == NULL)
        return;
    for (int i = 0; i < server->teams->len; i++) {
        loop_reponse_list_team(server, teams_list, i);
    }
    send_broadcast_list(write_buffer, teams_list);
    destroy_list(teams_list);
}
