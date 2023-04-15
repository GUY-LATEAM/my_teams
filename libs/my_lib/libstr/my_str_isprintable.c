/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** same as name
*/

#include <stddef.h>

int my_str_isprintable(char const *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126) {
            return 0;
        }
    }
    return 1;
}
