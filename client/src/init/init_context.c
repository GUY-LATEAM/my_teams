/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_context
*/

#include <string.h>
#include "my_teams_client.h"

context_t *init_context(void)
{
    context_t *context = malloc(sizeof(context_t));

    if (!context)
        return NULL;
    memset(context, 0, sizeof(context_t));
    return context;
}
