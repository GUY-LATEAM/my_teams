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

bool is_unauthorized_cmd(char *status, char *code, char **args)
{
    if (strcmp(status, "ERROR") == 0 && strcmp(code, "401") == 0)
        return true;
    return false;
}

bool check_unauthorized_cmd(char *status, char *code, char **args)
{
    if (is_unauthorized_cmd(status, code, args)) {
        client_error_unauthorized();
        return true;
    }
    return false;
}
