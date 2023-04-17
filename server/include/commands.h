/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** commands
*/

#ifndef MY_TEAMS_COMMANDS_H
    #define MY_TEAMS_COMMANDS_H
    #include "circular_buffer.h"
    #include "my_teams_server.h"

    #define CODE_404 "404"
    #define CODE_200 "200"
    #define SUBSCRIBED_BROADCAST "broadcast SUBSCRIBED"
    #define UNKNOW_COMMAND "ERROR 400 Unknown command"
    #define LOGOUT_BROADCAST "broadcast LOGOUT \""
    #define LOGIN_BROADCAST "broadcast LOGIN \""
    #define BROADCAST_MARK "\""
    #define BROADCADT_COLON ":"

    int help_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int login_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int logout_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int users_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int user_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int send_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int messages_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int subscribe_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int subscribed_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int unsubscribe_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int use_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int create_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int list_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int info_command(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    int command_not_found(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
    user_t *find_user(server_t *server, char *uuid);
    bool broadcast_teams(server_t *server, user_t *user, const char *message);
    bool broadcast_all_user(server_t *server, const char *message);
    int write_error(circular_buffer_t *write_buffer, const char *code,
        const char *message);
    int write_success(circular_buffer_t *write_buffer, const char *code,
        const char *message);
    int check_is_user_login(server_t *server, user_t *user,
        circular_buffer_t *write_buffer);
    bool is_user_login(server_t *server, const char *name);
#endif //MY_TEAMS_COMMANDS_H
