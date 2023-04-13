/*
** EPITECH PROJECT, 2023
** my_teams_client
** File description:
** my_teams_client
*/

#ifndef my_teams_client_h
    #define my_teams_client_h

    #include "network_structures.h"

    #define MAX_NAME_LENGTH 32
    #define MAX_UUID_LENGTH 36
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    typedef struct context_s {
        char team_uuid[MAX_UUID_LENGTH + 1];
        char channel_uuid[MAX_UUID_LENGTH + 1];
        char thread_uuid[MAX_UUID_LENGTH + 1];
    } context_t;

    typedef struct client_s {
        network_server_t *network_client;
        context_t *context;
        context_t *requested_context;
    } client_t;


#endif /* !my_teams_client_h */
