/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-romain.panno
** File description:
** my_putstr_error
*/

#include <unistd.h>

int my_putstr_error(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(2, str, i);
    return 0;
}
