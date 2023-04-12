/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** server_loop
*/

#include <signal.h>
#include <stdio.h>
#include "select_func.h"
#include "socket_basic_func.h"
#include "my_teams_server.h"
#include "server_func.h"
#include "server_loop.h"
#include "signal_management_server.h"
#include "init_struct.h"
#include "destroy_struct.h"

static const char GUY[] = "\x67\x75\x79";

int do_myteams_server(char **av)
{
    server_t *srv = NULL;

    srv = init_server(atoi(av[1]));
    if (!srv)
        return 84;
    signal(SIGINT, handle_signal);
    while (get_signal_flag() == NOTHING_RECEIVED) {
        loop_server(srv);
    }
    apply_signal_action(srv);
    destroy_server(srv);
    return 0;
}

void loop_server(server_t *srv)
{
    set_socket_fdset(srv->network_server);
    if (select_socket(srv->network_server->max_fd,
    &srv->network_server->read_fds,
    &srv->network_server->write_fds,
    &srv->network_server->except_fds) != 0)
            return;
    if (server_receive_new_con(srv->network_server, 1024,
    GUY) == 1) {
        printf("New client connected\n");
    }
    server_loop_client(srv->network_server);
}
