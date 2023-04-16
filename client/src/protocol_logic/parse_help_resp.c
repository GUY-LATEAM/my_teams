/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_info_channel_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "client_func.h"
#include "my_teams_client.h"

void parse_help(client_t *client, char *args)
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
    printf("%s", users_args[0])
}
