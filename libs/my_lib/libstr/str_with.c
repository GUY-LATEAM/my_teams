/*
** EPITECH PROJECT, 2022
** test
** File description:
** start_end_with
*/

#include <stddef.h>
#include "libstr.h"

int is_in(char *dest, char *ref)
{
    int mark = 0;
    int indx = 0;

    if (dest == NULL || ref == NULL)
        return 0;
    for (int i = 0; dest[i] != '\0' && ref[indx] != '\0'; i++) {
        if (dest[i] != ref[indx])
            indx = 0;
        else
            indx++;
        if (ref[indx + 1] == '\0')
            mark = 1;
    }
    if ((ref[indx] == '\0' && mark == 1) ||
            (dest[0] == '\0' && ref[0] == '\0'))
        return 1;
    return 0;
}

int start_with(char *dest, char *ref)
{
    if (dest == NULL || ref == NULL)
        return 0;

    for (int i = 0; dest[i] != '\0' && ref[i] != '\0'; i++) {
        if (dest[i] != ref[i])
            return 0;
        if (ref[i + 1] == '\0')
            return 1;
    }
    return 0;
}

int end_with(char *dest, char *ref)
{
    int indx_dest = 0;
    int indx_ref = 0;

    if (dest == NULL || ref == NULL)
        return 0;
    indx_dest = my_strlen(dest) - 1;
    indx_ref = my_strlen(ref) - 1;
    if (indx_dest == 0 || indx_ref == 0)
        return 0;
    for (; indx_dest >= 0 && indx_ref >= 0; indx_dest--, indx_ref--) {
        if (dest[indx_dest] != ref[indx_ref])
            return 0;
        if (indx_ref == 0)
            return 1;
    }
    if (dest[0] == '\0' && ref[0] == '\0')
        return 1;
    return 0;
}

int str_with(char *dest, char *ref, side_t side)
{
    int result = 0;

    switch (side) {
        case START:
            result = start_with(dest, ref);
            break;
        case END:
            result = end_with(dest, ref);
            break;
        case IN:
            result = is_in(dest, ref);
            break;
        default:
            result = -1;
            break;
    }
    return result;
}
