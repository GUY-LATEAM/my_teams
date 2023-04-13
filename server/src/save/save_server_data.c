/*
** EPITECH PROJECT, 2023
** save_server_data.c
** File description:
** save_server_data.c
*/

#include "save_struck.h"

bool save_server_data(server_t *server, const char *users_filename,
const char *teams_filename)
{
    bool users_saved = false;
    bool teams_saved = false;

    users_saved = save_users_to_file(server->all_users, users_filename);
    teams_saved = save_server_to_file(server->teams, teams_filename);
    return users_saved && teams_saved;
}

bool clear_file_content(const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file for clearing");
        return false;
    }

    fclose(file);
    return true;
}
