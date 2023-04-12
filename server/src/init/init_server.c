/*
** EPITECH PROJECT, 2023
** init_server.c
** File description:
** init_server.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list_lib.h"
#include "server_func.h"
#include "server_events.h"
#include "my_teams_server.h"

server_t *init_server(int port)
{
    server_t *srv = NULL;

    srv = malloc(sizeof(server_t));
    if (!srv)
        return NULL;
    srv->network_server = create_server(port);
    if (!srv->network_server)
        return NULL;
    srv->teams = list_create();
    srv->all_users = list_create();
    if (srv->send_event = init_events()) {
        fprintf(stderr, "Error: init_events failed\n");
        return NULL;
    }
    return srv;
}
