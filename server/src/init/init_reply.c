/*
** EPITECH PROJECT, 2023
** init_reply.c
** File description:
** init_reply.c
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>
#include "my_teams_server.h"

reply_t *init_reply(char *user_create, char *content)
{
    reply_t *rep = NULL;
    uuid_t uuid = {0};

    rep = malloc(sizeof(reply_t));
    if (!rep)
        return NULL;
    memset(rep->content, 0, MAX_BODY_LENGTH + 1);
    strncpy(rep->content, content, MAX_BODY_LENGTH);
    rep->content[MAX_BODY_LENGTH] = '\0';
    uuid_generate(uuid);
    uuid_unparse(uuid, rep->uuid);
    strncpy(rep->uuid_create, user_create, MAX_UUID_LENGTH);
    rep->uuid_create[MAX_UUID_LENGTH] = '\0';
    rep->timestamp = time(NULL);
    return rep;
}
