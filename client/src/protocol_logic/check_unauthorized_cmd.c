/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_response
*/

#include <string.h>
#include <stdbool.h>
#include "my_teams_client.h"
#include "logging_client.h"
#include "parse_logic.h"

bool is_unauthorized_cmd(const char *status, const char *code,
__attribute__((unused)) const char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "401") == 0)
        return true;
    return false;
}

bool check_unauthorized_cmd(const char *status, const char *code, const char **args)
{
    if (is_unauthorized_cmd(status, code, args)) {
        client_error_unauthorized();
        return true;
    }
    return false;
}
