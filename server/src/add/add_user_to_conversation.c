/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include <string.h>
#include "add_struct.h"
#include "list_lib.h"

bool add_user_to_conversation(conversation_t *conversation, user_t *user)
{
    if (!conversation || !user) {
        return false;
    }
    strcpy(conversation->uuid_create, user->uuid);
    return true;
}
