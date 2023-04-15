/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** use_logic
*/

#include <string.h>
#include "init_struct.h"
#include "protocol_logic.h"

void use_logic(client_t *client, char **args)
{
    memcpy(client->context->team_uuid, args[0], MAX_UUID_LENGTH);
    memcpy(client->context->channel_uuid, args[1], MAX_UUID_LENGTH);
    memcpy(client->context->thread_uuid, args[2], MAX_UUID_LENGTH);
}
