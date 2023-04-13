/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-bsminishell1-romain.panno
** File description:
** display_arr
*/

#include <unistd.h>
#include "libstr.h"

int display_arr(char **arr, char *separator)
{
    if (arr == NULL) {
        return 84;
    }
    for (int i = 0; arr[i] != NULL; i++) {
        my_putstr(arr[i]);
        if (separator != NULL)
            my_putstr(separator);
    }
    return 0;
}
