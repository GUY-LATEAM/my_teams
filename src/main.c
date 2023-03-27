/*
** EPITECH PROJECT, 2023
** my_teams.c
** File description:
** my_teams
*/

#include <string.h>
#include "my_teams.h"
#include "check_args_server.h"
#include "server_loop.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-help") || strcmp(av[1], "-h") == 0) {
        print_help();
    } else if (is_args_server_valid(ac, av) == false)
        return (84);
    else
        return (do_myteams(ac, av));
    return (0);
}
