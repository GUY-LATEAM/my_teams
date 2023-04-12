/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_args_client
*/

#include "check_args_client.h"

void print_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip\tis the server ip address");
    printf(" on which the server socket listens.\n");
    printf("\tport\tis the port number on which");
    printf(" the server socket listens.\n");
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

bool is_arg_ip(char *arg)
{
    int i = 0;
    int dots = 0;

    while (arg[i] != '\0') {
        if (arg[i] == '.') {
            i++;
            dots++;
            continue;
        }
        if (arg[i] < '0' || arg[i] > '9')
            return (false);
        i++;
    }
    if (dots != 3)
        return (false);
    return (true);
}

bool is_args_client_valid(int ac, char **av)
{
    if (ac != 3)
        return (false);
    if (is_arg_ip(av[1]) == false) {
        printf("Invalid ip address (must be in the form x.x.x.x)\n");
        return (false);
    }
    if (is_arg_port(av[2]) == false) {
        printf("Invalid port number (must be between 0 and 65535)\n");
        return (false);
    }
    return (true);
}
