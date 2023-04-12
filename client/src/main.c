/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <string.h>
#include "check_args_client.h"
#include "my_teams_client.h"
#include "client_loop.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        print_help();
    } else if (is_args_client_valid(ac, av) == false)
        return (84);
    else
        return (do_myteams_client(ac, av));
    return (0);
}
