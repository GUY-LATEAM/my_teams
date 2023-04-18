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
    char *tmp_data = NULL;
    size_t read_size = 0;
    int i = 0;

    for (i = 0; i < cbuff->buffer->len; i++) {
        tmp_data = get_list_i_data(cbuff->buffer, i);
        strcat(data, tmp_data);
        read_size += strlen(tmp_data);
        if (strstr(tmp_data, cbuff->end_pattern) != NULL) {
            i++;
            break;
        }
    }
    for (int j = 0; j < i; j++) {
        tmp_data = get_list_i_data(cbuff->buffer, 0);
        remove_list_element(cbuff->buffer, 0);
        free(tmp_data);
    }
    return read_size;
}

void destroy_circular_buffer(circular_buffer_t *cbuff)
{
    char *tmp_data = NULL;

    if (!cbuff)
        return;
    for (int i = 0; i < cbuff->buffer->len; i++) {
        tmp_data = get_list_i_data(cbuff->buffer, i);
        free(tmp_data);
    }
    for (int i = 0; i < cbuff->buffer->len; i++) {
        remove_list_element(cbuff->buffer, i);
    }
    free(cbuff->buffer);
    free(cbuff->end_pattern);
    free(cbuff);
}

