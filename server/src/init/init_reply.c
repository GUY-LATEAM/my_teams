/*
** EPITECH PROJECT, 2023
** init_reply.c
** File description:
** init_reply.c
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_teams_server.h"

reply_t *init_reply(char *user_create, char *content)
{
    reply_t *rep = NULL;

    rep = malloc(sizeof(reply_t));
    if (!rep)
        return NULL;
    memset(rep->uuid, 0, MAX_UUID_LENGTH);
    memset(rep->content, 0, MAX_BODY_LENGTH + 1);
    strncpy(rep->content, content, MAX_BODY_LENGTH);
    rep->content[MAX_BODY_LENGTH] = '\0';
    strncpy(rep->uuid_create, user_create, MAX_UUID_LENGTH);
    rep->uuid_create[MAX_UUID_LENGTH] = '\0';
    rep->timestamp = time(NULL);
    return rep;
}
