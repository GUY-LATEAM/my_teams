/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-romain.panno
** File description:
** is_same_str return 1 if s1 and s2 are the same
*/

#include <stddef.h>

int is_same_str(char *s1, char *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL) {
        return 84;
    }
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    if (s1[i] != '\0' || s2[i] != '\0') {
        return 0;
    } else {
        return 1;
    }
}
