/*
** EPITECH PROJECT, 2023
** load_user
** File description:
** load_user
*/

#include "save_struck.h"

static bool copy_message_info(message_t *message, char **message_info)
{
    if (message == NULL || message_info == NULL ||
    message_info[0] == NULL || message_info[1] == NULL ||
    message_info[2] == NULL) {
        return false;
    }
    strcpy(message->uuid, message_info[0]);
    strcpy(message->content, message_info[1]);
    message->timestamp = string_to_time(message_info[2]);
    if (message->timestamp == -1) {
        return false;
    }
    return true;
}

static message_t *create_message(char **message_info)
{
    message_t *message = NULL;

    message = malloc(sizeof(message_t));
    if (message == NULL) {
        return NULL;
    }
    if (copy_message_info(message, message_info) == false) {
        free(message);
        return NULL;
    }
    return message;
}

static message_t *create_message_from_line(char *message_info, const char sep)
{
    char **splitted = NULL;
    message_t *message = NULL;

    splitted = str_split(message_info, sep);
    if (splitted == NULL) {
        return NULL;
    }
    message = create_message(splitted);
    if (message == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return message;
}

static list_ptr_t *create_message_list(char **tab_message, const char sep)
{
    list_ptr_t *messages = NULL;
    message_t *message = NULL;

    messages = list_create();
    if (messages == NULL) {
        return NULL;
    }
    for (int i = 0; tab_message[i] != NULL; i++) {
        message = create_message_from_line(tab_message[i], sep);
        if ((message == NULL) ||
        (list_add_last(messages, message) != LIST_OK)) {
            destroy_list(messages);
            return NULL;
        }
    }
    return messages;
}

list_ptr_t *create_message_list_from_line(char *message_info, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *messages = NULL;

    splitted = str_split(message_info, sep);
    if (splitted == NULL) {
        return list_create();
    }
    messages = create_message_list(splitted, sep + 1);
    if (messages == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return messages;
}
