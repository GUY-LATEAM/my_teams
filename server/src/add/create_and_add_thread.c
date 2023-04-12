/*
** EPITECH PROJECT, 2023
** create_and_add
** File description:
** create_and_add
*/

#include "add_struct.h"
#include "init_struct.h"
#include "list_lib.h"

thread_t *create_and_add_thread(channel_t *channel, user_t *user, char *title, char *message)
{
    thread_t *thread = NULL;

    thread = init_thread(user, title, message);
    if (thread) {
        list_add_last(channel->threads, thread);
    }
    return thread;
}
