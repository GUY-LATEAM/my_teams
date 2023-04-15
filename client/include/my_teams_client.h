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

    enum cmd_e {
        LOGIN,
        LOGOUT,
        USERS,
        USER,
        SEND,
        MESSAGES,
        SUBSCRIBE,
        SUBSCRIBED_USERS,
        SUBSCRIBED_TEAMS,
        UNSUBSCRIBE,
        USE,
        CREATE,
        LIST,
        INFO,
        HELP,
        UNKNOWN
    };

    typedef struct context_s {
        bool team_valid;
        char team_uuid[MAX_UUID_LENGTH + 1];
        bool channel_valid;
        char channel_uuid[MAX_UUID_LENGTH + 1];
        bool thread_valid;
        char thread_uuid[MAX_UUID_LENGTH + 1];
    } context_t;

    typedef struct client_s {
        network_server_t *network_client;
        context_t *context;
        enum cmd_e requested_cmd;
    } client_t;


#endif /* !my_teams_client_h */
