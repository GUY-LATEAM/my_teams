/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_message
*/

#include "list_lib.h"
#include "my_teams_server.h"

void destroy_message(message_t *message, char *uuid)
{
    if (!message)
        return;
    if (message->uuid_create == uuid)
        free(message);
}
