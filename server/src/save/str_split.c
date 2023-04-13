/*
** EPITECH PROJECT, 2023
** str_split.c
** File description:
** str_split.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static size_t count_tokens(char *str, const char separator)
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

static char **malloc_tokens(size_t count)
{
    char **tokens = NULL;

    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        perror("Error allocating memory for tokens");
    }
    return tokens;
}

static void fill_tokens(char **tokens, char *str, const char separator,
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

    dup = strdup(str);
    if (dup == NULL) {
        perror("Error duplicating string");
    }
    return dup;
}

char **str_split(char *line, const char separator)
{
    char **result = NULL;
    size_t count = 0;
    char *str = duplicate_string(line);
    char *tmp = duplicate_string(line);

    if (str == NULL || tmp == NULL) {
        free(str);
        free(tmp);
        return NULL;
    }
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
