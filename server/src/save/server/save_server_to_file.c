/*
** EPITECH PROJECT, 2023
** save_server_to_file
** File description:
** save_server_to_file
*/

#include "save_struck.h"

bool save_server_to_file(list_ptr_t *teams, const char *filename)
{
    FILE *file = NULL;
    char sep = 1;

    if (clear_file_content(filename) == false) {
        return false;
    }
    file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file for saving users");
        return false;
    }
    if (save_team_loop(teams, file, sep) == false || (!fclose(file))) {
        return false;
    }
    return true;
}
