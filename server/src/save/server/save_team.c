/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

bool save_sub_user_loop(list_ptr_t *users, FILE *file)
{
    user_t *user = NULL;

    for (int i = 0; i < users->len; i++) {
        user = get_list_i_data(users, i);
        if (fprintf(file, "%s,", user->uuid) < 0) {
            return false;
        }
    }
    return true;
}

bool save_team(team_t *team, FILE *file)
{
    char *timestamp = NULL;

    timestamp = time_to_string(team->timestamp);
    if (timestamp == NULL)
        return false;
    if (fprintf(file, "%s;%s;%s;%s;", team->uuid,
    team->name,team->description, timestamp) < 0) {
        free(timestamp);
        return false;
    }
    if (save_sub_user_loop(team->subscribed_users, file) == false)
        return false;
    if (fprintf(file, ";") < 0) {
        free(timestamp);
        return false;
    }
    if (save_channel_loop(team->channels, file) == false)
        return false;
    free(timestamp);
    return true;
}

bool save_team_loop(list_ptr_t *teams, FILE *file)
{
    team_t *team = NULL;

    for (int i = 0; i < teams->len; i++) {
        team = get_list_i_data(teams, i);
        if ((save_team(team, file) == false) ||
        (fprintf(file, "\n") < 0)) {
            fclose(file);
            return false;
        }
    }
    return true;
}
