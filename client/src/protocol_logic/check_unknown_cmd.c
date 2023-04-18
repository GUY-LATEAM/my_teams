/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_unknown_cmd
*/

#include <string.h>
#include <stdbool.h>

static bool is_unknown_cmd(const char *status, const char *code,
__attribute__((unused))char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "400") == 0)
        return true;
    return false;
}

bool check_unknown_cmd(const char *status, const char *code, char **args)
{
    if (is_unknown_cmd(status, code, args)) {
        return true;
    }
    return false;
}
