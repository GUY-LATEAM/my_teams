/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** Write a function that reverses a string. It must be prototyped the follow
*/

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int leni = my_strlen(str) - 1;
    int len_div = my_strlen(str) / 2;
    char c = '?';

    for (int i = 0; i < len_div; i++) {
        c = str[i];
        str[i] = str[leni];
        str[leni] = c;
        leni--;
    }
    return (str);
}
