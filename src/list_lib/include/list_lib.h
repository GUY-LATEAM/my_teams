/*
** EPITECH PROJECT, 2021
** list_lib
** File description:
** list_t
*/

#ifndef LIST_T_H_
    #define LIST_T_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include "struct_list_lib.h"

    #define LIST_OK 0
    #define LIST_ERR_INPUT 1
    #define LIST_ERR_MALLOC 2
    #define FIRST_ELEMENT 0
    #define LAST_ELEMENT(i) (i == 0) ? 0 : i - 1

    list_ptr_t *list_create(void);

    list_t *list_init(list_ptr_t *list_ptr, void *data);

    int list_add_first(list_ptr_t *list_ptr, void *data);

    int list_add_last(list_ptr_t *list_ptr, void *data);

    int list_add_i(list_ptr_t *list_ptr, void *data, int i);

    void *get_list_i_data(list_ptr_t *list_ptr, int i);

    int get_int_data(list_ptr_t *list_ptr, int i);

    list_t *get_list_i(list_ptr_t *list_ptr, int i);

    int remove_list_element(list_ptr_t *list_ptr, int i);

    int display_list_int(list_ptr_t *list_ptr);

    int destroy_list(list_ptr_t *listptr);

    int free_list_no_data(list_ptr_t *list_ptr);

    int replace_list_i(list_ptr_t *list_ptr, void *data, int i,
    void (*destroy)(void *));
#endif /* !LIST_T_H_ */
