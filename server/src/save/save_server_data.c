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

bool load_server_data(server_t *server, const char *users_filename,
const char *teams_filename)
{
    bool users_loaded = false;
    bool teams_loaded = false;

    server->all_users = list_create();
    server->teams = list_create();
    users_loaded = load_users_from_file(server->all_users, users_filename);
    teams_loaded = load_server_from_file(server->teams, teams_filename);
    return users_loaded && teams_loaded;
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

bool is_file_not_empty(const char *filename)
{
    FILE *file = NULL;
    long file_size = 0;

    file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fclose(file);
    if (file_size == 0) {
        return false;
    }
    return true;
}

bool load_file_data(server_t *server, const char *filepath_user,
const char *filepath_server)
{
    if (is_file_not_empty(filepath_user) == false ||
        is_file_not_empty(filepath_server) == false) {
        return true;
    }
    if (load_server_data(server, filepath_user, filepath_server) == false) {
        return false;
    }
    return true;
}
