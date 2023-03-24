/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** socket_management_func
*/

#ifndef SOCKET_MANAGEMENT_FUNC_H_
    #define SOCKET_MANAGEMENT_FUNC_H_

    #include "network_structures.h"

    void do_socket_read(network_client_t *client, fd_set *read_fds);
    void do_socket_write(network_client_t *client, fd_set *write_fds);
    void do_socket_except(network_client_t *client, fd_set *except_fds,
        network_server_t *server);

#endif /* !SOCKET_MANAGEMENT_FUNC_H_ */
