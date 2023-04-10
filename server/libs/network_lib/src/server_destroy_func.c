/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** server_destroy_func
*/

#include <unistd.h>
#include "server_func.h"
#include "client_func.h"

void destroy_server_network(network_server_t *server)
{
    if (server == NULL)
        return;
    delete_all_network_clients_serv(server);
    close(server->socket);
    free(server);
}
