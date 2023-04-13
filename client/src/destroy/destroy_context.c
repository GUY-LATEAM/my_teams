/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_context
*/

#include "destroy_struct.h"

void destroy_context(context_t *context)
{
    if (!context)
        return;
    free(context);
}
