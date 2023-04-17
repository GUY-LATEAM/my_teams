/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** new_con_func
*/

#include "my_teams_server.h"
#include "list_lib.h"
#include "client_func.h"
#include "receive_handler.h"

void set_new_con_protocol_logic(server_t *serv)
{
    network_client_t *new_con = NULL;

    new_con = get_list_i_data(serv->network_server->clients,
    serv->network_server->clients->len - 1);
    new_con->user_data = NULL;
    new_con->protocol_data = serv;

    set_network_client_methods_dialogue(new_con, &receive);
}
