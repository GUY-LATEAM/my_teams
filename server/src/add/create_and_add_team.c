/*
** EPITECH PROJECT, 2023
** create_and_add
** File description:
** create_and_add
*/

#include "add_struct.h"
#include "init_struct.h"
#include "list_lib.h"

team_t *create_and_add_team(server_t *server, char *name, char *description)
{
    team_t *team = NULL;

    team = init_team(name, description);
    if (team) {
        list_add_last(server->teams, team);
    }
    return team;
}
