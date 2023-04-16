/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_misc
*/

#include <stdio.h>
#include "libstr.h"
#include "broadcast_misc.h"

time_t string_to_time(const char *timestamp_str)
{
    long read_long = 0;
    int result;

    result = sscanf(timestamp_str, "%ld", &read_long);
    if (result != 1) {
        return (time_t)-1;
    }
    return (time_t)read_long;
}

char **get_char_array_args(char *args)
{
    char **result = NULL;
    char **tmp = NULL;

    if (args == NULL)
        return NULL;
    tmp = str_to_word_array(args, "\"");
    if (tmp == NULL) {
        return NULL;
    }
    if (my_arrlen(tmp) != 2) {
        destroy_array(tmp);
        return NULL;
    }
    result = str_to_word_array(tmp[1], ":");
    destroy_array(tmp);
    return result;
}

int destroy_broadcast_thread_created(broadcast_thread_created_t *to_destroy)
{
    if (to_destroy == NULL) {
        return EXIT_FAILURE;
    }
    free(to_destroy->thread_uuid);
    free(to_destroy->user_uuid);
    free(to_destroy->thread_title);
    free(to_destroy->thread_body);
    free(to_destroy);
    return EXIT_SUCCESS;
}

broadcast_thread_created_t *get_broadcast_thread_created(char *args)
{
    broadcast_thread_created_t *result = NULL;
    char **tmp = NULL;

    if (args == NULL) {
        return NULL;
    }
    tmp = get_char_array_args(args);
    if (tmp == NULL || my_arrlen(tmp) != 5) {
        destroy_array(tmp);
        free(result);
        return NULL;
    }
    result = malloc(sizeof(broadcast_thread_created_t));
    result->thread_uuid = tmp[0];
    result->user_uuid = tmp[1];
    result->thread_timestamp = string_to_time(tmp[2]);
    result->thread_title = tmp[3];
    result->thread_body = tmp[4];
    free(tmp);
    return result;
}
