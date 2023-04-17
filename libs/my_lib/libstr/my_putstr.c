/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <unistd.h>

int my_putstr(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(1, str, i);
    return 0;
}
