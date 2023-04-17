/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** socket_basic_func
*/

#ifndef SOCKET_BASIC_FUNC_H_
    #define SOCKET_BASIC_FUNC_H_

    #include "network_structures.h"

    int create_socket(void);
    int bind_socket(int socket_fd, int port);
    int listen_socket(int socket_fd);
    int accept_socket(int socket_fd);
    void set_socket_fdset(int socket, fd_set *read_fds,
    fd_set *write_fds, fd_set *except_fds);
    int connect_socket(int socket_fd, char *ip, int port);

#endif /* !SOCKET_BASIC_FUNC_H_ */
