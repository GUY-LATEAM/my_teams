/*
** EPITECH PROJECT, 2023
** save_message
** File description:
** save_message
*/

#include "save_struck.h"

bool save_message(message_t *message, FILE *file)
{
    char *timestamp_str = NULL;

    timestamp_str = time_to_string(message->timestamp);
    if (timestamp_str == NULL) {
        return false;
    }
    if (fprintf(file, "%s^%s^%s", message->uuid, message->content,
    timestamp_str) < 0) {
        free(timestamp_str);
        return false;
    }
    free(timestamp_str);
    return true;
}

bool save_message_loop(list_ptr_t *messages, FILE *file)
{
    message_t *message = NULL;

    for (int i = 0; i < messages->len; i++) {
        message = get_list_i_data(messages, i);
        if ((save_message(message, file) == false) ||
        (fprintf(file, "/") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
