/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-romain.panno
** File description:
** my_puts_error
*/

#include <unistd.h>

int my_puts_error(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(2, str, i);
    write(2, "\n", 1);
    return 0;
}
