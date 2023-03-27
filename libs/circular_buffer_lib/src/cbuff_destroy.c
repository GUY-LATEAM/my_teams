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

bool read_circular_buffer(circular_buffer_t *cbuff, char *data)
{
    if (strlen(data) > get_used_space_circular_buffer(cbuff))
        return false;
    strncpy(data, cbuff->buffer + cbuff->cursor_read, strlen(data));
    cbuff->cursor_read = (cbuff->cursor_read + strlen(data)) % cbuff->size;
    return true;
}

void destroy_circular_buffer(circular_buffer_t *cbuff)
{
    if (cbuff) {
        free(cbuff->buffer);
        free(cbuff);
        free(cbuff->end_pattern);
    }
}

void clear_circular_buffer(circular_buffer_t *cbuff)
{
    memset(cbuff->buffer, 0, cbuff->size);
    cbuff->cursor_read = 0;
    cbuff->cursor_write = 0;
}
