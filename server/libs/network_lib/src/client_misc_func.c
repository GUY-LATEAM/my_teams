/*
** EPITECH PROJECT, 2023
** lib_network
** File description:
** client_misc_func
*/

#include "list_lib.h"
#include "socket_basic_func.h"
#include "client_func.h"

bool accept_network_client(network_server_t* server, network_client_t* client)
{
    client->socket = accept_socket(server->socket);

    if (client->socket == -1) {
        destroy_network_client(client);
        return false;
    }
    list_add_last(server->clients, client);
    return true;
}

bool connect_network_client(network_client_t* client, char* ip, int port)
{
    client->socket = create_socket();

    if (connect_socket(client->socket, ip, port) == -1) {
        destroy_network_client(client);
        return false;
    }
    if (client->socket == -1) {
        destroy_network_client(client);
        return false;
    }
    return true;
}
