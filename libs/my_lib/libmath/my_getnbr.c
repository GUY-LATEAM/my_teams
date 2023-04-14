/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get numbers
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int begin = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nbr = nbr * 10 + str [i] - 48;
            begin++;
        }
        if (str[i] > 57 || (str[i] < 48 && nbr > 0))
            break;
        i++;
    }
    if ((i - begin - 1 >= 0) && str[i - begin- 1] == '-' &&
        (str[i - begin- 2] < 48 || str[i - begin- 2] > 57)) {
        nbr = nbr * -1;
    }
    return (nbr);
}
