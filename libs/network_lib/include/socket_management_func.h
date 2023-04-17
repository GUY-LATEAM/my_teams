/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** socket_management_func
*/

#ifndef SOCKET_MANAGEMENT_FUNC_H_
    #define SOCKET_MANAGEMENT_FUNC_H_

    #include "network_structures.h"

    on_disconnect_error_t do_socket_read(network_client_t *client,
    fd_set *read_fds);
    on_disconnect_error_t do_socket_write(network_client_t *client,
    fd_set *write_fds);
    on_disconnect_error_t do_socket_except(network_client_t *client,
    fd_set *except_fds,
        network_server_t *server);
    void set_fds_clients(list_ptr_t *clients, fd_set *read_fds,
    fd_set *write_fds, fd_set *except_fds);
    void set_fds_client(network_client_t *client, fd_set *read_fds,
        fd_set *write_fds, fd_set *except_fds);
    void clear_fd_set(fd_set *read, fd_set *write, fd_set *except);
#endif /* !SOCKET_MANAGEMENT_FUNC_H_ */
