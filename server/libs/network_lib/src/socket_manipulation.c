/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** socket_manipulation
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "socket_manipulation.h"

int read_socket(int socket, circular_buffer_t *read_buff)
{
    char *buffer = NULL;
    int read_size = 0;

    buffer = malloc(sizeof(char) * (read_buff->size + 1));
    if (buffer == NULL)
        return (-1);
    memset(buffer, 0, read_buff->size + 1);
    read_size = read(socket, buffer, read_buff->size);
    if (read_size <= 0)
        return (read_size);
    buffer[read_size] = '\0';
    write_circular_buffer(read_buff, buffer);
    return (read_size);
}

int write_socket(int socket, circular_buffer_t *write_buff)
{
    char *buffer = NULL;
    int write_size = 0;

    buffer = malloc(sizeof(char) * (write_buff->size + 1));
    if (buffer == NULL)
        return (-1);
    memset(buffer, 0, write_buff->size + 1);
    write_size = read_circular_buffer(write_buff, buffer);
    if (write_size <= 0)
        return (write_size);
    buffer[write_size] = '\0';
    write_size = write(socket, buffer, write_size);
    return (write_size);
}
