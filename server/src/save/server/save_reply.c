/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool save_reply(reply_t *reply, FILE *file, const char sep)
{
    char *timestamp = NULL;

    timestamp = time_to_string(reply->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s%c%s%c%s%c%s", reply->uuid, sep, reply->content,
    sep, reply->uuid_create, sep, timestamp) < 0) {
        free(timestamp);
        return false;
    }
    free(timestamp);
    return true;
}

bool save_reply_loop(list_ptr_t *replies, FILE *file, const char sep)
{
    reply_t *reply = NULL;

    for (int i = 0; i < replies->len; i++) {
        reply = get_list_i_data(replies, i);
        if ((save_reply(reply, file, sep + 1) == false) ||
        (fprintf(file, "%c", sep) < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
