/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-baptiste.laran
** File description:
** my_memset
*/

#include <stdlib.h>

char *my_memset(char *str, int value, char set)
{
    str = malloc(sizeof(char) * value);

    for (int i = 0; i < value; i++) {
        str[i] = set;
        str[i + 1] = '\0';
    }
    return str;
}
