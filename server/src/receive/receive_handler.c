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

char *apply_command(void *user_data, void *protocol_data,
    command_t *command, circular_buffer_t *write_buffer)
{
    static int (*command_functions[])(void *, void *, char *) = {
        &help_command,
        &login_command,
        &logout_command,
        &users_command,
        &user_command,
        &send_command,
        &messages_command,
        &subscribe_command,
        &subscribed_command,
        &unsubscribe_command,
        &use_command,
        &create_command,
        &list_command,
        &info_command
    };

    for (int i = 0; commands[i] != NULL; i++) {
        if (strcmp(command->command, commands[i]) == 0) {
            return command_functions[i](user_data, protocol_data, command->args);
        }
    }
}

// if command is null send error in stdin because not error in logging server.h
void receive(void *user_data, void *protocol_data,
    circular_buffer_t *read_buffer, circular_buffer_t *write_buffer)
{
    command_t command = {NULL, NULL};
    char *response = NULL;

    if (get_command(read_buffer, &command) != EXIT_SUCCESS) {
        return;
    }
    response = apply_command(user_data, protocol_data, &command, write_buffer);
    if (command.command != NULL) {
        free(command.command);
    }
    if (command.args != NULL) {
        free(command.args);
    }
}
