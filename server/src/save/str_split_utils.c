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

size_t count_tokens(char *str, const char separator)
{
    size_t count = 0;
    char *token = NULL;
    char sep[2] = {separator, '\0'};

    token = strtok(str, sep);
    while (token != NULL) {
        count++;
        token = strtok(NULL, sep);
    }
    return count;
}

char **malloc_tokens(size_t count)
{
    char **tokens = NULL;

    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        perror("Error allocating memory for tokens");
    }
    return tokens;
}

void fill_tokens(char **tokens, char *str, const char separator,
size_t count)
{
    char *token = NULL;
    char sep[2] = {separator, '\0'};

    token = strtok(str, sep);
    for (size_t i = 0; i < count && token != NULL; i++) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            perror("Error duplicating token");
        }
        token = strtok(NULL, sep);
    }
    tokens[count] = NULL;
}

static char *duplicate_string(const char *str)
{
    char *dup = NULL;

    if (str == NULL) {
        return NULL;
    }
    dup = strdup(str);
    if (dup == NULL) {
        perror("Error duplicating string");
    }
    return dup;
}

bool duplication_string(char *line, char **str, char **tmp)
{
    *str = duplicate_string(line);
    *tmp = duplicate_string(line);
    if (*str == NULL) {
        return false;
    }
    if (*tmp == NULL) {
        free(*str);
        return false;
    }
    return true;
}
