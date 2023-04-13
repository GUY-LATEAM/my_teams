/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_client_protocol
*/

#include <stdio.h>
#include "client_func.h"
#include "server_func.h"
#include "list_lib.h"
#include "protocol_logic.h"
#include "socket_manipulation.h"

int create_client_protocol(network_server_t *client, char *ip, int port)
{
    network_client_t *cli = NULL;

    cli = create_client(BUFF_SIZE,  GUY);
    if (cli == NULL)
        return EXIT_FAILURE;
    if (!connect_network_client(cli, ip, port)) {
        printf("Connection failed\n");
        return EXIT_FAILURE;
    }
    list_add_last(client->clients, cli);
    client->max_fd = cli->socket;
    return EXIT_SUCCESS;
}
