/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** Write an iterative function that returns the first argument to the last
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    } else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return (result);
}
