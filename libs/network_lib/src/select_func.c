/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** select_func
*/

#include <stdio.h>
#include <unistd.h>
#include "list_lib.h"
#include "select_func.h"
#include "network_structures.h"

void update_max_fd(int *max_fd, int new_socket)
{
    if (*max_fd < new_socket)
        *max_fd = new_socket;
}

void find_new_max_fd(int *max_fd, list_ptr_t *clients,
int socket_serv)
{
    network_client_t *client = NULL;
    int new_max = 0;

    for (int i = 0; i < clients->len; i++) {
        client = get_list_i_data(clients, i);
        if (new_max < client->socket)
            new_max = client->socket;
    }
    if (new_max < socket_serv)
        *max_fd = socket_serv;
    else
        *max_fd = new_max;
}

int select_socket(int max_fd, fd_set *read_fds,
fd_set *write_fds, fd_set *except)
{
    int activity;

    activity = select(max_fd + 1, read_fds, write_fds, except, NULL);

    if (activity < 0) {
        return (-1);
    }
    return (0);
}
