/*
** EPITECH PROJECT, 2021
** list_lib
** File description:
** list_chaine
*/

#include <stdbool.h>
#include "list_lib.h"

static int move_pointers_for_last(list_ptr_t *list_ptr, list_t *element)
{
    if (list_ptr->first == NULL || list_ptr->last == NULL) {
        return LIST_ERR_INPUT;
    }
    element->next = list_ptr->first;
    element->prev = list_ptr->last;
    list_ptr->first->prev = element;
    list_ptr->last->next = element;
    list_ptr->last = element;
    return LIST_OK;
}

int list_add_last(list_ptr_t *list_ptr, void *data)
{
    list_t *element = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    element = malloc(sizeof(list_t));
    if (element == NULL) {
        return LIST_ERR_MALLOC;
    }
    element->data = data;
    if (list_ptr->len == 0) {
        list_ptr->first = element;
        list_ptr->last = element;
        element->next = element;
        element->prev = element;
    } else {
        move_pointers_for_last(list_ptr, element);
    }
    list_ptr->len += 1;
    return LIST_OK;
}

static int move_pointers_for_first(list_ptr_t *list_ptr, list_t *element)
{
    if (list_ptr->first == NULL || list_ptr->last == NULL) {
        return LIST_ERR_INPUT;
    }
    list_ptr->first->prev = element;
    list_ptr->last->next = element;
    list_ptr->first = element;
    return LIST_OK;
}

int list_add_first(list_ptr_t *list_ptr, void *data)
{
    list_t *element = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    element = malloc(sizeof(list_t));
    if (element == NULL) {
        return LIST_ERR_MALLOC;
    }
    element->data = data;
    element->next = list_ptr->first;
    element->prev = list_ptr->last;
    if (list_ptr->len == 0) {
        list_ptr->first = element;
        list_ptr->last = element;
    } else if (move_pointers_for_first(list_ptr, element) != LIST_OK) {
        return LIST_ERR_INPUT;
    }
    list_ptr->len++;
    return LIST_OK;
}
