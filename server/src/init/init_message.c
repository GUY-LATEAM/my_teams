/*
** EPITECH PROJECT, 2023
** init_message.c
** File description:
** init_message.c
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>
#include "my_teams_server.h"

message_t *init_message(char *content, char *create_uuid)
{
    message_t *msg = NULL;
    uuid_t uuid = {0};

    msg = malloc(sizeof(message_t));
    if (!msg)
        return NULL;
    memset(msg->content, 0, MAX_BODY_LENGTH + 1);
    strncpy(msg->content, content, MAX_BODY_LENGTH);
    uuid_generate(uuid);
    uuid_unparse(uuid, msg->uuid);
    strncpy(msg->uuid_create, create_uuid, MAX_UUID_LENGTH);
    msg->uuid_create[MAX_UUID_LENGTH] = '\0';
    msg->content[MAX_BODY_LENGTH] = '\0';
    msg->timestamp = time(NULL);
    return msg;
}
