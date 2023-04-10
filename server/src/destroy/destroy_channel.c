/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_channel
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_channel(channel_t *channel)
{
    if (!channel)
        return;
    for (int i = 0; i < channel->threads->len; i++)
        destroy_thread(get_list_i_data(channel->threads, i));
    free(channel);
}