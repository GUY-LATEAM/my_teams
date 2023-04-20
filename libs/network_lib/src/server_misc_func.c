/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** server_misc_func
*/

#include <stdio.h>
#include "list_lib.h"
#include "socket_management_func.h"
#include "server_func.h"
#include "client_func.h"
#include "select_func.h"

int server_receive_new_con(network_server_t *server, int buff_size,
    const char *pattern)
{
    if (FD_ISSET(server->socket, &server->read_fds)) {
        accept_network_client(server, create_client(buff_size, pattern));
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void server_loop_client(network_server_t *server)
{
    network_client_t *client = NULL;

    for (int i = 0; i < server->clients->len ; i++) {;
        client = get_list_i_data(server->clients, i);
        if (do_socket_read(client, &server->read_fds)
            == DISCONNECTED) {
            remove_list_element(server->clients, i);
            find_new_max_fd(&server->max_fd, server->clients, server->socket);
            continue;
        }
        do_socket_write(client, &server->write_fds);
        if (do_socket_except(client, &server->except_fds, server)
            == SOCKET_ERROR) {
            remove_list_element(server->clients, i);
            continue;
        }
    }
}
