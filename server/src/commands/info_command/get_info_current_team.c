/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** get_info_current_team
*/

#include <string.h>
#include "libstr.h"
#include "commands.h"
#include "my_teams_server.h"
#include "protocol_logic.h"

team_t *get_team_by_context(char **context, server_t *serv)
{
    team_t *tmp_team = NULL;

    for (int i = 0; i < serv->teams->len; i++) {
        tmp_team = get_list_i_data(serv->teams, i);
        if (strcmp(tmp_team->uuid, context[0]) == 0)
            return tmp_team;
    }
    return NULL;
}

bool is_context_team(char **context)
{
    if (my_arrlen(context) != 3)
        return false;
    if (strcmp(context[0], "UN") != 0
    && strcmp(context[1], "UN") == 0
    && strcmp(context[2], "UN") == 0) {
        return true;
    }
    return false;
}

void send_info_current_team(server_t *serv, char **context,
circular_buffer_t *write)
{
    team_t *team_ctx = NULL;

    team_ctx = get_team_by_context(context, serv);
    if (!team_ctx)
        return;
    write_circular_buffer(write, "OK");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "200");
    write_circular_buffer(write, SP);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, team_ctx->uuid);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, team_ctx->name);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, team_ctx->description);
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, GUY);
}
