/*
** EPITECH PROJECT, 2023
** server
** File description:
** subscribe_utils
*/

#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "context_getter.h"
#include "logging_server.h"
#include "protocol_logic.h"

char *get_subscribe_team_uuid(char *args)
{
    char **tmp = NULL;
    char *uuid = NULL;

    tmp = str_to_word_array(args, "\"");
    if (!tmp)
        return NULL;
    if (my_arrlen(tmp) != 1) {
        destroy_array(tmp);
        return NULL;
    }
    uuid = strdup(tmp[0]);
    destroy_array(tmp);
    return uuid;
}

bool is_already_subscribed(
char *user_uuid, char *team_uuid, list_ptr_t *team_list)
{
    team_t *team = get_team_by_uuid(team_list, team_uuid);

    if (!team)
        return false;
    for (int i = 0; i < team->subscribed_users->len; i++) {
        if (strcmp(user_uuid, get_list_i_data(team->subscribed_users, i))
        == 0) {
            return true;
        }
    }
    return false;
}
