/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_info_thread_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "libstr.h"
#include "broadcast_misc.h"
#include "client_func.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_info_thread(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unknown_cmd(status, code, users_args)
    || check_unauthorized_cmd(status, code, users_args)
    || check_unknown_team_cmd(client, status, code, users_args)
    || check_unknown_channel_cmd(client, status, code, users_args)
    || check_unknown_thread_cmd(client, status, code, users_args))
        return;
    if ((my_arrlen(users_args) - 1) % 5 != 0)
        return;
    for (int i = 0; users_args[i + 1]; i += 5)
        client_print_thread(users_args[i], users_args[i + 1],
        string_to_time(users_args[i + 2]),
        users_args[i + 3], users_args[i + 4]);
    destroy_array(users_args);
}
