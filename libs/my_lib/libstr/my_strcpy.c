/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Write a function that copies a string into another.
*/

#include <stddef.h>

char *my_strcpy(char *dest , char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
