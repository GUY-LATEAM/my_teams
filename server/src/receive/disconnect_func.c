/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** disconnect_func
*/

#include <stdio.h>
#include "network_structures.h"

void on_disconnect_server(__attribute__((unused)) void *user_data,
__attribute__((unused)) void *protocol_data,
on_disconnect_error_t error_code)
{
    if (error_code == SOCKET_ERROR) {
        printf("Broken pipe Socket Error\n");
    }
}
