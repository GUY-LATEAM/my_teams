/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** use_logic
*/

#include <string.h>
#include "init_struct.h"
#include "libstr.h"
#include "protocol_logic.h"

void use_logic(client_t *client, enum cmd_e cmd ,char **args,
__attribute__((unused)) int *nb_args)
{
    int size_array = 0;

    size_array = my_arraylen(args);
    memset(client->context->team_uuid, 0, MAX_UUID_LENGTH);
    memset(client->context->channel_uuid, 0, MAX_UUID_LENGTH);
    memset(client->context->thread_uuid, 0, MAX_UUID_LENGTH);
    if (size_array > 0) {
        memcpy(client->context->team_uuid, args[0], MAX_UUID_LENGTH);
    }
    if (size_array > 1) {
        memcpy(client->context->channel_uuid, args[1], MAX_UUID_LENGTH);
    }
    if (size_array > 2) {
        memcpy(client->context->thread_uuid, args[2], MAX_UUID_LENGTH);
    }
    client->requested_cmd = cmd;
}
