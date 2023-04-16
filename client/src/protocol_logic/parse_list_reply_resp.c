/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_list_user_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "client_func.h"
#include "libstr.h"
#include "my_teams_client.h"
#include "signal_management_client.h"

void parse_list_reply(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false)
        return;
    if (check_unauthorized_cmd(status, code, users_args)
        || check_unknown_channel_cmd(client, status, code, users_args))
        return;
    if (my_arrlen(users_args) % 4 != 0)
        return;
    for (int i = 0; users_args[i]; i += 4) {
        client_thread_print_replies(users_args[i], users_args[i + 1],
            0, users_args[i + 3]);
    }
}
