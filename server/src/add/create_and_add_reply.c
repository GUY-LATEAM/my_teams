/*
** EPITECH PROJECT, 2023
** create_and_add
** File description:
** create_and_add
*/

#include "add_struct.h"
#include "init_struct.h"
#include "list_lib.h"

reply_t *create_and_add_reply(thread_t *thread, user_t *user, char *content)
{
    reply_t *reply = NULL;

    reply = init_reply(user->uuid, content);
    if (reply) {
        list_add_last(thread->replies, reply);
    }
    return reply;
}
