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
    void destroy_server(network_server_t *server);
    void server_receive_new_con(network_server_t *server, int buff_size,
    char *pattern);
    void server_loop_client(network_server_t *server);

#endif /* !SERVER_FUNC_H_ */
