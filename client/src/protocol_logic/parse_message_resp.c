/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_message_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "broadcast_misc.h"
#include "my_teams_client.h"

void parse_message(__attribute__((unused)) client_t *client, char *args)
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
    if ((my_arrlen(users_args) - 1) % 3 != 0)
        return;
    for (int i = 0; users_args[i + 1]; i += 3)
        client_private_message_print_messages(users_args[i * 3],
        string_to_time(users_args[2]), users_args[i * 3 + 2]);
    destroy_array(users_args);
}
