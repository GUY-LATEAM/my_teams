/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_struct
*/

#ifndef INIT_STRUCT_H_
    #define INIT_STRUCT_H_

    #include "my_teams_client.h"

    client_t *init_client(void);
    context_t *init_context(void);
    void create_client_protocol(network_server_t *client, char *ip, int port);

#endif /* !INIT_STRUCT_H_ */
