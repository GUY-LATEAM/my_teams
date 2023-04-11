/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_contexte
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_contexte(context_t *contexte)
{
    if (!contexte)
        return;
    free(contexte);
}
