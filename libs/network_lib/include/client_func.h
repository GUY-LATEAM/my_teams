/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** client_func
*/

#ifndef CLIENT_FUNC_H_
    #define CLIENT_FUNC_H_

    #include <stdbool.h>
    #include "network_structures.h"
    #include "circular_buffer.h"

    // Create a client

    network_client_t *create_client(int buff_size, const char *pattern);

    bool set_network_client_methods_dialogue(
        network_client_t* client,
        void (*receive)(void *, void *, circular_buffer_t *, circular_buffer_t *));

    bool set_network_client_methods_connexion(
        network_client_t* client, void (*on_connect)(void *user_data),
        void (*on_disconnect)(void *user_data, void *protocol_data,
        on_disconnect_error_t error_code));

    // Destroy a client

    void destroy_network_client(network_client_t *client);
    bool delete_network_client_serv(network_server_t* server, int client_id);
    bool delete_all_network_clients_serv(network_server_t* server);

    // Misc client

    bool connect_network_client(network_client_t* client, char* ip, int port);
    bool accept_network_client(network_server_t* server,
    network_client_t* client);

#endif /* !CLIENT_FUNC_H_ */
