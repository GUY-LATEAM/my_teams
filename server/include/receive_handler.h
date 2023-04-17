/*
** EPITECH PROJECT, 2023
** server
** File description:
** receive_handler
*/

#ifndef SERVER_RECEIVE_HANDLER_H
    #define SERVER_RECEIVE_HANDLER_H
    #include "network_structures.h"

    #define FUNCTIONS_LIST &help_command,\
        &login_command,\
        &logout_command,\
        &users_command,\
        &user_command,\
        &send_command,\
        &messages_command,\
        &subscribe_command,\
        &subscribed_command,\
        &unsubscribe_command,\
        &use_command,\
        &create_command,\
        &list_command,\
        &info_command

    typedef struct command_s command_t;

    struct command_s {
        char *command;
        char *args;
    };

    void receive(void *user_data, void *protocol_data,
    circular_buffer_t *read_buffer, circular_buffer_t *write_buffer);

    void set_new_con_protocol_logic(server_t *interface);

#endif // SERVER_RECEIVE_HANDLER_H
