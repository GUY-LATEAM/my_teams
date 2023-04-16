/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_response
*/

#include <string.h>
#include <stdbool.h>
#include "logging_client.h"
#include "parse_logic.h"

static bool is_user_found(char *status, char *code, char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "404") == 0)
        return true;
    return false;
}

bool check_unknown_user_cmd(char *status, char *code, char **args)
{
    if (is_user_found(status, code, args)) {
        client_error_unknown_user(args[0]);
        return true;
    }
    return false;
}