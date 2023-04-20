/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_unknown_func
*/

#include "check_unknown_func.h"

int check_unknown_thread(client_t *client, char *status,
char *code, char **args)
{
    int checked_fail = 0;

    checked_fail += check_unknown_team_cmd(client, status, code, args);
    checked_fail += check_unknown_channel_cmd(client, status, code, args);
    checked_fail += check_unknown_thread_cmd(client, status, code, args);
    if (checked_fail > 0)
        return true;
    return false;
}

int check_unknown_channel(client_t *client, char *status,
char *code, char **args)
{
    int checked_fail = 0;

    checked_fail += check_unknown_team_cmd(client, status, code, args);
    checked_fail += check_unknown_channel_cmd(client, status, code, args);
    if (checked_fail > 0)
        return true;
    return false;
}
