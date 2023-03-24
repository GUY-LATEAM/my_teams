/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** server_misc_func
*/

#include "socket_management_func.h"
#include "server_func.h"
#include "client_func.h"

void server_loop(network_server_t *server, int buff_size, char *pattern)
{
    network_client_t *client = NULL;
    int client_id = 0;

    if (FD_ISSET(server->socket, &server->read_fds)) {
        create_network_client(server, buff_size, pattern);
    }
    for (int i = 0; i < list_size(server->clients); i++) {
        client = list_get(server->clients, i);
        do_socket_read(client, &server->read_fds);
        do_socket_write(client, &server->write_fds);
        do_socket_except(client, &server->except_fds, server);
    }
}
