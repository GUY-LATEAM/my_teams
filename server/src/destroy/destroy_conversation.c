/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_conversation
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_conversation(conversation_t *conversation)
{
    if (!conversation)
        return;
    for (int i = 0; i < conversation->messages->len; i++)
        destroy_message(get_list_i_data(conversation->messages, i));
    free(conversation);
}
