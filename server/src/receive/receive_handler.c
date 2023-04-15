/*
** EPITECH PROJECT, 2023
** server
** File description:
** receive_handler
*/

#include <string.h>
#include "libstr.h"
#include "protocol_logic.h"
#include "logging_server.h"
#include "commands.h"
#include "receive_handler.h"

static const char *commands[] = {"help", "login", "logout", "users", "user",
"send", "messages", "subscribe", "subscribed", "unsubscribe", "use", "create",
"list", "info", NULL};

static char *get_args_before_guy(char *str)
{
    char *guyref = NULL;
    char *result = NULL;
    int len_str = NULL;

    if (str == NULL)
        return NULL;
    len_str = strlen(str);
    if (len_str <= 3)
        return NULL;
    guyref = strstr(str, GUY);
    if (guyref == NULL || guyref != &str[len_str - 3]) {
        return NULL;
    }
    result = malloc(sizeof(char) * (len_str - 2));
    if (result == NULL) {
        return NULL;
    }
    result[len_str - 3] = '\0';
    return strncpy(result, str, len_str - 3);
}

static int get_command(circular_buffer_t *read_buffer, command_t *command)
{
    char *buffer = NULL;
    char *tmp = NULL;

    read_circular_buffer(read_buffer, buffer);
    command->command = my_split(buffer, SP, LEFT);
    if (command->command == NULL) {
        return EXIT_SUCCESS;
    }
    tmp = my_split(buffer, SP, RIGHT);
    command->args = get_args_before_guy(tmp);
    free(tmp);
    free(buffer);
    return EXIT_SUCCESS;
}

static int apply_command(void *user_data, void *protocol_data,
command_t *command, circular_buffer_t *write_buffer)
{
    static int (*command_functions[])
        (void *, void *, char *, circular_buffer_t *) = {FUNCTIONS_LIST, NULL};

    for (int i = 0; commands[i] != NULL; i++) {
        if (strcmp(command->command, commands[i]) == 0) {
            return command_functions[i](
            user_data, protocol_data, command->args, write_buffer);
        }
    }
    return EXIT_FAILURE;
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

void receive(void *user_data, void *protocol_data,
circular_buffer_t *read_buffer, circular_buffer_t *write_buffer)
{
    command_t command = {NULL, NULL};

    if (get_command(read_buffer, &command) != EXIT_SUCCESS) {
        command_not_found(user_data, protocol_data, NULL, write_buffer);
        return;
    }
    if (apply_command(user_data, protocol_data, &command, write_buffer)) {
        command_not_found(user_data, protocol_data, NULL, write_buffer);
    }
    delete_command(&command);
}
