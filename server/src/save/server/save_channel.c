/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool save_channel(channel_t *channel, FILE *file, const char sep)
{
    char *timestamp = NULL;

    timestamp = time_to_string(channel->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s%c%s%c%s%c%s%c%s%c", channel->uuid, sep,
    channel->name, sep, channel->description, sep, channel->uuid_create,
    sep, timestamp, sep) < 0) {
        free(timestamp);
        return false;
    }
    if (save_thread_loop(channel->threads, file, sep + 1) == false) {
        return false;
    }
    free(timestamp);
    return true;
}

bool save_channel_loop(list_ptr_t *channels, FILE *file, const char sep)
{
    channel_t *channel = NULL;

    for (int i = 0; i < channels->len; i++) {
        channel = get_list_i_data(channels, i);
        if ((save_channel(channel, file, sep + 1) == false) ||
        (fprintf(file, "%c", sep) < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
