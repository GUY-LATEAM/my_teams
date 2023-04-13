/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** socket_manipulation
*/

#ifndef SOCKET_MANIPULATION_H_
    #define SOCKET_MANIPULATION_H_

    #include "circular_buffer.h"

    #define BUFF_SIZE 1024

    int write_socket(int socket, circular_buffer_t *write_buff);
    int read_socket(int socket, circular_buffer_t *read);

#endif /* !SOCKET_MANIPULATION_H_ */
