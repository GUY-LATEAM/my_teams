/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_client_protocol
*/

#include <stdio.h>
#include "client_func.h"
#include "my_teams_client.h"
#include "server_func.h"
#include "list_lib.h"
#include "protocol_logic.h"
#include "socket_manipulation.h"
#include "protocol_func.h"

int create_client_protocol(client_t *client, char *ip, int port)
{
    network_client_t *cli = NULL;

    cli = create_client(BUFF_SIZE,  GUY);
    if (cli == NULL)
        return EXIT_FAILURE;
    if (!connect_network_client(cli, ip, port)) {
        printf("Connection failed\n");
        return EXIT_FAILURE;
    }
    set_network_client_methods_dialogue(cli, &receive_client);
    list_add_last(client->network_client->clients, cli);
    set_network_client_methods_connexion(cli, NULL, on_disconnect_client);
    cli->user_data = NULL;
    cli->protocol_data = client;
    client->network_client->max_fd = cli->socket;
    return EXIT_SUCCESS;
}
