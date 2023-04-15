/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** Reproduce the behavior of the strstrfunction
*/

#include <unistd.h>
#include "libstr.h"

int my_strcmp(char const *s1, char const *s2)
{
    int nbr = 0;

    if (s1 == NULL || s2 == NULL) {
        return -1;
    }
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            nbr = s1[i] - s2[i];
            return nbr;
        }
    }
    return 0;
}
