/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** strstr
*/

#include <stddef.h>
#include "libstr.h"

static int is_in_from_i(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (i == 0) {
        return (s1[0] == '\0' && s2[0] == '\0') ? 0 : -1;
    }
    return (s1[i - 1] - s2[i - 1]);
}

int my_strstr(char *str, char const *to_find)
{
    if (str == NULL || to_find == NULL) {
        return -1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_in_from_i(&(str[i]), to_find) == 0)
            return 1;
    }
    if (str[0] == '\0' && to_find[0] == '\0') {
        return 1;
    }
    return 0;
}
