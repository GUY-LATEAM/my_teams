/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool copy_channel_info(channel_t *channel, char **channel_info)
{
    if (channel_info == NULL || channel_info[0] == NULL ||
    channel_info[1] == NULL || channel_info[2] == NULL ||
    channel_info[3] == NULL || channel_info[4] == NULL) {
        return false;
    }
    strcpy(channel->uuid, channel_info[0]);
    strcpy(channel->name, channel_info[1]);
    strcpy(channel->description, channel_info[2]);
    strcpy(channel->uuid_create, channel_info[3]);
    channel->timestamp = string_to_time(channel_info[4]);
    return channel->timestamp != -1;
}

static channel_t *create_channel(char **tab_info, const char sep)
{
    channel_t *channel = NULL;

    channel = malloc(sizeof(channel_t));
    if (channel == NULL) {
        return NULL;
    }
    if (!copy_channel_info(channel, tab_info)) {
        free(channel);
        return NULL;
    }
    channel->threads = create_thread_list_from_line(tab_info[5], sep);
    if (channel->threads == NULL) {
        free(channel);
        return NULL;
    }
    return channel;
}

static channel_t *create_channel_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    channel_t *channel = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    channel = create_channel(splitted, sep + 1);
    if (channel == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return channel;
}

static list_ptr_t *create_channel_list(char **tab_info, const char sep)
{
    list_ptr_t *channels = NULL;
    channel_t *channel = NULL;

    channels = list_create();
    if (channels == NULL) {
        return NULL;
    }
    for (int i = 0; tab_info[i] != NULL; i++) {
        channel = create_channel_from_line(tab_info[i], sep);
        if (channel == NULL || list_add_last(channels, channel) != LIST_OK) {
            destroy_list(channels);
            return NULL;
        }
    }
    return channels;
}

list_ptr_t *create_channel_list_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *channels = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    channels = create_channel_list(splitted, sep + 1);
    if (channels == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return channels;
}
