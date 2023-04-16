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
#include "client_func.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_logout(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;
    network_client_t *cli = NULL;

    status = get_status(args);
    args = args + strlen(status) + 1;
    code = get_code(args);
    args = args + strlen(code) + 1;
    users_args = get_argument_parse(args);
    if (check_unauthorized_cmd(status, code, users_args))
        return;
    cli = get_list_i_data(client->network_client->clients, 0);
    destroy_network_client(cli);
    SET_SIGNAL_FLAG(SIGINT_RECEIVED);
}