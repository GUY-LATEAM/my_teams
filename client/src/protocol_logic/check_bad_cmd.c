/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_bad_cmd
*/

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

static bool is_bad(const char *status, const char *code,
__attribute__((unused)) char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "404") == 0)
        return true;
    return false;
}

bool check_bad_cmd(const char *status, const char *code,
char **args)
{
    if (is_bad(status, code, args)) {
        return true;
    }
    return false;
}
