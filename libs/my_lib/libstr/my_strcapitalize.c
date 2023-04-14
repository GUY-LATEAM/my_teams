/*
** EPITECH PROJECT, 2021
** my_str_capitalize
** File description:
** capitalize str
*/

#include <stddef.h>

char *my_strcapitalize(char *str)
{
    if (str == NULL) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
