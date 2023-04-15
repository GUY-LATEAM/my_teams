/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool copy_thread_info(thread_t *thread, char **thread_info)
{
    if (thread_info == NULL || thread_info[0] == NULL ||
        thread_info[1] == NULL || thread_info[2] == NULL ||
        thread_info[3] == NULL || thread_info[4] == NULL) {
        return false;
    }
    strcpy(thread->uuid, thread_info[0]);
    strcpy(thread->title, thread_info[1]);
    strcpy(thread->message, thread_info[2]);
    strcpy(thread->uuid_create, thread_info[3]);
    thread->timestamp = string_to_time(thread_info[4]);
    return thread->timestamp != -1;
}

static thread_t *create_thread(char **splitted, const char sep)
{
    thread_t *thread = NULL;

    thread = malloc(sizeof(thread_t));
    if (thread == NULL) {
        return NULL;
    }
    if (!copy_thread_info(thread, splitted)) {
        free(thread);
        return NULL;
    }
    thread->replies = create_reply_list_from_line(splitted[5], sep);
    if (thread->replies == NULL) {
        free(thread);
        return NULL;
    }
    return thread;
}

static thread_t *create_thread_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    thread_t *thread = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    thread = create_thread(splitted, sep + 1);
    if (thread == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return thread;
}

static list_ptr_t *create_thread_list(char **tab_thread, const char sep)
{
    list_ptr_t *threads = NULL;
    thread_t *thread = NULL;

    threads = list_create();
    if (threads == NULL)
        return NULL;
    for (int i = 0; tab_thread[i] != NULL; i++) {
        thread = create_thread_from_line(tab_thread[i], sep);
        if (list_add_last(threads, thread) != LIST_OK) {
            destroy_list(threads);
            return NULL;
        }
    }
    return threads;
}

list_ptr_t *create_thread_list_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *threads = NULL;

    if (line == NULL) {
        return NULL;
    }
    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    threads = create_thread_list(splitted, sep + 1);
    if (threads == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return threads;
}
