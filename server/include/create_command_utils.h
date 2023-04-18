/*
** EPITECH PROJECT, 2023
** server
** File description:
** create_command_utils
*/

#ifndef SERVER_CREATE_COMMAND_UTILS_H
    #define SERVER_CREATE_COMMAND_UTILS_H

    #include "init_struct.h"

    int create_team(
    server_t *server, __attribute__((unused)) user_t *user, char **args);
    int create_channel(server_t *server, user_t *user, char **args);
    int create_thread(server_t *server, user_t *user, char **args);
    int create_reply(server_t *server, user_t *user, char **args);

#endif // SERVER_CREATE_COMMAND_UTILS_H
