/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_create_channel_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "libstr.h"
#include "client_func.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_create_channel(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_already_exist_cmd(status, code, users_args)
    || check_unknown_team_cmd(client, status, code, users_args))
        return;
    client_print_channel_created(users_args[0], users_args[1], users_args[2]);
    destroy_array(users_args);
}
