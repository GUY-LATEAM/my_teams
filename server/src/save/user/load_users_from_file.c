/*
** EPITECH PROJECT, 2023
** save_users_to_file
** File description:
** save_users_to_file
*/

#include "save_struck.h"

bool load_users_from_file(list_ptr_t *users, const char *filename)
{
    FILE *file = NULL;
    char sep = 1;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for saving users");
        return false;
    }
    if (load_user_loop(users, file, sep) == false ||
    (fclose(file) != EXIT_SUCCESS)) {
        return false;
    }
    return true;
}
