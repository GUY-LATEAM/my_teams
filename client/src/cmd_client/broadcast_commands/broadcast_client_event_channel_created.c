/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** broadcast_client_event_channel_created
*/

#include "broadcast_misc.h"

int broadcast_client_event_channel_created(char *raw_args)
{
    char **args = NULL;
    int result = 0;
    size_t args_len = 0;

    if (raw_args == NULL)
        return EXIT_FAILURE;
    args = get_char_array_args(raw_args);
    if (args == NULL) {
        return EXIT_FAILURE;
    }
    args_len = my_arrlen(args);
    if (args_len != 2 && args_len != 3)
        return EXIT_FAILURE;
    if (args_len == 2)
        result = client_event_channel_created(args[0], args[1], "");
    else
        result = client_event_channel_created(args[0], args[1], args[2]);
    destroy_array(args);
    return result;
}
