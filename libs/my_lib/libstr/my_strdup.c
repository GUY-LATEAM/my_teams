/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-antman-brice.desousa
** File description:
** my_strdup
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len = 0;
    char *res = NULL;

    if (str == NULL) {
        return NULL;
    }
    for (; str[len] != '\0'; len++);
    res = malloc(sizeof(char) * len + 1);
    res[len] = '\0';
    for (len = 0; str[len] != '\0'; len++)
        res[len] = str[len];
    return res;
}
