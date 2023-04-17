/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** get_context
*/

#include <string.h>
#include "my_teams_server.h"

team_t *get_team_by_uuid(list_ptr_t *list_team, char *uuid)
{
    team_t *tmp = NULL;

    for (int i = 0; i < list_team->len; i++) {
        tmp = get_list_i_data(list_team, i);
        if (strcmp(tmp->uuid, uuid) == 0) {
            return tmp;
        }
    }
    return NULL;
}

channel_t *get_channel_by_uuid(list_ptr_t *list_channel, char *uuid)
{
    channel_t *tmp = NULL;

    for (int i = 0; i < list_channel->len; i++) {
        tmp = get_list_i_data(list_channel, i);
        if (strcmp(tmp->uuid, uuid) == 0) {
            return tmp;
        }
    }
    return NULL;
}

thread_t *get_thread_by_uuid(list_ptr_t *list_thread, char *uuid)
{
    thread_t *tmp = NULL;

    for (int i = 0; i < list_thread->len; i++) {
        tmp = get_list_i_data(list_thread, i);
        if (strcmp(tmp->uuid, uuid) == 0) {
            return tmp;
        }
    }
    return NULL;
}
