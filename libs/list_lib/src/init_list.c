/*
** EPITECH PROJECT, 2021
** list_lib
** File description:
** list_init
*/

#include "list_lib.h"

list_ptr_t *list_create(void)
{
    list_ptr_t *list_ptr_element = malloc(sizeof(list_ptr_t));

    if (list_ptr_element == NULL) {
        return NULL;
    }
    list_ptr_element->first = NULL;
    list_ptr_element->last = NULL;
    list_ptr_element->len = 0;
    return list_ptr_element;
}

list_t *list_init(list_ptr_t *list_ptr, void *data)
{
    list_t *first_list = NULL;

    if (list_ptr == NULL) {
        return NULL;
    }
    first_list = malloc(sizeof(list_t));
    if (first_list == NULL) {
        return NULL;
    }
    first_list->data = data;
    first_list->next = first_list;
    first_list->prev = first_list;
    list_ptr->first = first_list;
    list_ptr->last = first_list;
    list_ptr->len = 1;
    return first_list;
}
