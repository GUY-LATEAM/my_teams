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

    if (is_circular_buffer_empty(cbuff))
        return 0;
    while (cbuff->cursor_read != cbuff->cursor_write) {
        data[i] = cbuff->buffer[cbuff->cursor_read];
        cbuff->cursor_read = (cbuff->cursor_read + 1) % cbuff->size;
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
