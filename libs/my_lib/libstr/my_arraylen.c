/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-bsminishell1-romain.panno
** File description:
** my_array_len
*/

#include "unistd.h"

int my_arrlen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
