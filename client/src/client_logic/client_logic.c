/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** client_logic
*/

#include "signal_management_client.h"
#include "socket_basic_func.h"
#include "client_loop.h"
#include "select_func.h"
#include "server_func.h"
#include "client_func.h"
#include "init_struct.h"
#include "destroy_struct.h"
#include "list_lib.h"
#include "protocol_logic.h"

int do_myteams_client(char **av)
{
    client_t *client = init_client();

    if (!client)
        return (84);
    signal(SIGINT, handle_signal);
    create_client_protocol(client->network_client, av[1], atoi(av[2]));
    while (get_signal_flag() == NOTHING_RECEIVED) {
        loop_client(client);
    }
    apply_signal_action(client);
    destroy_client(client);
    return (0);
}

void loop_client(client_t *client)
{
    set_socket_fdset(client->network_client);
    if (select_socket(client->network_client->max_fd,
    &client->network_client->read_fds,
    &client->network_client->write_fds,
    &client->network_client->except_fds) != 0)
        return;
    server_loop_client(client->network_client);
    manage_input(client);
}
