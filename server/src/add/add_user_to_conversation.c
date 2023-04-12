/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_user_to_conversation(conversation_t *conversation, user_t *user)
{
    if (!conversation || !user) {
        return false;
    }
    conversation->user = user;
    return true;
}
