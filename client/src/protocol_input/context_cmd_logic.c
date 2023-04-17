/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** context_cmd_logic
*/

#include "stdlib.h"
#include "my_teams_client.h"

static int get_nbr_new_args(context_t *context)
{
    int nb_args = 0;

    if (context->team_valid)
        nb_args += 1;
    if (context->channel_valid)
        nb_args += 1;
    if (context->thread_valid)
        nb_args += 1;
    return (nb_args);
}

void add_context_to_args(client_t *client, char **args, int *nb_args)
{
    char **new_tab = NULL;

    *nb_args += get_nbr_new_args(client->context);
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
