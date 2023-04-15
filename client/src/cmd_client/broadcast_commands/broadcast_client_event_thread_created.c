/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_client_event_thread_created
*/

#include "broadcast_misc.h"

int broadcast_client_event_thread_created(char *raw_args)
{
    broadcast_thread_created_t *thread_created = NULL;
    int result = 0;

    if (raw_args == NULL) {
        return EXIT_FAILURE;
    }
    thread_created = get_broadcast_thread_created(raw_args);
    if (thread_created == NULL) {
        return EXIT_FAILURE;
    }
    result = client_event_thread_created(thread_created->thread_uuid,
    thread_created->user_uuid, thread_created->thread_timestamp,
    thread_created->thread_title, thread_created->thread_body);
    destroy_broadcast_thread_created(thread_created);
    return result;
}
