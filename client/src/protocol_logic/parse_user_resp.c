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

void parse_user(__attribute__((unused)) client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unauthorized_cmd(status, code, users_args)
    || check_unknown_user_cmd(status, code, users_args))
        return;
    if ((my_arrlen(users_args)) % 3 != 0)
        return;
    client_print_user(users_args[0], users_args[1], atoi(users_args[2]));
    destroy_array(users_args);
}
