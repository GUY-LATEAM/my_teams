/*
** EPITECH PROJECT, 2023
** init_user.c
** File description:
** init_user.c
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <uuid/uuid.h>
#include "list_lib.h"
#include "my_teams_server.h"

user_t *init_user(char *name)
{
    user_t *user = NULL;
    uuid_t uuid;

    user = malloc(sizeof(user_t));
    if (!user)
        return NULL;
    uuid_generate(uuid);
    uuid_unparse(uuid, user->uuid);
    memset(user->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(user->name, name, MAX_NAME_LENGTH);
    user->name[MAX_NAME_LENGTH] = '\0';
    user->conversations = list_create();
    user->timestamp = time(NULL);
    return user;
}
