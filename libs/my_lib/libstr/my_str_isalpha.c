/*
** EPITECH PROJECT, 2021
** my_str_is_aplha
** File description:
** str alpha
*/

#include <stddef.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') {
            return 0;
        }
    }
    return 1;
}
