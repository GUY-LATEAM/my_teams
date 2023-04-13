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
        if (tab_info[i] == NULL)
            return NULL;
        if (list_add_last(users, tab_info[i]) == false)
            return NULL;
    }
    return users;
}

list_ptr_t *create_user_list_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    list_ptr_t *users = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    users = create_user_list(splitted);
    if (users == NULL) {
        free(splitted);
        return NULL;
    }
    free(splitted);
    return users;
}
