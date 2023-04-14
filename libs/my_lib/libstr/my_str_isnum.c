/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** same
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return 0;
    }
    if (str[0] == '-') {
        i++;
    }
    if (str[i] == '0' && str[i + 1] != '\0') {
        return 0;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
