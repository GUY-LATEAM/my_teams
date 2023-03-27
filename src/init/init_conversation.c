/*
** EPITECH PROJECT, 2023
** init_conversation
** File description:
** init_conversation
*/

#include <stdlib.h>
#include <string.h>
#include "list_lib.h"
#include "my_teams.h"

conversation_t *init_conversation(user_t *user)
{
    conversation_t *conv = NULL;

    conv = malloc(sizeof(conversation_t));
    if (!conv)
        return NULL;
    conv->user = user;
    conv->messages = list_create();
    return conv;
}