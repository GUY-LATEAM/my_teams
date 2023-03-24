/*
** EPITECH PROJECT, 2021
** list_lib
** File description:
** struct_list_t
*/

#ifndef STRUCT_LIST_T_H_
    #define STRUCT_LIST_T_H_
    typedef struct list_s {
        void *data;
        struct list_s *prev;
        struct list_s *next;
    }list_t;

    typedef struct list_ptr_s {
        int len;
        list_t *first;
        list_t *last;
    } list_ptr_t;

#endif /* !STRUCT_LIST_T_H_ */
