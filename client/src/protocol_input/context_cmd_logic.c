/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** context_cmd_logic
*/

#include "stdlib.h"
#include "list_lib.h"
#include "my_teams_client.h"

static void write_context_buffer(circular_buffer_t *write,
char *team, char *channel, char *thread)
{
    write_circular_buffer(write, team);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, channel);
    write_circular_buffer(write, ":");
    write_circular_buffer(write, thread);
    write_circular_buffer(write, ":");
}

static void add_context_to_args_ext(client_t *client,
char **channel, char **thread)
{
    if (client->context->channel_valid == VALID_CTX)
        *channel = client->context->channel_uuid;
    else if (client->context->channel_valid == UNKNOWN_CTX)
        *channel = "UN";
    else
        *channel = "KO";
    if (client->context->thread_valid == VALID_CTX)
        *thread = client->context->thread_uuid;
    else if (client->context->thread_valid == UNKNOWN_CTX)
        *thread = "UN";
    else
        *thread = "KO";
}

void add_context_to_args(client_t *client,
__attribute__((unused)) char **args)
{
    char *team = NULL;
    char *channel = NULL;
    char *thread = NULL;
    network_client_t *cli = NULL;

    cli = get_list_i_data(client->network_client->clients, 0);
    if (!cli)
        return;
    if (client->context->team_valid == VALID_CTX)
        team = client->context->team_uuid;
    else if (client->context->team_valid == UNKNOWN_CTX)
        team = "UN";
    else
        team = "KO";
    add_context_to_args_ext(client, &channel, &thread);
    write_context_buffer(cli->write_buffer, team, channel, thread);
}
