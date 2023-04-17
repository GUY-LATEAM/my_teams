/*
** EPITECH PROJECT, 2023
** init_message.c
** File description:
** init_message.c
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_teams_server.h"

message_t *init_message(char *content)
{
    message_t *msg = NULL;

    msg = malloc(sizeof(message_t));
    if (!msg)
        return NULL;
    memset(msg->content, 0, MAX_BODY_LENGTH + 1);
    strncpy(msg->content, content, MAX_BODY_LENGTH);
    msg->content[MAX_BODY_LENGTH] = '\0';
    memset(msg->uuid, 0, MAX_UUID_LENGTH);
    msg->timestamp = time(NULL);
    return msg;
}
