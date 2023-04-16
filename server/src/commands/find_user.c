/*
** EPITECH PROJECT, 2023
** find_user.c
** File description:
** find_user.c
*/

#include <string.h>
#include "my_teams_server.h"

user_t *find_user(server_t *server, char *uuid)
{
    user_t *user = NULL;

    for (int i = 0; i < server->all_users->len; i++) {
        user = get_list_i_data(server->all_users, i);
        if (strcmp(user->uuid, uuid) == 0) {
            return user;
        }
    }
    return NULL;
}
