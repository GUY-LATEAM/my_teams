/*
** EPITECH PROJECT, 2023
** load_user
** File description:
** load_user
*/

#include "save_struck.h"

static bool copy_user_info(user_t *user, char **user_info)
{
    if (user_info == NULL || user_info[0] == NULL || user_info[1] == NULL) {
        return false;
    }
    strcpy(user->uuid, user_info[0]);
    strcpy(user->name, user_info[1]);
    user->timestamp = string_to_time(user_info[2]);

    return user->timestamp != -1;
}

static user_t *create_user(char **user_info, char sep)
{
    user_t *user = NULL;

    user = malloc(sizeof(user_t));
    if (user == NULL) {
        return NULL;
    }
    if (!copy_user_info(user, user_info)) {
        free(user);
        return NULL;
    }
    user->conversations = create_conversation_list_from_line(user_info[3],
    sep);
    if (user->conversations == NULL) {
        free(user);
        return NULL;
    }
    return user;
}

static user_t *create_user_from_line(char *line, char sep)
{
    char **splitted = NULL;
    user_t *user = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    user = create_user(splitted, sep + 1);
    if (user == NULL) {
        return NULL;
    }
    return user;
}

bool load_user_loop(list_ptr_t *users, FILE *file, char sep)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    user_t *user = NULL;

    while ((read = getline(&line, &len, file)) != -1) {
        user = create_user_from_line(line, sep);
        if (user == NULL) {
            return false;
        }
        if (list_add_last(users, user) == false) {
            return false;
        }
    }
    return true;
}
