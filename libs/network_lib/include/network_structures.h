/*
** EPITECH PROJECT, 2023
** Network_Lib
** File description:
** network_structures
*/

#ifndef NETWORK_STRUCTURES_H_
    #define NETWORK_STRUCTURES_H_

    #include <sys/select.h>
    #include "circular_buffer.h"
    #include "struct_list_lib.h"

    typedef enum on_disconnect_error_e {
        NO_ERROR,
        DISCONNECTED,
        SOCKET_ERROR,
        MAX_ENUM
    } on_disconnect_error_t;

    typedef struct network_server_s {
        int socket;
        int max_fd;
        fd_set read_fds;
        fd_set write_fds;
        fd_set except_fds;
        list_ptr_t *clients;
    } network_server_t;

    typedef struct network_client_s {
        int socket;

        circular_buffer_t *read_buffer;
        circular_buffer_t *write_buffer;

        void *user_data;
        void *protocol_data;

        void (*receive)(void *user_data, void *protocol_data,
        circular_buffer_t *read_buffer, circular_buffer_t *write_buffer);
        void (*on_disconnect)(void *user_data, void *protocol_data,
        on_disconnect_error_t error_code);
        void (*on_connect)(void *protocol_data);
    } network_client_t;

#endif /* !NETWORK_STRUCTURES_H_ */
