/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** same as name
*/

#include <unistd.h>
#include "libstr.h"

char *my_strupcase(char *str)
{
    int len = 0;

    if (str == NULL) {
        return NULL;
    }
    len = my_strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
