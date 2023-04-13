/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** socket_management
*/

#include <stdio.h>
#include "socket_basic_func.h"
#include "list_lib.h"
#include "select_func.h"
#include "socket_management_func.h"
#include "client_func.h"
#include "socket_manipulation.h"

on_disconnect_error_t do_socket_read(network_client_t *client, fd_set *read_fds)
{
    if (FD_ISSET(client->socket, read_fds)) {
        if (read_socket(client->socket, client->read_buffer) <= 0) {
            client->on_disconnect(client->user_data,
            client->protocol_data, DISCONNECTED);
            destroy_network_client(client);
            return DISCONNECTED;
        }
        if (is_circular_buffer_completed(client->read_buffer)) {
            printf("Received ! : %s", client->read_buffer->buffer);
            client->receive(client->user_data, client->protocol_data,
            client->read_buffer,
            client->write_buffer);
            clear_circular_buffer(client->read_buffer);
        }
    }
    return NO_ERROR;
}

on_disconnect_error_t do_socket_write(network_client_t *client,
fd_set *write_fds)
{
    if (FD_ISSET(client->socket, write_fds)) {
        write_socket(client->socket, client->write_buffer);
        clear_circular_buffer(client->write_buffer);
    }
    return NO_ERROR;
}

on_disconnect_error_t do_socket_except(network_client_t *client,
fd_set *except_fds, network_server_t *server)
{
    if (FD_ISSET(client->socket, except_fds)) {
        client->on_disconnect(client->user_data,
        client->protocol_data, SOCKET_ERROR);
        destroy_network_client(client);
        find_new_max_fd(&server->max_fd, server->clients);
        return SOCKET_ERROR;
    }
    return NO_ERROR;
}

void set_fds_clients(list_ptr_t *clients, fd_set *read_fds,
fd_set *write_fds, fd_set *except_fds)
{
    network_client_t *client = NULL;

    for (int i = 0; i < clients->len; i++) {
        client = get_list_i_data(clients, i);
        set_fds_client(client, read_fds, write_fds, except_fds);
    }
}

void set_fds_client(network_client_t *client, fd_set *read_fds,
fd_set *write_fds, fd_set *except_fds)
{
    set_socket_fdset(client->socket, read_fds, NULL, except_fds);
    if (is_circular_buffer_completed(client->write_buffer))
        set_socket_fdset(client->socket, NULL, write_fds, NULL);
}
