/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_client_event_thread_reply_received
*/

#include "broadcast_misc.h"

int broadcast_client_event_thread_reply_received(char *raw_args)
{
    char **args = NULL;
    int result = 0;

    if (raw_args == NULL) {
        return EXIT_FAILURE;
    }
    args = get_char_array_args(raw_args);
    if (args == NULL || my_arrlen(args) != 4) {
        return EXIT_FAILURE;
    }
    result =
    client_event_thread_reply_received(args[0], args[1], args[2], args[3]);
    destroy_array(args);
    return result;
}
