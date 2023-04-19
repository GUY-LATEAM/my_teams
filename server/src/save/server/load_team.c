/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "save_struck.h"
#include "libstr.h"

static bool create_team_annexe(team_t *team, char **splitted, const char sep)
{
    list_ptr_t *tmp = NULL;

    tmp = create_user_list_from_line(splitted[4], sep);
    if (tmp == NULL) {
        return false;
    }
    if (my_arrlen(splitted) < 5) {
        team->channels = list_create();
        return true;
    }
    team->channels = create_channel_list_from_line(splitted[5], sep);
    if (team->channels == NULL) {
        destroy_list(tmp);
        return false;
    }
    team->subscribed_users = tmp;
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
        free(team);
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
        free_tokens(splitted);
        return NULL;
    }
    free_tokens(splitted);
    return team;
}

bool load_teams_loop(list_ptr_t *teams, FILE *file, const char sep)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    team_t *team = NULL;

    while ((read = getline(&line, &len, file)) != -1) {
        remove_newline(line);
        team = create_team_from_line(line, sep);
        if (team == NULL || list_add_last(teams, team) != LIST_OK) {
            free(line);
            return false;
        }
    }
    free(line);
    return true;
}
