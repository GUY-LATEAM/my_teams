/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-baptiste.laran
** File description:
** my_split_left
*/

#include <stdlib.h>
#include "stddef.h"

int check_char(char dest, char *ref);

int my_split_left_len(char *ref, char *mark)
{
    int i = 0;

    for (; ref[i] != '\0' && check_char(ref[i], mark) == 0; i++);
    return i;
}

char *my_split_left(char *ref, char *mark)
{
    int len = 0;
    char *result = NULL;
    int indx = 0;

    if (ref == NULL) {
        return NULL;
    }
    len = my_split_left_len(ref, mark);
    result = malloc(sizeof(char) * (len + 1));
    for (; ref[indx] != '\0' && check_char(ref[indx], mark) == 0; indx++) {
        result[indx] = ref[indx];
    }
    result[indx] = '\0';
    return result;
}
