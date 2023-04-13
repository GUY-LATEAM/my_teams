/*
** EPITECH PROJECT, 2023
** save_users_to_file
** File description:
** save_users_to_file
*/

#include "save_struck.h"

bool save_users_to_file(list_ptr_t *users, const char *filename)
{
    FILE *file = NULL;

    if (clear_file_content(filename) == false) {
        return false;
    }
    file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for saving users");
        return false;
    }
    if (save_user_loop(users, file) == false || (!fclose(file))) {
        return false;
    }
    return true;
}
