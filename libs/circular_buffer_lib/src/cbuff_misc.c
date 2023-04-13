/*
** EPITECH PROJECT, 2023
** netfwork_lib
** File description:
** cbuff_misc
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circular_buffer.h"

bool is_circular_buffer_full(circular_buffer_t *cbuff)
{
    if (cbuff->cursor_write == cbuff->size - 1)
        return true;
    else
        return false;
}

bool is_circular_buffer_empty(circular_buffer_t *cbuff)
{
    if (cbuff->cursor_read == cbuff->cursor_write && cbuff->cursor_read == 0)
        return true;
    else
        return false;
}

size_t get_available_space_circular_buffer(circular_buffer_t *cbuff)
{
    return cbuff->cursor_read - cbuff->cursor_write + cbuff->size - 1;
}

size_t get_used_space_circular_buffer(circular_buffer_t *cbuff)
{
    return (cbuff->cursor_write - \
    cbuff->cursor_read + cbuff->size) % cbuff->size;
}

bool is_circular_buffer_completed(circular_buffer_t *cbuff)
{
    if (strstr(cbuff->buffer + cbuff->cursor_read, cbuff->end_pattern))
        return true;
    else
        return false;
}
