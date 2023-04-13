/*
** EPITECH PROJECT, 2021
** list_lib
** File description:
** manage_lists
*/

#include "list_lib.h"

int remove_list_element(list_ptr_t *list_ptr, int i)
{
    list_t *ptr = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    ptr = get_list_i(list_ptr, i);
    if (i == 0)
        list_ptr->first = ptr->next;
    else if (i == list_ptr->len - 1)
        list_ptr->last = ptr->prev;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    list_ptr->len -= 1;
    free(ptr);
    return LIST_OK;
}

int free_list_no_data(list_ptr_t *list_ptr)
{
    list_t *tmp = NULL;

    if (list_ptr == NULL) {
        return LIST_ERR_INPUT;
    }
    tmp = list_ptr->first;
    if (tmp == NULL) {
        return LIST_ERR_INPUT;
    }
    for (int i = 0; i < list_ptr->len; i++) {
        tmp = tmp->next;
        if (tmp == NULL) {
            return LIST_ERR_INPUT;
        }
        free(tmp->prev);
    }
    free(list_ptr);
    return LIST_OK;
}

int destroy_list(list_ptr_t *listptr)
{
    int len = listptr->len;

    for (; len > 0; len -= 1) {
        if (len == 1) {
            free(listptr->last->data);
            free(listptr->last);
        } else {
            listptr->last = listptr->last->prev;
            free(listptr->last->next->data);
            free(listptr->last->next);
        }
    }
    free(listptr);
    return EXIT_SUCCESS;
}
