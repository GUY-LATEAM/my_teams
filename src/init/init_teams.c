/*
** EPITECH PROJECT, 2023
** init_team
** File description:
** init_team
*/

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include "list_lib.h"
#include "my_teams.h"

team_t *init_team(char *name, char *description)
{
    team_t *team = malloc(sizeof(team_t));
    uuid_t uuid;

    if (!team)
        return NULL;

    uuid_generate(uuid);
    uuid_unparse(uuid, team->uuid);
    strncpy(team->name, name, MAX_NAME_LENGTH);
    team->name[MAX_NAME_LENGTH] = '\0';
    strncpy(team->description, description, MAX_DESCRIPTION_LENGTH);
    team->description[MAX_DESCRIPTION_LENGTH] = '\0';
    team->subscribed_users = list_create();
    team->channels = list_create();
    team->users = list_create();
    return team;
}
