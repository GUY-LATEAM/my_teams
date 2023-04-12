/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_user_to_server(server_t *server, user_t *user)
{
    if (!server || !user) {
        return false;
    }
    list_add_last(server->all_users, user);
    return true;
}
