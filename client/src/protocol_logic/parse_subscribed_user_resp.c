/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_subscribe_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

void parse_subscribed_user(__attribute__((unused)) client_t *client,
char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_unknown_team_cmd(client, status, code, users_args))
        return;
    if ((my_arrlen(users_args) - 1) % 3 != 0)
        return;
    for (int i = 0; users_args[i + 1]; i += 3)
        client_print_users(users_args[i], users_args[i + 1],
        atoi(users_args[i + 2]));
    destroy_array(users_args);
}
