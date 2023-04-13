/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool save_thread(thread_t *thread, FILE *file, const char sep)
{
    char *timestamp = NULL;

    timestamp = time_to_string(thread->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s%c%s%c%s%c%s%c%s%c", thread->uuid, sep, thread->title,
    sep, thread->message, sep, thread->uuid_create, sep, timestamp, sep) < 0) {
        free(timestamp);
        return false;
    }
    if (save_reply_loop(thread->replies, file, sep + 1) == false) {
        free(timestamp);
        return false;
    }
    free(timestamp);
    return true;
}

bool save_thread_loop(list_ptr_t *threads, FILE *file, const char sep)
{
    thread_t *thread = NULL;

    for (int i = 0; i < threads->len; i++) {
        thread = get_list_i_data(threads, i);
        if ((save_thread(thread, file, sep + 1) == false) ||
        (fprintf(file, "%c", sep) < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
