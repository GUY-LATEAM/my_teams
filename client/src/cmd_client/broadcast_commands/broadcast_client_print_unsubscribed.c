/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_client_print_unsubscribed
*/

#include "broadcast_misc.h"

int broadcast_client_print_unsubscribed(char *raw_args)
{
    char **args = NULL;
    int result = 0;

    if (raw_args == NULL) {
        return EXIT_FAILURE;
    }
    args = get_char_array_args(raw_args);
    if (args == NULL || my_arrlen(args) != 2) {
        return EXIT_FAILURE;
    }
    result = client_print_unsubscribed(args[0], args[1]);
    destroy_array(args);
    return result;
}
