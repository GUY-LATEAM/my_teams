/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_conversation_to_user(user_t *user, conversation_t *conversation)
{
    if (!user || !conversation) {
        return false;
    }
    list_add_last(user->conversations, conversation);
    return true;
}
