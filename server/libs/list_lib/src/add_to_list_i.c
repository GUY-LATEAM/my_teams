/*
** EPITECH PROJECT, 2022
** list_lib
** File description:
** add_to_list_i
*/

#include "list_lib.h"

int replace_list_i(list_ptr_t *list_ptr, void *data, int i,
    void (*destroy)(void *))
{
    list_t *ptr_i = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    ptr_i = get_list_i(list_ptr, i);
    if (ptr_i == NULL) {
        return LIST_ERR_INPUT;
    }
    if (destroy != NULL && ptr_i->data != NULL) {
        destroy(ptr_i->data);
    }
    ptr_i->data = data;
    return LIST_OK;
}

static void replace_data_pointers(list_t *element, list_t *ptr_i, void *data)
{
    element->data = data;
    element->next = ptr_i;
    element->prev = ptr_i->prev;
    ptr_i->prev->next = element;
    ptr_i->prev = element;
}

int list_add_i(list_ptr_t *list_ptr, void *data, int i)
{
    list_t *element = NULL;
    list_t *ptr_i = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    ptr_i = get_list_i(list_ptr, i);
    if (ptr_i == NULL || ptr_i->next == NULL || ptr_i->prev == NULL) {
        return LIST_ERR_INPUT;
    }
    element = malloc(sizeof(list_t));
    if (element == NULL) {
        return LIST_ERR_MALLOC;
    }
    replace_data_pointers(element, ptr_i, data);
    list_ptr->len++;
    return LIST_OK;
}
