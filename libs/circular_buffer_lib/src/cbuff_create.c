/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** circular_circular_buffer
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "circular_buffer.h"

circular_buffer_t *create_circular_buffer(size_t size, const char *pattern)
{
    circular_buffer_t *cbuff = NULL;

    cbuff = malloc(sizeof(circular_buffer_t));
    if (!cbuff)
        return NULL;
    cbuff->buffer = malloc(size);
    memset(cbuff->buffer, 0, size);
    if (!cbuff->buffer) {
        free(cbuff);
        return NULL;
    }
    cbuff->size = size;
    cbuff->cursor_read = 0;
    cbuff->cursor_write = 0;
    cbuff->end_pattern = strdup(pattern);
    return cbuff;
}

bool write_circular_buffer(circular_buffer_t *cbuff, const char *data)
{
    size_t data_len = strlen(data);
    size_t i = 0;

    while (i < data_len) {
        if (is_circular_buffer_full(cbuff)) {
            cbuff->cursor_write = 0;
        }
        cbuff->buffer[cbuff->cursor_write] = data[i];
        cbuff->cursor_write = (cbuff->cursor_write + 1) % cbuff->size;
        i++;
    }
    return true;
}
