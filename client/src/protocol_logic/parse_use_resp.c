/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_use_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

void parse_use(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    status = get_status(args);
    args = args + strlen(status) + 1;
    code = get_code(args);
    args = args + strlen(code) + 1;
    users_args = get_argument_parse(args);
    if (check_unauthorized_cmd(status, code, users_args))
        return;
    client->context->team_valid = strcmp(&args[0], "OK") == 0 ? true : false;
    client->context->channel_valid = strcmp(&args[1], "OK") == 0 ? true : false;
    client->context->thread_valid = strcmp(&args[2], "OK") == 0 ? true : false;
}