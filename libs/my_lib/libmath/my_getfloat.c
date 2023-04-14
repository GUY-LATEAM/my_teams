/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-baptiste.laran
** File description:
** my_getfloat
*/

#include <stdlib.h>
#include "libmath.h"

int my_strlen(char const *str);

static int get_float_gap(char *str)
{
    int len = 0;
    int i = 0;

    for (; str[i] != '.' && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return 0;
    i++;
    for (; str[i] != '\0'; i++, len++);
    return len;
}

static char *get_int_str(char *str)
{
    char *result = NULL;
    int check = 0;
    int indx = 0;

    if (str == NULL)
        return NULL;
    for (; str[check] != '\0' && str[check] != '.'; check++);
    if (str[check] != '.')
        return str;
    result = malloc(sizeof(my_strlen(str)));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.') {
            result[indx] = str[i];
            indx++;
            result[indx] = '\0';
        }
        result[indx] = '\0';
    }
    return result;
}

float my_getfloat(char *str)
{
    char *int_str = NULL;
    int gap_float = 0;
    int int_nbr = 0;
    float res = 0.0;

    if (str == NULL)
        return 0;
    int_str = get_int_str(str);
    int_nbr = my_getnbr(int_str);
    gap_float = get_float_gap(str);
    res = (float) int_nbr / my_compute_power_rec(10, gap_float);
    return res;
}
