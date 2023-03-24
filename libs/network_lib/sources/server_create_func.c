/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** server_create_func
*/

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
    server->clients = NULL;
    return (server);
}
