/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_misc
*/

#ifndef BROADCAST_MISC_H
    #define BROADCAST_MISC_H
    #include <time.h>
    #include <stdlib.h>
    #include "logging_client.h"
    #include "libstr.h"

    typedef struct broadcast_thread_created_s broadcast_thread_created_t;

    struct broadcast_thread_created_s {
        char *thread_uuid;
        char *user_uuid;
        time_t thread_timestamp;
        char *thread_title;
        char *thread_body;
    };

    char **get_char_array_args(char *args);
    broadcast_thread_created_t *get_broadcast_thread_created(char *args);
    int destroy_broadcast_thread_created(
        broadcast_thread_created_t *to_destroy);

#endif /* !BROADCAST_MISC_H */
