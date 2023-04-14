/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** commands
*/

#ifndef MY_TEAMS_COMMANDS_H
    #define MY_TEAMS_COMMANDS_H
    #include "circular_buffer.h"

    #define UNKNOW_COMMAND "ERROR 400 Unknown command"

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
    int commmand_not_found(void *user_data, void *protocol_data, char *args,
        circular_buffer_t *write_buffer);
#endif //MY_TEAMS_COMMANDS_H
