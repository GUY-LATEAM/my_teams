/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** read_input
*/

#include <string.h>
#include "manage_response_client.h"
#include "cmd_client_manager.h"
#include "protocol_logic.h"
#include "socket_manipulation.h"

void receive_client(__attribute__((unused)) void *user_data,
void *protocol_data, circular_buffer_t *read,
__attribute__((unused)) circular_buffer_t *write)
{
    char data[BUFF_SIZE] = {0};

    size_t sized = read_circular_buffer(read, data);
    printf("Read data : %s, %d\n", data, sized);
    if (strstr(data, "OK") != NULL || strstr(data, "ERROR") != NULL) {
        manage_response(protocol_data, data);
    } else {
        manage_cmd_client(data);
    }
}
