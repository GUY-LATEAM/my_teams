/*
** EPITECH PROJECT, 2023
** login_utils.c
** File description:
** login_utils.c
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

bool is_user_login(server_t *server, const char *name)
{
    user_t *user = NULL;

    for (int i = 0; i < server->all_users->len; i++) {
        user = get_list_i_data(server->all_users, i);
        if (strcmp(user->name, name) == 0) {
            return true;
        }
    }
    return false;
}

int check_is_user_login(server_t *server, user_t *user,
circular_buffer_t *write_buffer)
{
    if (user == NULL || is_user_login(server, user->name) != true) {
        write_error(write_buffer, "401", "Unauthorized: The client needs to\
authenticate before performing this action.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
