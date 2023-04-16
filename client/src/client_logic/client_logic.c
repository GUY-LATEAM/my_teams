/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** client_logic
*/

#include <unistd.h>
#include "signal_management_client.h"
#include "socket_basic_func.h"
#include "client_loop.h"
#include "select_func.h"
#include "server_func.h"
#include "client_func.h"
#include "init_struct.h"
#include "destroy_struct.h"
#include "list_lib.h"
#include "socket_management_func.h"
#include "protocol_logic.h"

int do_myteams_client(char **av)
{
    client_t *client = NULL;

    client = init_client();
    if (!client)
        return (EXIT_FAILURE);
    signal(SIGINT, handle_signal);
    if (create_client_protocol(client,
    av[1], atoi(av[2])) != 0) {
        destroy_client(client);
        return (EXIT_FAILURE);
    }
    while (SIGNAL_FLAG == NOTHING_RECEIVED) {
        loop_client(client);
    }
    apply_signal_action(client);
    destroy_client(client);
    return (EXIT_SUCCESS);
}

void loop_client(client_t *client)
{
    clear_fd_set(&client->network_client->read_fds,
    &client->network_client->write_fds,
    &client->network_client->except_fds);
    set_socket_fdset(STDIN_FILENO, &client->network_client->read_fds,
    NULL, &client->network_client->except_fds);
    set_fds_clients(client->network_client->clients,
    &client->network_client->read_fds,
    &client->network_client->write_fds, &client->network_client->except_fds);
    if (select_socket(client->network_client->max_fd,
    &client->network_client->read_fds,
    &client->network_client->write_fds,
    &client->network_client->except_fds) != 0)
        return;
    server_loop_client(client->network_client);
    manage_input(client);
}
