/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_user_to_team(team_t *team, user_t *user)
{
    if (!team || !user) {
        return false;
    }
    list_add_last(team->subscribed_users, user);
    return true;
}
