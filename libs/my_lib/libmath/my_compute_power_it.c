/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nbr, int power)
{
    int result = 1;

    if (power < 0) {
        return 0;
    }
    if (power == 0) {
        return 1;
    }
    while (power > 0) {
        result *= nbr;
        power--;
    }
    return result;
}
