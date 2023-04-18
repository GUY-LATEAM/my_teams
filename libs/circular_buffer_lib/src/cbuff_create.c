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
    char *dup_data = NULL;
    int len_data = 0;

    len_data = strlen(data);
    dup_data = malloc(sizeof(char) * (len_data + 1));
    strcpy(dup_data, data);
    dup_data[len_data] = '\0';
    list_add_last(cbuff->buffer, dup_data);
    return true;
}
