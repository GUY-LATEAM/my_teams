/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** same as strcmp but with n
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nbr = 0;

    if (s1 == NULL || s2 == NULL) {
        return -1;
    }
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i]) {
            nbr = s1[i] - s2[i];
            return nbr;
        }
    }
    return 0;
}
