/*
** EPITECH PROJECT, 2021
** my_str_lowcase.c
** File description:
** same as name
*/

#include <unistd.h>
#include "libstr.h"

char *my_strlowcase(char *str)
{
    int len = 0;

    if (str == NULL) {
        return NULL;
    }
    len = my_strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
