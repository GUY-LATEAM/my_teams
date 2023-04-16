/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_users_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

void parse_users(__attribute__((unused)) client_t *client, char *args)
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
    for (int i = 0; i < my_arrlen(users_args) / 3; i++)
        client_print_users(users_args[i * 3], users_args[i * 3 + 1],
        atoi(users_args[i * 3 + 2]));
}