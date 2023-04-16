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
,char **args, int *nb_args)
{
    if (!client->context->team_valid && !client->context->channel_valid
    && !client->context->thread_valid)
        client->requested_cmd = INFO_USER;
    if (client->context->team_valid && !client->context->channel_valid
    && !client->context->thread_valid)
        client->requested_cmd = INFO_TEAM;
    if (client->context->team_valid && client->context->channel_valid
    && !client->context->thread_valid)
        client->requested_cmd = INFO_CHANNEL;
    if (client->context->team_valid && client->context->channel_valid
    && client->context->thread_valid)
        client->requested_cmd = INFO_THREAD;
    add_context_to_args(client, args, nb_args);
}