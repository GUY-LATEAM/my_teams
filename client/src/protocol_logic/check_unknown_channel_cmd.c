/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_channel_cmd
*/

#include <string.h>
#include <stdbool.h>
#include "my_teams_client.h"
#include "logging_client.h"
#include "parse_logic.h"

bool check_unknown_channel_cmd(const client_t *client,
__attribute__((unused)) const char *status,
__attribute__((unused)) const char *code, char **args)
{
    if (client->context->channel_valid) {
        client_error_unknown_channel(args[0]);
        return true;
    }
    return false;
}
