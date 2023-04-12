/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

bool save_thread(thread_t *thread, FILE *file)
{
    char *timestamp = NULL;

    timestamp = time_to_string(thread->timestamp);
    if (timestamp == NULL) {
        return false;
    }
    if (fprintf(file, "%s_%s_%s_%s_%s_", thread->uuid, thread->title,
    thread->message, thread->user->uuid, timestamp) < 0) {
        free(timestamp);
        return false;
    }
    if (save_reply_loop(thread->replies, file) == false) {
        free(timestamp);
        return false;
    }
    free(timestamp);
    return true;
}

bool save_thread_loop(list_ptr_t *threads, FILE *file)
{
    thread_t *thread = NULL;

    for (int i = 0; i < threads->len; i++) {
        thread = get_list_i_data(threads, i);
        if ((save_thread(thread, file) == false) ||
        (fprintf(file, "|") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
