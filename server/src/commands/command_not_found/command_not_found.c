/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** command_not_found
*/

#include "commands.h"
#include "protocol_logic.h"

int command_not_found(__attribute__((unused)) void *user_data,
__attribute__((unused)) void *protocol_data, __attribute__((unused)) char *args,
circular_buffer_t *write_buffer)
{
    write_circular_buffer(write_buffer, UNKNOW_COMMAND GUY);
    return EXIT_SUCCESS;
}
