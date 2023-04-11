/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_server
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_server(server_t *server)
{
    if (!server)
        return;
    for (int i = 0; i < server->all_users->len; i++)
       destroy_user(get_list_i_data(server->all_users, i));
    for (int i = 0; i < server->teams->len; i++)
        destroy_team(get_list_i_data(server->teams, i));
    free(server);
}