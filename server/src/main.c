/*
** EPITECH PROJECT, 2023
** my_teams_server.h.c
** File description:
** my_teams_server.h
*/

#include <string.h>
#include "check_args_server.h"
#include "server_loop.h"
#include "my_teams_server.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (EXIT_EPITECH);
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        print_help();
    } else if (is_args_server_valid(ac, av) == false)
        return (EXIT_EPITECH);
    else
        return (do_myteams_server(av));
    return (EXIT_SUCCESS);
}
