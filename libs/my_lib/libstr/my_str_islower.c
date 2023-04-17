/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** return if str is lower
*/

#include <stddef.h>

int my_str_islower(char const *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            return 0;
        }
    }
    return 1;
}
