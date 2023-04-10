/*
** EPITECH PROJECT, 2022
** list_lib
** File description:
** list_get_data
*/

#include "list_lib.h"

list_t *get_list_i(list_ptr_t *list_ptr, int i)
{
    list_t *ptr_i = NULL;

    if (list_ptr == NULL) {
        return NULL;
    }
    if (i < 0) {
        i = i % list_ptr->len - 1;
    }
    ptr_i = list_ptr->first;
    for (int v = 0; v < i; v++) {
        ptr_i = ptr_i->next;
    }
    return ptr_i;
}

void *get_list_i_data(list_ptr_t *list_ptr, int i)
{
    list_t *ptr_i = NULL;

    if (list_ptr == NULL) {
        return NULL;
    }
    if (i < 0) {
        i = i % list_ptr->len - 1;
    }
    ptr_i = list_ptr->first;
    for (int v = 0; v < i; v++)
        ptr_i = ptr_i->next;
    return ptr_i->data;
}
