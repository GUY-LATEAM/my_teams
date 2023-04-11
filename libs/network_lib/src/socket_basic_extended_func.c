/*
** EPITECH PROJECT, 2023
** lib_network
** File description:
** socket_basic_extended_func
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "socket_basic_func.h"

int connect_socket(int socket_fd, char *ip, int port)
{
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);
    return (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)));
}
