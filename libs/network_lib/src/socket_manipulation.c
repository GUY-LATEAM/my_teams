/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** socket_manipulation
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socket_manipulation.h"

int read_socket(int socket, circular_buffer_t *read_buff)
{
    int read_size = 0;
    char buffer[BUFF_SIZE];

    read_size = read(socket, buffer, BUFF_SIZE);
    buffer[read_size] = '\0';
    if (read_size <= 0)
        return (read_size);
    write_circular_buffer(read_buff, buffer);
    return (read_size);
}

int write_socket(int socket, circular_buffer_t *write_buff)
{
    char buffer[BUFF_SIZE];
    int write_size = 0;

    memset(buffer, 0, BUFF_SIZE);
    write_size = read_circular_buffer(write_buff, buffer);
    if (write_size <= 0) {
        return (write_size);
    }
    write_size = write(socket, buffer, write_size);
    return (write_size);
}
