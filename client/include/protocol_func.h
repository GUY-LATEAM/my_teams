/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** protocol_logic
*/

#ifndef PROTOCOL_LOGIC_H
    #define PROTOCOL_LOGIC_H

    #include "circular_buffer.h"
    #include "protocol_logic.h"

void receive_client(void *user_data, void *protocol_data,
                    circular_buffer_t *read, circular_buffer_t *write);
void on_disconnect_client(void *user_data, void *protocol_data,
on_disconnect_error_t error_code);

#endif //PROTOCOL_LOGIC_H
