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
__attribute__((unused)) const char *code,
__attribute__((unused))char **args)
{
    if (client->context->channel_valid != VALID_CTX) {
        client_error_unknown_channel(client->context->channel_uuid);
    }
    if (client->context->channel_valid == INVALID_CTX)
        return true;
    return false;
}
