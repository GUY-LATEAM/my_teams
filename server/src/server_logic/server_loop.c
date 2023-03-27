/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** server_loop
*/

#include <signal.h>
#include <stdio.h>
#include "my_teams_server.h"
#include "server_func.h"
#include "server_loop.h"
#include "signal_management.h"

int do_myteams(int ac, char **av)
{
    server_t *srv = NULL;

    srv = init_server(atoi(av[1]));
    if (!srv)
        return 84;
    signal(SIGINT, handle_signal);
    while (get_signal_flag() != SIGINT_RECEIVED) {
        loop_server(srv);
    }
    apply_signal_action(srv);
    // Destroy server
    return 0;
}

void loop_server(server_t *srv)
{
    if (server_receive_new_con(srv->network_server, 1024, "\x67\x75\x79") == 1) {
        printf("New client connected");
    }
    server_loop_client(srv->network_server);

}