/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_channel
*/

#include "list_lib.h"
#include "my_teams_server.h"

void destroy_reply(reply_t *reply)
{
    if (!reply)
        return;
    free(reply);
}
