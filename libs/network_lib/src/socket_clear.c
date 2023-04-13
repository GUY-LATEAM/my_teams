/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** socket_clear
*/

#include "socket_management_func.h"

void clear_fd_set(fd_set *read, fd_set *write, fd_set *except)
{
    FD_ZERO(read);
    FD_ZERO(write);
    FD_ZERO(except);
}
