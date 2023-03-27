/*
** EPITECH PROJECT, 2023
** init_contexte.c
** File description:
** init_contexte
*/

#include <stdlib.h>
#include <string.h>
#include "my_teams.h"

context_t *init_context(void)
{
    context_t *ctx = NULL;

    ctx = malloc(sizeof(context_t));
    if (!ctx)
        return NULL;
    memset(ctx->team_uuid, 0, MAX_UUID_LENGTH);
    memset(ctx->channel_uuid, 0, MAX_UUID_LENGTH);
    memset(ctx->thread_uuid, 0, MAX_UUID_LENGTH);
    return ctx;
}
