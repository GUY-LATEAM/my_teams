/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

bool save_channel(channel_t *channel, FILE *file)
{
    char *timestamp = NULL;

    timestamp = time_to_string(channel->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s/%s/%s/%s/%s/", channel->uuid, channel->name,
    channel->description, channel->user_owner->uuid, timestamp) < 0) {
        free(timestamp);
        return false;
    }
    if (save_thread_loop(channel->threads, file) == false) {
        return false;
    }
    free(timestamp);
    return true;
}

bool save_channel_loop(list_ptr_t *channels, FILE *file)
{
    channel_t *channel = NULL;

    for (int i = 0; i < channels->len; i++) {
        channel = get_list_i_data(channels, i);
        if ((save_channel(channel, file) == false) ||
        (fprintf(file, ",") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
