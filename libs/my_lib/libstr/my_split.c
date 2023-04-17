/*
** EPITECH PROJECT, 2022
** test
** File description:
** my_split
*/

#include <unistd.h>
#include "libstr.h"

char *my_split(char *ref, char *mark, side_t side)
{
    char *result = NULL;

    switch (side) {
        case LEFT:
            result = my_split_left(ref, mark);
            break;
        case RIGHT:
            result = my_split_right(ref, mark);
            break;
        default:
            write(2, "Bad int for side\n", 18);
            break;
    }
    return result;
}
