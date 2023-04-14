/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
