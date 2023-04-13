/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-romain.panno
** File description:
** destroy_arr
*/

#include <stddef.h>
#include <stdlib.h>

int destroy_array(void **array)
{
    if (array == NULL)
        return 84;

    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return 0;
}
