/*
** EPITECH PROJECT, 2023
** save_conversation
** File description:
** save_conversation
*/

#include "save_struck.h"

bool save_conversation(conversation_t *conversation, FILE *file)
{
    char *timestamp_str = NULL;

    timestamp_str = time_to_string(conversation->timestamp);
    if (timestamp_str == NULL) {
        return false;
    }
    if (fprintf(file, "%s:%s:", conversation->user->uuid,
    timestamp_str) < 0) {
        free(timestamp_str);
        return false;
    }
    free(timestamp_str);
    if (save_message_loop(conversation->messages, file) == false) {
        return false;
    }
    return true;
}

bool save_conversation_loop(list_ptr_t *conversation, FILE *file)
{
    conversation_t *conv = NULL;

    for (int i = 0; i < conversation->len; i++) {
        conv = get_list_i_data(conversation, i);
        if ((save_conversation(conv, file) == false) ||
        (fprintf(file, ",") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
