/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** read_input
*/

#include <string.h>
#include "manage_response_client.h"
#include "protocol_logic.h"

//manage_cmd_client(protocol_data, data, write);

void receive_client(void *user_data, void *protocol_data,
circular_buffer_t *read, circular_buffer_t *write)
{
    char *data = NULL;

    if (user_data != protocol_data)
        return;
    read_circular_buffer(read, data);
    if (strstr(data, "OK") != NULL || strstr(data, "ERROR") != NULL) {
        manage_response(protocol_data, data);
    } else {
        return;
    }
}
