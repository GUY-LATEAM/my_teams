/*
** EPITECH PROJECT, 2021
** my_soir_in_array.c
** File description:
** sort in array
*/

#include <stddef.h>

static void compare_int(int *tab, int size)
{
    for (int j = 0; j < size - 1; j++) {
        if (tab[j] > tab[j + 1]) {
            int tmp = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = tmp;
        }
    }
}

int *my_sort_int_array(int *tab, int size)
{
    if (tab == NULL || size <= 0) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        compare_int(tab, size);
    }
    return tab;
}
