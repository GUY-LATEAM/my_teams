/*
** EPITECH PROJECT, 2021
** my
** File description:
** nbr_to_string
*/

#include <stdlib.h>
#include "libstr.h"

int len_nbr(int nb)
{
    int len_nb = 1;

    if (nb < 0)
        nb *= -1;
    while (nb > 10) {
        len_nb += 1;
        nb /= 10;
    }
    return len_nb;
}

char *int_to_string(int nb)
{
    int i = 0;
    int len_nb = len_nbr(nb);
    int tmp = 0;
    char *res = malloc(sizeof(char) * len_nb + 1);

    for (; i < len_nb; i++) {
        tmp = nb % 10;
        nb /= 10;
        res[i] = tmp + '0';
    }
    res[i] = '\0';
    res = my_revstr(res);
    return res;
}
