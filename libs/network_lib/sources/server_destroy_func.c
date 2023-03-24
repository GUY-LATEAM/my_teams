/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** server_destroy_func
*/

#include <unistd.h>
#include "server_func.h"
#include "client_func.h"

void destroy_server(network_server_t *server)
{
    if (server == NULL)
        return;
    delete_all_network_clients_serv(server);
    close(server->socket);
    free(server);
}