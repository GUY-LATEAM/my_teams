/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** disconnect_func
*/

#include <stdio.h>
#include "my_teams_server.h"
#include "network_structures.h"

void on_disconnect_server(void *user_data,
__attribute__((unused)) void *protocol_data,
on_disconnect_error_t error_code)
{
    user_t *user = NULL;

    if (user_data != NULL) {
        user = user_data;
        user->nb_users--;
    }
    if (error_code == SOCKET_ERROR) {
        printf("Broken pipe Socket Error\n");
    }
}
