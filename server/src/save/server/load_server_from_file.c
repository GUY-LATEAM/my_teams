/*
** EPITECH PROJECT, 2023
** load_server
** File description:
** load_server
*/

#include "save_struck.h"

bool load_server_from_file(list_ptr_t *teams, const char *filename)
{
    FILE *file = NULL;
    char sep = 1;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for saving users");
        return false;
    }
    if (load_teams_loop(teams, file, sep) == false ||
    (fclose(file) != EXIT_SUCCESS)) {
        return false;
    }
    return true;
}
