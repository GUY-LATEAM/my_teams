/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_login_resp
*/

#include <stdio.h>
#include <string.h>
#include "list_lib.h"
#include "signal_management_client.h"
#include "client_func.h"
#include "parse_logic.h"

void parse_no_info(client_t *client, char *response)
{
    char *code = NULL;
    char *status = NULL;
    char *message = NULL;

    status = strtok(response, SP);
    code = strtok(response, SP);
    message = strtok(response, SP);
    if (strcmp(status, "ERROR") == 0 ||
    is_code_valid(code, client->requested_cmd) == false) {
        printf("Error: %s\n", message);
        return;
    }
    printf("Success: %s\n", message);
}

void parse_logout(client_t *client, char *response)
{
    network_client_t *cli;
    parse_no_info(client, response);

    cli = get_list_i_data(client->network_client->clients, 0);
    destroy_network_client(cli);
    remove_list_element(client->network_client->clients, 0);
    SET_SIGNAL_FLAG(SIGINT_RECEIVED);
}
