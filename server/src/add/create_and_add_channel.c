/*
** EPITECH PROJECT, 2023
** create_and_add
** File description:
** create_and_add
*/

#include "add_struct.h"
#include "init_struct.h"
#include "list_lib.h"

channel_t *create_and_add_channel(team_t *team, user_t *user, char *name, char *description)
{
    channel_t *channel = NULL;

    channel = init_channel(user, name, description);
    if (channel) {
        list_add_last(team->channels, channel);
    }
    return channel;
}
