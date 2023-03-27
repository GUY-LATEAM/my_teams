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

void find_new_max_fd(int *max_fd, list_ptr_t *clients)
{
    network_client_t *client = NULL;

    for (int i = 0; i < clients->len; i++) {
        client = get_list_i_data(clients, i);
        update_max_fd(max_fd, client->socket);
    }
}

int select_socket(int max_fd, fd_set *read_fds,
fd_set *write_fds, fd_set *except)
{
    int activity;

    activity = select(max_fd + 1, read_fds, write_fds, except, NULL);

    if (activity < 0) {
        printf("Error: Fail to select\n");
        return (-1);
    }
    return (0);
}
