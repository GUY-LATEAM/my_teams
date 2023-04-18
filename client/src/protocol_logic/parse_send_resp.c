/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_send_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "protocol_logic.h"
#include "my_teams_client.h"

void parse_send(__attribute__((unused)) client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_unknown_user_cmd(status, code, users_args))
        return;
    destroy_array(users_args);
}
