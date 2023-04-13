/*
** EPITECH PROJECT, 2023
** save_conversation
** File description:
** save_conversation
*/

#include "save_struck.h"

static bool save_conversation(conversation_t *conversation, FILE *file,
const char sep)
{
    char *timestamp_str = NULL;

    timestamp_str = time_to_string(conversation->timestamp);
    if (timestamp_str == NULL) {
        return false;
    }
    if (fprintf(file, "%s%c%s%c", conversation->uuid_create, sep,
    timestamp_str, sep) < 0) {
        free(timestamp_str);
        return false;
    }
    free(timestamp_str);
    if (save_message_loop(conversation->messages, file, sep + 1) == false) {
        return false;
    }
    return true;
}

bool save_conversation_loop(list_ptr_t *conversation, FILE *file,
const char sep)
{
    conversation_t *conv = NULL;

    for (int i = 0; i < conversation->len; i++) {
        conv = get_list_i_data(conversation, i);
        if ((save_conversation(conv, file, sep + 1) == false) ||
        (fprintf(file, "%c", sep) < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
