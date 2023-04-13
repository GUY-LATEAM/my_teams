/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_client_protocole
*/

#include "client_func.h"
#include "server_func.h"
#include "list_lib.h"
#include <stdio.h>

static const char GUY[] = "\x67\x75\x79";

int create_client_protocol(network_server_t *client, char *ip, int port)
{
    network_client_t *cli = NULL;

    cli = create_client(1024,  GUY);
    if (cli == NULL)
        return -1;
    if (!connect_network_client(cli, ip, port)) {
        printf("Connection failed\n");
        return -1;
    }
    list_add_last(client->clients, cli);
    client->max_fd = cli->socket;
    return 0;
}
