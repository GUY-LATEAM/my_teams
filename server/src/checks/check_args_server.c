/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_args_server
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check_args_server.h"

void print_help(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\n\tport is the port number on which the server socket listens.\n");
}

bool is_args_server_valid(int ac, char **av)
{
    if (ac != 2)
        return (false);
    if (is_arg_port(av[1]) == false) {
        printf("Invalid port number (must be between 0 and 65535)\n");
        return (false);
    }
    return (true);
}

bool is_arg_port(char *arg)
{
    int i = 0;

    while (arg[i] != '\0') {
        if (arg[i] < '0' || arg[i] > '9')
            return (false);
        i++;
    }
    if (atoi(arg) < 0 || atoi(arg) > 65535)
        return (false);
    return (true);
}
