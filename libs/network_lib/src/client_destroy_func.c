/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** client_destroy_func
*/

#include <sys/socket.h>
#include <unistd.h>
#include "list_lib.h"
#include "circular_buffer.h"
#include "client_func.h"
#include "socket_basic_func.h"

void destroy_network_client(network_client_t *client)
{
    if (client == NULL)
        return;
    destroy_circular_buffer(client->read_buffer);
    destroy_circular_buffer(client->write_buffer);
    shutdown(client->socket, SHUT_RDWR);
    close(client->socket);
    free(client);
}

bool delete_network_client_serv(network_server_t* server, int client_id)
{
    network_client_t *client = get_list_i_data(server->clients, client_id);

    if (client == NULL)
        return false;
    destroy_network_client(client);
    remove_list_element(server->clients, client_id);
    return true;
}

bool delete_all_network_clients_serv(network_server_t* server)
{
    for (int i = 0; i < server->clients->len ; i++)
        delete_network_client_serv(server, i);
    return true;
}
