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

void create_logic(client_t *client, enum cmd_e cmd ,char **args, int *nb_args)
{
    if (!client->context->team_valid && !client->context->channel_valid && !client->context->thread_valid)
        client->requested_cmd = CREATE_TEAM;
    if (client->context->team_valid && !client->context->channel_valid && !client->context->thread_valid)
        client->requested_cmd = CREATE_CHANNEL;
    if (client->context->team_valid && client->context->channel_valid && !client->context->thread_valid)
        client->requested_cmd = CREATE_THREAD;
    if (client->context->team_valid && client->context->channel_valid && client->context->thread_valid)
        client->requested_cmd = CREATE_REPLY;
    add_context_to_args(client, args, nb_args);
}