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

void list_logic(client_t *client, enum cmd_e cmd ,char **args, int *nb_args)
{
    if (client->context->thread_valid)
        client->requested_cmd = LIST_REPLY;
    else if (client->context->channel_valid)
        client->requested_cmd = LIST_THREAD;
    else if (client->context->team_valid)
        client->requested_cmd = LIST_CHANNEL;
    else
        client->requested_cmd = LIST_TEAM;
    add_context_to_args(client, args, nb_args);
}