/*
** EPITECH PROJECT, 2023
** init_thread
** File description:
** init_thread
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>
#include "list_lib.h"
#include "my_teams_server.h"

thread_t *init_thread(char *user_create, char *title, char *message)
{
    thread_t *thrd = NULL;
    uuid_t uuid;

    thrd = malloc(sizeof(thread_t));
    if (!thrd)
        return NULL;
    uuid_generate(uuid);
    uuid_unparse(uuid, thrd->uuid);
    strncpy(thrd->title, title, MAX_NAME_LENGTH);
    thrd->title[MAX_NAME_LENGTH] = '\0';
    strncpy(thrd->message, message, MAX_BODY_LENGTH);
    thrd->message[MAX_BODY_LENGTH] = '\0';
    strncpy(thrd->uuid_create, user_create, MAX_UUID_LENGTH);
    thrd->uuid_create[MAX_UUID_LENGTH] = '\0';
    thrd->replies = list_create();
    thrd->timestamp = time(NULL);
    return thrd;
}
