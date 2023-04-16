/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** context_cmd_logic
*/

#include "stdlib.h"
#include "my_teams_client.h"

void add_context_to_args(client_t *client, char **args, int *nb_args)
{
    char **new_tab;
    if (client->context->team_valid)
        *nb_args += 1;
    if (client->context->channel_valid)
        *nb_args += 1;
    if (client->context->thread_valid)
        *nb_args += 1;
    new_tab = realloc(args, sizeof(char *) * (*nb_args + 1));
    if (!new_tab)
        return;
    args = new_tab;
    if (client->context->team_valid)
        args[*nb_args] = client->context->team_uuid;
    if (client->context->channel_valid)
        args[*nb_args] = client->context->channel_uuid;
    if (client->context->thread_valid)
        args[*nb_args] = client->context->thread_uuid;
}
