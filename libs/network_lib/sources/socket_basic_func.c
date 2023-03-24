/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** socket_basic_func
*/

/*
** EPITECH PROJECT, 2023
** B-NWP-400-TLS-4-1-myftp-clement.lagasse
** File description:
** socket_func
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "socket_basic_func.h"

int create_socket(void)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Error: Fail to create socket\n");
        return (-1);
    }
    return (socket_fd);
}

int bind_socket(int socket_fd, int port)
{
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error: Fail to bind\n");
        return (-1);
    }
    printf("Open on port %d\n", port);
    return (0);
}

int listen_socket(int socket_fd)
{
    if (listen(socket_fd, 3) < 0) {
        printf("Error: Fail to listen\n");
        return (-1);
    }
    return (0);
}

int accept_socket(int socket_fd)
{
    int new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    new_socket = accept(socket_fd, (struct sockaddr *)&address,
    (socklen_t *)&addrlen);

    if (new_socket < 0) {
        printf("Error: Fail to accept\n");
        return (-1);
    }
    return (new_socket);
}

void set_socket_fdset(network_server_t *server)
{
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->except_fds);
    FD_SET(server->socket, &server->read_fds);
    FD_SET(server->socket, &server->write_fds);
    FD_SET(server->socket, &server->except_fds);
}
