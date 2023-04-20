/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_bad_team_uuid
*/

#include <string.h>
#include <stdbool.h>
#include "my_teams_client.h"
#include "logging_client.h"
#include "parse_logic.h"

bool check_bad_team_uuid(const client_t *client,
__attribute__((unused)) const char *status,
const char *code, __attribute__((unused)) char **args)
{
    if (strcmp(code, "404") == 0) {
        client_error_unknown_team(client->context->team_uuid);
        return true;
    }
    return false;
}
