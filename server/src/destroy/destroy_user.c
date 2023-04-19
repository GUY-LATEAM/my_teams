/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_users
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_user(user_t *user)
{
    if (!user)
        return;
    for (int i = 0; i < user->conversations->len; i++)
        destroy_conversation(get_list_i_data(user->conversations, i));
    free_list_no_data(user->conversations);
    free(user);
}
