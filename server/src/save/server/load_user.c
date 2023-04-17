/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static list_ptr_t *create_user_list(char **tab_info)
{
    list_ptr_t *users = NULL;

    users = list_create();
    if (users == NULL) {
        return NULL;
    }
    for (int i = 0; tab_info[i] != NULL; i++) {
        if (tab_info[i] == NULL) {
            destroy_list(users);
            return NULL;
        }
        if (list_add_last(users, strdup(tab_info[i])) != LIST_OK) {
            destroy_list(users);
            return NULL;
        }
    }
    return users;
}

list_ptr_t *create_user_list_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *users = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return list_create();
    }
    users = create_user_list(splitted);
    if (users == NULL) {
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return users;
}
