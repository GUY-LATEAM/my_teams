/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** send_command
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "libstr.h"
#include "logging_server.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

int broadcast_message(circular_buffer_t *write, char *message,
char *uuid)
{
    char *message_to_send = NULL;

    message_to_send = malloc(sizeof(char) * (strlen(message) + \
    strlen(uuid) + strlen(MESSAGE_BRDCAST) + strlen(GUY) + \
    strlen(BROADCAST_MARK) + strlen(BROADCAST_COLON) + 1));
    if (message_to_send == NULL)
        return EXIT_FAILURE;
    sprintf(message_to_send, "broadcast MESSAGE \"%s:%s\"%s", uuid,
    message, GUY);
    if (write_circular_buffer(write, message_to_send) == false)
        return EXIT_FAILURE;
    free(message_to_send);
    return EXIT_SUCCESS;
}

static int add_message_struct(server_t *server, user_t *user, char **tab)
{
    network_client_t *client = NULL;
    int check_bool = 0;

    for (int i = 0; i < server->network_server->clients->len; i++) {
        client = get_list_i_data(server->network_server->clients, i);
        if (client == NULL)
            continue;
        if (send_message_if(client, user, tab, &check_bool) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static char **create_args(char *args)
{
    char **tab = NULL;

    tab = str_to_word_array(args, "\":");
    if (tab == NULL || tab[0] == NULL || tab[1] == NULL) {
        return NULL;
    }
    return tab;
}

int proced_command(server_t *server, void *user_data, char *args,
circular_buffer_t *write_buffer)
{
    char **tab = NULL;

    tab = create_args(args);
    if (tab == NULL) {
        write_error(write_buffer, "500", "Internal Server Error: An \
error occurred on the server side while processing the command.");
        return EXIT_FAILURE;
    }
    if (add_message_struct(server, (user_t *)user_data,
    tab) == EXIT_FAILURE) {
        write_error(write_buffer, "404", "Not Found: The user does not \
exist.");
        free(tab);
        return EXIT_FAILURE;
    }
    free(tab);
    return EXIT_SUCCESS;
}

int send_command( void *user_data, void *protocol_data, char *args,
__attribute__((unused)) circular_buffer_t *write_buffer)
{
    server_t *server = NULL;

    server = (server_t *) protocol_data;
    if (check_is_user_login(server,
    (user_t *) user_data, write_buffer) == EXIT_FAILURE) {
        return EXIT_SUCCESS;
    }
    if (proced_command(server, user_data, args,
    write_buffer) == EXIT_FAILURE) {
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
