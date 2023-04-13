/*
** EPITECH PROJECT, 2023
** save_user
** File description:
** save_user
*/

#include "save_struck.h"

static bool save_user(user_t *user, FILE *file, char sep)
{
    char *timestamp_str = NULL;

    timestamp_str = time_to_string(user->timestamp);
    if (timestamp_str == NULL) {
        return false;
    }
    if (fprintf(file, "%s%c%s%c%s%c", user->uuid, sep, user->name,
    sep,timestamp_str, sep) < 0) {
        free(timestamp_str);
        return false;
    }
    free(timestamp_str);
    if (save_conversation_loop(user->conversations, file, sep + 1) == false) {
        return false;
    }
    return true;
}

bool save_user_loop(list_ptr_t *users, FILE *file, char sep)
{
    user_t *user = NULL;

    for (int i = 0; i < users->len; i++) {
        user = get_list_i_data(users, i);
        if ((save_user(user, file, sep) == false) ||
        (fprintf(file, "\n") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
