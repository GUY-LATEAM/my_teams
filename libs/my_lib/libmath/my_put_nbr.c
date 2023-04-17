/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** print nbr
*/

#include "libstr.h"
#include "libmath.h"

static int get_len_nbr(int nbr)
{
    int len = 0;

    while (nbr != 0) {
        nbr /= 10;
        len++;
    }
    return (len);
}

int my_put_nbr(int nb)
{
    int len_nbr = my_compute_power_it(10, get_len_nbr(nb) - 1);

    if (nb == 0) {
        my_putchar('0');
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while (len_nbr > 0) {
        my_putchar(nb / len_nbr + '0');
        nb = nb % len_nbr;
        len_nbr /= 10;
    }
    return 0;
}
