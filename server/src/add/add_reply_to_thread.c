/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_reply_to_thread(thread_t *thread, reply_t *reply)
{
    if (!thread || !reply) {
        return false;
    }
    list_add_last(thread->replies, reply);
    return true;
}
