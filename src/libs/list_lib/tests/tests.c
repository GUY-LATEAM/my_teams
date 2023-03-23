/*
** EPITECH PROJECT, 2022
** list_lib
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "list_lib.h"
#include <criterion/redirect.h>

Test(list_add_last_, add_last)
{
    list_ptr_t *list_ptr = NULL;
    char *res = NULL;

    list_ptr = list_create();
    list_add_last(list_ptr, "oui mec");

    res = get_list_i_data(list_ptr, FIRST_ELEMENT);
    cr_assert_str_eq(res, "oui mec");
}

Test(list_add_first_, add_first)
{
    list_ptr_t *list_ptr = NULL;
    char *res = NULL;

    list_ptr = list_create();
    list_add_first(list_ptr, "oui mec");

    res = get_list_i_data(list_ptr, FIRST_ELEMENT);
    cr_assert_str_eq(res, "oui mec");
}

Test(list_add_first_2, add_first)
{
    list_ptr_t *list_ptr = NULL;
    char *res = NULL;

    list_ptr = list_create();
    list_add_first(list_ptr, "oui dude");
    list_add_first(list_ptr, "oui mec");

    res = get_list_i_data(list_ptr, FIRST_ELEMENT);
    cr_assert_str_eq(res, "oui mec");
}

Test(list_add, list_add_pulitple_elements)
{
    list_ptr_t *list_ptr = NULL;
    char *res = NULL;

    list_ptr = list_create();
    list_add_first(list_ptr, "oui mec");
    list_add_first(list_ptr, "non mec");
    list_add_last(list_ptr, "oui oui");
    list_add_i(list_ptr, "nonnonono", 2);

    res = get_list_i_data(list_ptr, 2);
    cr_assert_str_eq(res, "nonnonono");
    res = get_list_i_data(list_ptr, FIRST_ELEMENT);
    cr_assert_str_eq(res, "non mec");
    res = get_list_i_data(list_ptr, 1);
    cr_assert_str_eq(res, "oui mec");
    res = get_list_i_data(list_ptr, LAST_ELEMENT(list_ptr->len));
    cr_assert_str_eq(res, "oui oui");
}
