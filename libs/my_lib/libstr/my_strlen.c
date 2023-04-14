/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return -1;
    }
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
