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
#include "my_teams_client.h"

void use_logic(client_t *client, __attribute__((unused)) enum cmd_e cmd,
char **args, __attribute__((unused)) int *nb_args)
{
    int size_array = 0;

    size_array = my_arrlen(args);
    memset(client->context->team_uuid, 0, MAX_UUID_LENGTH);
    memset(client->context->channel_uuid, 0, MAX_UUID_LENGTH);
    memset(client->context->thread_uuid, 0, MAX_UUID_LENGTH);
    client->context->team_valid = UNKNOWN_CTX;
    client->context->channel_valid = UNKNOWN_CTX;
    client->context->thread_valid = UNKNOWN_CTX;
    if (size_array > 0) {
        strcpy(client->context->team_uuid, args[0]);
    }
    if (size_array > 1) {
        strcpy(client->context->channel_uuid, args[1]);
    }
    if (size_array > 2) {
        strcpy(client->context->thread_uuid, args[2]);
    }
    client->requested_cmd = USE;
}
