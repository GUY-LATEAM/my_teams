/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool copy_reply_info(reply_t *reply, char **reply_info)
{
    if (reply_info == NULL || reply_info[0] == NULL ||
    reply_info[1] == NULL || reply_info[2] == NULL ||
    reply_info[3] == NULL) {
        return false;
    }
    strcpy(reply->uuid, reply_info[0]);
    strcpy(reply->content, reply_info[1]);
    strcpy(reply->uuid_create, reply_info[2]);
    reply->timestamp = string_to_time(reply_info[3]);
    return reply->timestamp != -1;
}

static reply_t *create_reply(char **splitted)
{
    reply_t *reply = NULL;

    if (splitted == NULL) {
        return NULL;
    }
    reply = malloc(sizeof(reply_t));
    if (reply == NULL) {
        return NULL;
    }
    if (!copy_reply_info(reply, splitted)) {
        free(reply);
        return NULL;
    }
    return reply;
}

static reply_t *create_reply_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    reply_t *reply = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    reply = create_reply(splitted);
    if (reply == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return reply;
}

static list_ptr_t *create_reply_list(char **splitted, const char sep)
{
    list_ptr_t *replies = NULL;
    reply_t *reply = NULL;

    replies = list_create();
    if (replies == NULL) {
        return NULL;
    }
    for (int i = 0; splitted[i] != NULL; i++) {
        reply = create_reply_from_line(splitted[i], sep);
        if ((reply == NULL) || (list_add_last(replies, reply) != LIST_OK)) {
            destroy_list(replies);
            return NULL;
        }
    }
    return replies;
}

list_ptr_t *create_reply_list_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *replies = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return list_create();
    }
    replies = create_reply_list(splitted, sep + 1);
    if (replies == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return replies;
}
