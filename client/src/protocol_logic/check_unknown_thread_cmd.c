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

bool check_unknown_thread_cmd(const client_t *client,
__attribute__((unused)) const char *status,
__attribute__((unused)) const char *code, char **args)
{
    if (client->context->thread_valid != VALID_CTX) {
        client_error_unknown_thread(args[0]);
    }
    if (client->context->thread_valid == INVALID_CTX)
        return true;
    return false;
}
