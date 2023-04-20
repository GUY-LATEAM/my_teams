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

void parse_subscribe(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_bad_team_uuid(client, status, code, users_args))
        return;
    client_print_subscribed(users_args[0], users_args[1]);
    destroy_array(users_args);
}
