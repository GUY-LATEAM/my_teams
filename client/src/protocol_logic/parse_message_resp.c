/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_message_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

void parse_message(__attribute__((unused)) client_t *client, char *args)
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
    check_unknown_user_cmd(status, code, users_args))
        return;
    for (int i = 0; i < my_arrlen(users_args) / 3; i++)
        client_private_message_print_messages(users_args[i * 3], 0,
        users_args[i * 3 + 2]);
}