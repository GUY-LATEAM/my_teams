/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** select_misc_func
*/

#include <unistd.h>
#include <stdio.h>
#include "select_func.h"

char *read_input_select(fd_set *read_fds)
{
    char *input = NULL;
    size_t size = 0;

    if (FD_ISSET(STDIN_FILENO, read_fds)) {
        if (getline(&input, &size, stdin) == -1)
            return NULL;
    }
    return input;
}
