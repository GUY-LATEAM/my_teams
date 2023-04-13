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
    char buffer[1024];

    printf("read_socket\n");
    read_size = read(socket, buffer, 1024);
    buffer[read_size] = '\0';
    printf("read_size: %s\n", buffer);
    printf("read_size: %d\n", read_size);
    if (read_size <= 0)
        return (read_size);
    write_circular_buffer(read_buff, buffer);
    return (read_size);
}

int write_socket(int socket, circular_buffer_t *write_buff)
{
    char buffer[1024];
    int write_size = 0;

    memset(buffer, 0, 1024);
    write_size = read_circular_buffer(write_buff, buffer);
    if (write_size <= 0) {
        return (write_size);
    }
    printf("write_size: %s\n", buffer);
    write_size = write(socket, buffer, write_size);
    return (write_size);
}
