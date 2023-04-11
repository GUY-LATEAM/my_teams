/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** client_logic
*/

#include "signal_management_client.h"
#include "my_teams_server.h"
#include "client_loop.h"

int do_myteams_client(int ac, char **av)
{
    client_t *client = init_client(ac, av);

    if (!client)
        return (84);
    signal(SIGINT, handle_signal);
    while (get_signal_flag() == NOTHING_RECEIVED) {
        loop_client(client);
    }
    apply_signal_action(client);
    destroy_client(client);
    return (0);
}