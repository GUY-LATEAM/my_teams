/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** socket_management
*/

#include <stdio.h>
#include "select_func.h"
#include "socket_management_func.h"
#include "client_func.h"
#include "socket_manipulation.h"

void do_socket_read(network_client_t *client, fd_set *read_fds)
{
    if (FD_ISSET(client->socket, read_fds)) {
        if (read_socket(client->socket, client->read_buffer)) {
            client->on_disconnect(client->user_data, DISCONNECTED);
            destroy_network_client(client);
            return;
        }
        if (is_circular_buffer_completed(client->read_buffer)) {
            client->receive(client->user_data, client->read_buffer,
            client->write_buffer);
            clear_circular_buffer(client->read_buffer);
        }
    }
}

void do_socket_write(network_client_t *client, fd_set *write_fds)
{
    if (FD_ISSET(client->socket, write_fds)) {
        if (is_circular_buffer_completed(client->write_buffer)) {
            printf("Well received !\n");
            write_socket(client->socket, client->write_buffer);
            clear_circular_buffer(client->write_buffer);
        }
    }
}

void do_socket_except(network_client_t *client, fd_set *except_fds,
network_server_t *server)
{
    if (FD_ISSET(client->socket, except_fds)) {
        client->on_disconnect(client->user_data, SOCKET_ERROR);
        destroy_network_client(client);
        find_new_max_fd(&server->max_fd, server->clients);
    }
}
