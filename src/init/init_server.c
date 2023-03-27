/*
** EPITECH PROJECT, 2023
** init_server.c
** File description:
** init_server.c
*/

#include <stdlib.h>
#include <string.h>
#include "list_lib.h"
#include "server_func.h"
#include "my_teams.h"

server_t *init_server(int port)
{
    server_t *srv = NULL;

    srv = malloc(sizeof(server_t));
    if (!srv)
        return NULL;
    srv->network_server = create_server(port);
    srv->teams = list_create();
    return srv;
}