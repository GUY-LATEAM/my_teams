/*
** EPITECH PROJECT, 2023
** netfwork_lib
** File description:
** cbuff_destroy
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circular_buffer.h"

size_t read_circular_buffer(circular_buffer_t *cbuff, char *data)
{
    size_t i = 0;
    char *end_pattern = NULL;

    if (is_circular_buffer_empty(cbuff))
        return 0;
    end_pattern = strstr(cbuff->buffer + cbuff->cursor_read,
    cbuff->end_pattern);
    if (end_pattern == NULL)
        end_pattern = strstr(cbuff->buffer, cbuff->end_pattern);
    end_pattern += strlen(cbuff->end_pattern);
    while (cbuff->buffer + cbuff->cursor_read != end_pattern) {
        data[i] = cbuff->buffer[cbuff->cursor_read];
        cbuff->cursor_read = cbuff->cursor_read + 1;
        i++;
        if (cbuff->cursor_read == cbuff->size - 1)
            cbuff->cursor_read = 0;
    }
    return i;
}

void destroy_circular_buffer(circular_buffer_t *cbuff)
{
    if (cbuff) {
        if (cbuff->buffer)
            free(cbuff->buffer);
        if (cbuff->end_pattern)
            free(cbuff->end_pattern);
        free(cbuff);
    }
}

void clear_circular_buffer(circular_buffer_t *cbuff)
{
    memset(cbuff->buffer, 0, cbuff->size);
    cbuff->cursor_read = 0;
    cbuff->cursor_write = 0;
}
