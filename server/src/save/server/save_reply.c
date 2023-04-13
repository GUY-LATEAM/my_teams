/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

bool save_reply(reply_t *reply, FILE *file)
{
    char *timestamp = NULL;

    timestamp = time_to_string(reply->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s#%s#%s#%s", reply->uuid, reply->content,
    reply->user->uuid, timestamp) < 0) {
        free(timestamp);
        return false;
    }
    free(timestamp);
    return true;
}

bool save_reply_loop(list_ptr_t *replies, FILE *file)
{
    reply_t *reply = NULL;

    for (int i = 0; i < replies->len; i++) {
        reply = get_list_i_data(replies, i);
        if ((save_reply(reply, file) == false) ||
        (fprintf(file, "^") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
