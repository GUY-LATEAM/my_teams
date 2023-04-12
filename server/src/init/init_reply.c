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

reply_t *init_reply(user_t *user, char *content)
{
    reply_t *rep = NULL;

    rep = malloc(sizeof(reply_t));
    if (!rep)
        return NULL;
    memset(rep->uuid, 0, MAX_UUID_LENGTH);
    memset(rep->content, 0, MAX_BODY_LENGTH + 1);
    strncpy(rep->content, content, MAX_BODY_LENGTH);
    rep->content[MAX_BODY_LENGTH] = '\0';
    rep->user = user;
    rep->timestamp = time(NULL);
    return rep;
}
