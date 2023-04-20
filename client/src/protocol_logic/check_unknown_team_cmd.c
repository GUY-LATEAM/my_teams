/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_team_cmd
*/

#include <string.h>
#include <stdbool.h>
#include "my_teams_client.h"
#include "logging_client.h"
#include "parse_logic.h"

bool check_unknown_team_cmd(const client_t *client,
__attribute__((unused)) const char *status,
const char *code, __attribute__((unused)) char **args)
{
    if (strcmp(code, "404") == 0) {
        client_error_unknown_team(client->context->team_uuid);
        return true;
    }
    if (client->context->team_valid != VALID_CTX) {
        client_error_unknown_team(client->context->team_uuid);
    }
    if (client->context->team_valid == INVALID_CTX)
        return true;
    return false;
}
