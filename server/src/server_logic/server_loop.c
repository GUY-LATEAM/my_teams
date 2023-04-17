/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** server_loop
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "select_func.h"
#include "socket_basic_func.h"
#include "my_teams_server.h"
#include "server_func.h"
#include "server_loop.h"
#include "signal_management_server.h"
#include "init_struct.h"
#include "destroy_struct.h"
#include "save_struck.h"
#include "socket_management_func.h"
#include "protocol_logic.h"
#include "socket_manipulation.h"
#include "receive_handler.h"

int do_myteams_server(char **av)
{
    server_t *srv = NULL;

    srv = init_server(atoi(av[1]));
    if (!srv)
        return 84;
    //if (save_file_data(srv, USERS_FILEPATH, SERVER_FILEPATH) == false)
    //    return 84;
    signal(SIGINT, handle_signal);
    while (SIGNAL_FLAG == NOTHING_RECEIVED) {
        loop_server(srv);
    }
    apply_signal_action(srv);
    destroy_server(srv);
    return 0;
}

void loop_server(server_t *srv)
{
    clear_fd_set(&srv->network_server->read_fds,
    &srv->network_server->write_fds,
    &srv->network_server->except_fds);
    set_socket_fdset(srv->network_server->socket,
    &srv->network_server->read_fds, NULL, &srv->network_server->except_fds);
    set_fds_clients(srv->network_server->clients,
    &srv->network_server->read_fds,
    &srv->network_server->write_fds, &srv->network_server->except_fds);
    if (select_socket(srv->network_server->max_fd,
    &srv->network_server->read_fds,
    &srv->network_server->write_fds,
    &srv->network_server->except_fds) != 0)
            return;
    if (server_receive_new_con(srv->network_server, BUFF_SIZE,
    GUY) == EXIT_SUCCESS) {
        printf("New client connected\n");
        set_new_con_protocol_logic(srv);
    }
    server_loop_client(srv->network_server);
}
