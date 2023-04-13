/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-baptiste.laran
** File description:
** my_split_right
*/

#include <stdlib.h>
#include <stddef.h>
int check_char(char dest, char *ref);

int my_split_get_indx_right(char *ref, char *mark)
{
    int i = 0;

    for (; ref[i] != '\0' && check_char(ref[i], mark) == 0; i++);
    for (; ref[i] != '\0' && check_char(ref[i], mark) == 1; i++);
    return i;
}

int my_split_right_len(char *ref, char *mark)
{
    int i = 0;
    int len = 0;

    for (; ref[i] != '\0' && check_char(ref[i], mark) == 0; i++);
    for (; ref[i] != '\0' && check_char(ref[i], mark) == 1; i++);
    for (; ref[i] != '\0'; i++, len++);
    return len;
}

char *my_split_right(char *ref, char *mark)
{
    int len = 0;
    char *result = NULL;
    int indx = 0;
    int i = 0;

    if (ref == NULL) {
        return NULL;
    }
    len = my_split_right_len(ref, mark);
    result = malloc(sizeof(char) * (len + 1));
    indx = my_split_get_indx_right(ref, mark);
    for (; ref[indx] != '\0'; i++, indx++)
        result[i] = ref[indx];
    result[i] = '\0';
    return result;
}
