/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_teams
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_team(team_t *team)
{
    if (!team)
        return;
    for (int i = 0; i < team->channels->len; i++)
        destroy_channel(get_list_i_data(team->channels, i));
    free_list_no_data(team->channels);
    free(team);
}
