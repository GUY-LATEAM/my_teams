/*
** EPITECH PROJECT, 2021
** my_str_cat.C
** File description:
** cat str
*/

#include <stddef.h>
#include <stdlib.h>
#include "libstr.h"

char *my_strcat(char *dest, char const *src)
{
    int new_len = 0;
    int indx_res = 0;
    char *res = NULL;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    new_len = my_strlen(dest) + my_strlen(src);
    res = malloc(sizeof(char) * (new_len + 1));
    for (; dest[indx_res] != '\0'; indx_res++) {
        res[indx_res] = dest[indx_res];
    }
    for (int i = 0; src[i] != '\0'; indx_res++, i++) {
        res[indx_res] = src[i];
    }
    res[indx_res] = '\0';
    return res;
}
