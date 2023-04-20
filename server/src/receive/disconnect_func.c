/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** disconnect_func
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_teams_server.h"
#include "network_structures.h"
#include "commands.h"
#include "protocol_logic.h"

static void broad_cast_logout(user_t *user, server_t *serv)
{
    char *message = NULL;

    if (user == NULL || serv == NULL)
        return;
    message = malloc(sizeof(char)
    * (strlen(user->uuid)
    + (strlen(user->name) + (strlen(GUY)) + strlen(LOGOUT_BROADCAST)
    + strlen(BROADCAST_MARK) + strlen(BROADCAST_COLON) + 1)));
    if (message == NULL)
        return;
    if (sprintf(
        message, "broadcast LOGOUT \"%s:%s\"%s", user->uuid, user->name, GUY)
    < 0)
    broadcast_all_user(serv, message);
    free(message);
}

void on_disconnect_server(void *user_data,
void *protocol_data,
on_disconnect_error_t error_code)
{
    user_t *user = NULL;

    if (user_data != NULL) {
        user = user_data;
        user->nb_users--;
        broad_cast_logout(user, protocol_data);
    }
    if (error_code == SOCKET_ERROR)
        printf("Broken pipe Socket Error\n");
}
