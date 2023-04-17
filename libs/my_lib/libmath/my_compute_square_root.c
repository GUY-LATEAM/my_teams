/*
** EPITECH PROJECT, 2021
** square_root.c
** File description:
** do square root
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int result = 0;

    while (result * result < nb) {
        result = i;
        i++;
    }
    return result;
}
