/*
** EPITECH PROJECT, 2023
** free_token
** File description:
** free_token
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void free_tokens(char **tokens)
{
    if (tokens == NULL) {
        return;
    }
    for (size_t i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
