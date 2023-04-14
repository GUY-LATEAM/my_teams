/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** command_not_found
*/

#include "protocol_logic.h"
#include "commands.h"

int command_not_found(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer)
{
    write_circular_buffer(write_buffer, UNKNOW_COMMAND GUY);
    return EXIT_SUCCESS;
}
