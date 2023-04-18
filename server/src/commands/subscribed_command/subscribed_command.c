/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribed_command
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "logging_server.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

int subscribed_command(void *user_data,
void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    server_t *server = NULL;
    user_t *user = NULL;
    char *uuid = NULL;

    server = (server_t *) protocol_data;
    user = (user_t *) user_data;
    if (check_is_user_login(server,
    user, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    uuid = strtok(args, " \"");
    if (uuid == NULL) {
        subscribed_no_argument(server, user, write_buffer);
        return EXIT_SUCCESS;
    }
    if (subscribed_argument(server, uuid, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
