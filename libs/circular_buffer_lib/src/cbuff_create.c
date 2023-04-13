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
    if (data_len > get_available_space_circular_buffer(cbuff))
        return false;

    size_t bytes_to_end = cbuff->size - cbuff->cursor_write;
    if (bytes_to_end >= data_len) {
        memcpy(cbuff->buffer + cbuff->cursor_write, data, data_len);
    } else {
        memcpy(cbuff->buffer + cbuff->cursor_write, data, bytes_to_end);
        memcpy(cbuff->buffer, data + bytes_to_end, data_len - bytes_to_end);
    }
    cbuff->cursor_write = (cbuff->cursor_write + data_len) % cbuff->size;
    return true;
}
