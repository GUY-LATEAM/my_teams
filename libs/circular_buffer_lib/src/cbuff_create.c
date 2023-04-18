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
#include "list_lib.h"
#include "libstr.h"
#include "circular_buffer.h"

circular_buffer_t *create_circular_buffer(size_t size, const char *pattern)
{
    circular_buffer_t *cbuff = NULL;

    cbuff = malloc(sizeof(circular_buffer_t));
    if (!cbuff)
        return NULL;
    cbuff->size = size;
    cbuff->buffer = list_create();
    cbuff->end_pattern = strdup(pattern);
    return cbuff;
}

bool write_circular_buffer(circular_buffer_t *cbuff, const char *data)
{
    int i = 0;
    char *tmp_data = NULL;
    char *ptr = NULL;

    tmp_data = malloc(sizeof(char) * 2);
    memset(tmp_data, 0, 2);
    while (data[i] != '\0') {
        ptr = strstr(data + i, cbuff->end_pattern);
        if (data + i - ptr == 0) {
            list_add_last(cbuff->buffer, strdup(cbuff->end_pattern));
            i += strlen(cbuff->end_pattern);
            continue;
        }
        tmp_data[0] = data[i];
        list_add_last(cbuff->buffer, strdup(tmp_data));
        i++;
    }
    free(tmp_data);
    return true;
}
