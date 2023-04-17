/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** select_func
*/

#ifndef SELECT_FUNC_H_
    #define SELECT_FUNC_H_

    #include <sys/socket.h>
    #include "struct_list_lib.h"

    void update_max_fd(int *max_fd, int new_socket);
    void find_new_max_fd(int *max_fd,  list_ptr_t *clients);
    int select_socket(int max_fd, fd_set *read_fds,
    fd_set *write_fds, fd_set *except);
    char *read_input_select(fd_set *read_fds);

#endif /* !SELECT_FUNC_H_ */
