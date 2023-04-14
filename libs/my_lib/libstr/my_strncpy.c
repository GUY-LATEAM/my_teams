/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Write a function that copies n characters from a string into another.
*/

#include <stddef.h>
#include "libstr.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_src = 0;

    if (dest == NULL || src == NULL || n < 0) {
        return NULL;
    }
    len_src = my_strlen(src);
    if (n > len_src) {
        for (; i < len_src; i++) {
            dest[i] = src[i];
        }
    } else {
        for (; i < n; i++) {
            dest[i] = src[i];
        }
    }
    dest[i] = '\0';
    return dest;
}
