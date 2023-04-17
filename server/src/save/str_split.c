/*
** EPITECH PROJECT, 2023
** str_split.c
** File description:
** str_split.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "save_struck.h"

char **str_split(char *line, const char separator)
{
    char **result = NULL;
    size_t count = 0;
    char *str = NULL;
    char *tmp = NULL;

    if (!duplication_string(line, &str, &tmp))
        return NULL;
    count = count_tokens(tmp, separator);
    free(tmp);
    result = malloc_tokens(count);
    if (result == NULL) {
        free(str);
        return NULL;
    }
    fill_tokens(result, str, separator, count);
    free(str);
    return result;
}
