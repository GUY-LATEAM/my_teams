/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_already_exist_cmd
*/

#include <string.h>
#include <stdbool.h>
#include "logging_client.h"
#include "parse_logic.h"

static bool is_already_exist(const char *status, const char *code,
__attribute__((unused)) char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "409") == 0)
        return true;
    return false;
}

bool check_already_exist_cmd(const char *status, const char *code, char **args)
{
    if (is_already_exist(status, code, args)) {
        client_error_already_exist();
        return true;
    }
    return false;
}
