/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_unsubscribe_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

void parse_unsubscribe(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    status = get_status(args);
    args = args + strlen(status) + 1;
    code = get_code(args);
    args = args + strlen(code) + 1;
    users_args = get_argument_parse(args);
    if (check_unauthorized_cmd(status, code, users_args) ||
        check_unknown_team_cmd(client, status, code, users_args))
        return;
    client_print_unsubscribed(users_args[0], users_args[1]);
}
