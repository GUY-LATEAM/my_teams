/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_client_event_logged_in
*/

#include "broadcast_misc.h"

int broadcast_client_event_logged_in(char *raw_args)
{
    char **args = NULL;
    int result = 0;

    printf("In Broadcast :%s\n", raw_args);
    if (raw_args == NULL) {
        return EXIT_FAILURE;
    }
    args = get_char_array_args(raw_args);
    if (args == NULL || my_arrlen(args) != 2) {
        return EXIT_FAILURE;
    }
    result = client_event_logged_in(args[0], args[1]);
    destroy_array(args);
    return result;
}
