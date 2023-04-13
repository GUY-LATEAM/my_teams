/*
** EPITECH PROJECT, 2022
** test_file
** File description:
** my_puts
*/

#include <unistd.h>

int my_puts(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(1, str, i);
    write(1, "\n", 1);
    return 0;
}
