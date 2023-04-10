/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** client_func
*/

#include "list_lib.h"
#include "circular_buffer.h"
#include "client_func.h"
#include "socket_basic_func.h"
#include "select_func.h"

bool create_network_client(network_server_t* server,
int buff_size, char *pattern)
{
    network_client_t *client = malloc(sizeof(network_client_t));

    client->read_buffer = create_circular_buffer(buff_size, pattern);
    client->write_buffer = create_circular_buffer(buff_size, pattern);
    client->socket = accept_socket(server->socket);
    client->on_connect = NULL;
    client->on_disconnect = NULL;
    client->send = NULL;
    client->receive = NULL;
    client->user_data = NULL;
    if (client->socket == -1) {
        destroy_network_client(client);
        return false;
    }
    update_max_fd(&server->max_fd, client->socket);
    list_add_last(server->clients, client);
    return true;
}

bool set_network_client_methods_dialogue(
    network_client_t* client, void (*send) (void *, circular_buffer_t *),
    void (*receive)(void *, circular_buffer_t *))
{
    if (client == NULL)
        return false;
    client->send = send;
    client->receive = receive;
    return true;
}

bool set_network_client_methods_connexion(
    network_client_t* client, void (*on_connect)(void *user_data),
    void (*on_disconnect)(void *user_data,
    on_disconnect_error_t error_code))
{
    if (client == NULL)
        return false;
    client->on_connect = on_connect;
    client->on_disconnect = on_disconnect;
    return true;
}
