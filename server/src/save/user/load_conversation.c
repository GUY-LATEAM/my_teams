/*
** EPITECH PROJECT, 2023
** load_user
** File description:
** load_user
*/

#include "save_struck.h"

static bool copy_conversation_info(conversation_t *conv, char **conv_info)
{
    if (conv_info == NULL || conv_info[0] == NULL || conv_info[1] == NULL) {
        return false;
    }
    strcpy(conv->uuid_create, conv_info[0]);
    conv->timestamp = string_to_time(conv_info[1]);

    return conv->timestamp != -1;
}

static conversation_t *create_conversation(char **conv_info, const char sep)
{
    conversation_t *conv = NULL;

    conv = malloc(sizeof(conversation_t));
    if (conv == NULL) {
        return NULL;
    }
    if (copy_conversation_info(conv, conv_info) == false) {
        free(conv);
        return NULL;
    }
    conv->messages = create_message_list_from_line(conv_info[2], sep);
    if (conv->messages == NULL) {
        free(conv);
        return NULL;
    }
    return conv;
}

static conversation_t *create_conversation_from_line(char *conv_info,
const char sep)
{
    char **splitted = NULL;
    conversation_t *conv = NULL;

    splitted = str_split(conv_info, sep);
    if (splitted == NULL) {
        return NULL;
    }
    conv = create_conversation(splitted, sep + 1);
    if (conv == NULL) {
        free(splitted);
        return NULL;
    }
    free(splitted);
    return conv;
}

static list_ptr_t *create_conversation_list(char **tab_conv, const char sep)
{
    list_ptr_t *conv = NULL;
    conversation_t *conv_info = NULL;

    conv = list_create();
    if (conv == NULL) {
        return NULL;
    }
    for (int i = 0; tab_conv[i] != NULL; i++) {
        if (tab_conv[i] == NULL)
            return NULL;
        conv_info = create_conversation_from_line(tab_conv[i], sep);
        if ((conv_info == NULL) || (conv_info->messages == NULL) ||
        list_add_last(conv, conv_info) == false) {
            return NULL;
        }
    }
    return conv;
}

list_ptr_t *create_conversation_list_from_line(char *conv_info, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *conv = NULL;

    splitted = str_split(conv_info, sep);
    if (splitted == NULL) {
        return NULL;
    }
    conv = create_conversation_list(splitted, sep + 1);
    if (conv == NULL) {
        free(splitted);
        return NULL;
    }
    free(splitted);
    return conv;
}
