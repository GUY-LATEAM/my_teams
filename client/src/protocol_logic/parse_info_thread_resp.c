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
#include "client_func.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_info_thread(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false)
        return;
    if (check_unauthorized_cmd(status, code, users_args)
        || check_unknown_channel_cmd(client, status, code, users_args))
        return;
    if (my_arrlen(users_args) % 5 != 0)
        return;
    for (int i = 0; users_args[i]; i += 5)
        client_print_thread(users_args[i], users_args[i + 1], 0,
        users_args[i + 3], users_args[i + 4]);
    destroy_array(users_args);
}
