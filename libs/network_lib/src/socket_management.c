/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** socket_management
*/

#include "select_func.h"
#include "socket_management_func.h"
#include "client_func.h"

void do_socket_read(network_client_t *client, fd_set *read_fds)
{
    if (FD_ISSET(client->socket, read_fds)) {
        client->receive(client->user_data, client->read_buffer);
    }
}

void do_socket_write(network_client_t *client, fd_set *write_fds)
{
    if (FD_ISSET(client->socket, write_fds)) {
        client->send(client->user_data, client->write_buffer);
    }
}

void do_socket_except(network_client_t *client, fd_set *except_fds, network_server_t *server)
{
    if (FD_ISSET(client->socket, except_fds)) {
        client->on_disconnect(client->user_data, SOCKET_ERROR);
        destroy_network_client(client);
        find_new_max_fd(&server->max_fd, server->clients);
    }
}
