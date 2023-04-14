/*
** EPITECH PROJECT, 2023
** server
** File description:
** receive_handler
*/

#include "libstr.h"
#include "protocol_logic.h"
#include "logging_server.h"
#include "commands.h"
#include "receive_handler.h"

static const char *commands[] = {
    "help",
    "login",
    "logout",
    "users",
    "user",
    "send",
    "messages",
    "subscribe",
    "subscribed",
    "unsubscribe",
    "use",
    "create",
    "list",
    "info",
    NULL
};

static int get_command(circular_buffer_t *read_buffer, command_t *command)
{
    command->command = my_split(read_buffer->buffer, SP, LEFT);
    if (command->command == NULL) {
        return EXIT_SUCCESS;
    }
    command->args = my_split(read_buffer->buffer, SP, LEFT);
    return EXIT_SUCCESS;
}

int apply_command(void *user_data, void *protocol_data,
    command_t *command, circular_buffer_t *write_buffer)
{
    static int (*command_functions[])(void *, void *, char *) = {
        FUNCTIONS_LIST,
        NULL
    };

    for (int i = 0; commands[i] != NULL; i++) {
        if (strcmp(command->command, commands[i]) == 0) {
            return command_functions[i](user_data, protocol_data,
                command->args);
        }
    }
    return NULL;
}

static void delete_command(command_t *command)
{
    if (command->command != NULL) {
        free(command->command);
    }
    if (command->args != NULL) {
        free(command->args);
    }
}

// if command is null send error in stdin because not error in logging server.h
void receive(void *user_data, void *protocol_data,
    circular_buffer_t *read_buffer, circular_buffer_t *write_buffer)
{
    command_t command = {NULL, NULL};
    int command_result = EXIT_SUCCESS;

    if (get_command(read_buffer, &command) != EXIT_SUCCESS) {
        return;
    }
    command_result = apply_command(user_data, protocol_data,
        &command, write_buffer);
    delete_command(&command);
    return command_result;
}
