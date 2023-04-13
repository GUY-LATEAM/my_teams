/*
** EPITECH PROJECT, 2023
** save_user
** File description:
** save_user
*/

#include "save_struck.h"

bool save_user(user_t *user, FILE *file)
{
    char *timestamp_str = NULL;

    timestamp_str = time_to_string(user->timestamp);
    if (timestamp_str == NULL) {
        return false;
    }
    if (fprintf(file, "%s;%s;%s;", user->uuid, user->name,
    timestamp_str) < 0) {
        free(timestamp_str);
        return false;
    }
    free(timestamp_str);
    if (save_conversation_loop(user->conversations, file) == false) {
        return false;
    }
    return true;
}

bool save_user_loop(list_ptr_t *users, FILE *file)
{
    user_t *user = NULL;

    for (int i = 0; i < users->len; i++) {
        user = get_list_i_data(users, i);
        if ((save_user(user, file) == false) ||
        (fprintf(file, "\n") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
