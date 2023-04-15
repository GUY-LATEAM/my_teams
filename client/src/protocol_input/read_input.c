/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** read_input
*/

#include <stdio.h>
#include "protocol_logic.h"

char *read_input(void)
{
    char *input = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1)
        return NULL;
    return input;
}
