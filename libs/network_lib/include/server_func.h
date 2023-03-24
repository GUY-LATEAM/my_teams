/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** server_func
*/

#ifndef SERVER_FUNC_H_
    #define SERVER_FUNC_H_

    #include "network_structures.h"

    network_server_t *create_server(int port);
    void destroy_server(network_server_t *server);
    void server_loop(network_server_t *server, int buff_size, char *pattern);

#endif /* !SERVER_FUNC_H_ */
