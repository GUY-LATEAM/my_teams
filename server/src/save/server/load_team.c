/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"

static bool create_team_annexe(team_t *team, char **splitted, const char sep)
{
    team->subscribed_users = create_user_list_from_line(splitted[3], sep);
    if (team->subscribed_users == NULL) {
        free(team);
        return false;
    }
    team->channels = create_channel_list_from_line(splitted[4], sep);
    if (team->channels == NULL) {
        free(team);
        return false;
    }
    return true;
}

static bool copy_team_info(team_t *team, char **team_info)
{
    if (team_info == NULL || team_info[0] == NULL || team_info[1] == NULL ||
        team_info[2] == NULL || team_info[3] == NULL) {
        return false;
    }
    strcpy(team->uuid, team_info[0]);
    strcpy(team->name, team_info[1]);
    strcpy(team->description, team_info[2]);
    team->timestamp = string_to_time(team_info[3]);
    return team->timestamp != -1;
}

static team_t *create_team(char **splitted, const char sep)
{
    team_t *team = NULL;

    team = malloc(sizeof(team_t));
    if (team == NULL) {
        return NULL;
    }
    if (copy_team_info(team, splitted) == false) {
        free(team);
        return NULL;
    }
    if (create_team_annexe(team, splitted, sep) == false) {
        return NULL;
    }
    return team;
}

static team_t *create_team_from_line(char *line, const char sep)
{
    char **splitted = NULL;
    team_t *team = NULL;

    splitted = str_split(line, sep);
    if (splitted == NULL) {
        return NULL;
    }
    team = create_team(splitted, sep + 1);
    if (team == NULL) {
        free(splitted);
        return NULL;
    }
    free(splitted);
    return team;
}

bool load_teams_loop(list_ptr_t *teams, FILE *file, const char sep)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    team_t *team = NULL;

    while ((read = getline(&line, &len, file)) != -1) {
        team = create_team_from_line(line, sep);
        if (team == NULL || list_add_last(teams, team) == false) {
            return false;
        }
    }
    return true;
}
