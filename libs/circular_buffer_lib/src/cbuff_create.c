/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** circular_circular_buffer
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circular_buffer.h"

circular_buffer_t *create_circular_buffer(size_t size, char *pattern)
{
    circular_buffer_t *cbuff = NULL;

    cbuff = malloc(sizeof(circular_buffer_t));
    if (!cbuff)
        return NULL;
    cbuff->buffer = calloc(size, sizeof(char));
    if (!cbuff->buffer) {
        free(cbuff);
        return NULL;
    }
    cbuff->size = size;
    cbuff->end_pattern = strdup(pattern);
    return cbuff;
}

bool write_circular_buffer(circular_buffer_t *cbuff, char *data)
{
    if (strlen(data) > get_available_space_circular_buffer(cbuff))
        return false;
    strcat(cbuff->buffer + cbuff->cursor_write, data);
    cbuff->cursor_write = (cbuff->cursor_write + strlen(data)) % cbuff->size;
    return true;
}
