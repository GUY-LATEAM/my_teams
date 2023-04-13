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
    size_t used_space = get_used_space_circular_buffer(cbuff);

    if (used_space == 0)
        return 0;

    for (size_t i = 0; i < used_space; i++) {
        data[i] = cbuff->buffer[(cbuff->cursor_read + i) % cbuff->size];
    }
    cbuff->cursor_read = (cbuff->cursor_read + used_space) % cbuff->size;
    return used_space;
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
