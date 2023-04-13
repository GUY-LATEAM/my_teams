/*
** EPITECH PROJECT, 2023
** server
** File description:
** receive_handler
*/

#ifndef SERVER_RECEIVE_HANDLER_H
  #define SERVER_RECEIVE_HANDLER_H
  #include "network_structures.h"

  typedef struct command_s command_t;

  struct command_s {
    char *command;
    char *args;
  };

void receive(void *user_data, void *protocol_data,
  circular_buffer_t *read_buffer, circular_buffer_t *write_buffer);

#endif // SERVER_RECEIVE_HANDLER_H
