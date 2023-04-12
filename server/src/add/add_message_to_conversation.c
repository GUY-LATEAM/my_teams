/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "add_struct.h"
#include "list_lib.h"

bool add_message_to_conversation(conversation_t *conversation, message_t *message)
{
    if (!conversation || !message) {
        return false;
    }
    list_add_last(conversation->messages, message);
    return true;
}
