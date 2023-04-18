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

bool is_circular_buffer_empty(circular_buffer_t *cbuff)
{
    if (cbuff->buffer->len > 0)
        return false;
    return true;
}

bool is_circular_buffer_completed(circular_buffer_t *cbuff)
{
    char *data_tmp = NULL;

    for (int i = 0; i < cbuff->buffer->len; i++) {
        data_tmp = get_list_i_data(cbuff->buffer, i);
        if (strstr(data_tmp, cbuff->end_pattern) != NULL) {
            return true;
        }
    }
    return false;
}
