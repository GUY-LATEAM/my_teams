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

    if (!parse_resp(&status, &code, &users_args, args)
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_unknown_team_cmd(client, status, code, users_args))
        return;
    client_print_unsubscribed(users_args[0], users_args[1]);
    destroy_array(users_args);
}
