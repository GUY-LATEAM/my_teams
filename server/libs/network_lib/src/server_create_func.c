/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** server_create_func
*/

#include "list_lib.h"
#include "server_func.h"
#include "socket_basic_func.h"

network_server_t *create_server(int port)
{
    network_server_t *server = malloc(sizeof(network_server_t));

    if (server == NULL)
        return (NULL);
    server->socket = create_socket();
    if (server->socket == -1) {
        free(server);
        return (NULL);
    }
    if (bind_socket(server->socket, port) == -1) {
        free(server);
        return (NULL);
    }
    if (listen_socket(server->socket) == -1) {
        free(server);
        return (NULL);
    }
    server->clients = list_create();
    server->max_fd = server->socket;
    return (server);
}
