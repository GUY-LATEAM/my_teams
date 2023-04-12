/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** server_func
*/

#ifndef SERVER_FUNC_H_
    #define SERVER_FUNC_H_

    #include "network_structures.h"

    network_server_t *create_server(int port);
    network_server_t *create_server_client(void);
    void destroy_server_network(network_server_t *server);
    int server_receive_new_con(network_server_t *server, int buff_size,
    const char *pattern);
    void server_loop_client(network_server_t *server);

#endif /* !SERVER_FUNC_H_ */
