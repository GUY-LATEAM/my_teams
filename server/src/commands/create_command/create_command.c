/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** create_command
*/

#include "add_struct.h"
#include "commands.h"
#include "circular_buffer.h"

int create_command(void *user_data,
__attribute__((unused)) void *protocol_data, __attribute__((unused)) char *args,
circular_buffer_t *write_buffer)
{
    server_t *server = NULL;

    if (user_data == NULL) {
        write_error(write_buffer, "401", "The client needs to authenticate");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
