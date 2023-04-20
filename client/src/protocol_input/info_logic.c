/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribe_logic
*/

#include <string.h>
#include "my_teams_client.h"
#include "init_struct.h"
#include "protocol_logic.h"

void info_logic(client_t *client, __attribute__((unused)) enum cmd_e cmd
,char **args)
{
    if (client->context->team_valid == UNKNOWN_CTX &&
    client->context->channel_valid == UNKNOWN_CTX
    && client->context->thread_valid == UNKNOWN_CTX)
        client->requested_cmd = INFO_USER;
    if (client->context->team_valid != UNKNOWN_CTX
    && client->context->channel_valid == UNKNOWN_CTX
    && client->context->thread_valid == UNKNOWN_CTX)
        client->requested_cmd = INFO_TEAM;
    if (client->context->team_valid != UNKNOWN_CTX
    && client->context->channel_valid != UNKNOWN_CTX
    && client->context->thread_valid == UNKNOWN_CTX)
        client->requested_cmd = INFO_CHANNEL;
    if (client->context->team_valid != UNKNOWN_CTX
    && client->context->channel_valid != UNKNOWN_CTX
    && client->context->thread_valid != UNKNOWN_CTX)
        client->requested_cmd = INFO_THREAD;
    add_context_to_args(client, args);
}
