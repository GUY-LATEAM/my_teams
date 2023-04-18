/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_logout_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "libstr.h"
#include "client_func.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_logout(__attribute__((unused)) client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;


    if (parse_resp(&status, &code, &users_args, args) == false)
        return;
    if (check_unauthorized_cmd(status, code, users_args))
        return;
    SET_SIGNAL_FLAG(SIGINT_RECEIVED);
    destroy_array(users_args);
}
