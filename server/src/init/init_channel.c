/*
** EPITECH PROJECT, 2023
** init_channel
** File description:
** init_channel
*/

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include <time.h>
#include "list_lib.h"
#include "my_teams_server.h"

channel_t *init_channel(char *user_create, char *name, char *description)
{
    channel_t *chan = NULL;
    uuid_t uuid = {0};

    chan = malloc(sizeof(channel_t));
    if (!chan)
        return NULL;
    uuid_generate(uuid);
    uuid_unparse(uuid, chan->uuid);
    strncpy(chan->name, name, MAX_NAME_LENGTH);
    chan->name[MAX_NAME_LENGTH] = '\0';
    strncpy(chan->description, description, MAX_DESCRIPTION_LENGTH);
    chan->description[MAX_DESCRIPTION_LENGTH] = '\0';
    strncpy(chan->uuid_create, user_create, MAX_UUID_LENGTH);
    chan->uuid_create[MAX_UUID_LENGTH] = '\0';
    chan->threads = list_create();
    chan->timestamp = time(NULL);
    return chan;
}
