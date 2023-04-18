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
        SUBSCRIBED,
        SUBSCRIBED_USERS,
        SUBSCRIBED_TEAMS,
        UNSUBSCRIBE,
        USE,
        CREATE,
        CREATE_TEAM,
        CREATE_CHANNEL,
        CREATE_THREAD,
        CREATE_REPLY,
        LIST,
        LIST_TEAM,
        LIST_CHANNEL,
        LIST_THREAD,
        LIST_REPLY,
        INFO,
        INFO_TEAM,
        INFO_CHANNEL,
        INFO_THREAD,
        INFO_USER,
        HELP,
        UNKNOWN
    };

    enum context_state_e {
        UNKNOWN_CTX,
        VALID_CTX,
        INVALID_CTX,
    };

    typedef struct context_s {
        enum context_state_e team_valid;
        char team_uuid[MAX_UUID_LENGTH + 1];
        enum context_state_e channel_valid;
        char channel_uuid[MAX_UUID_LENGTH + 1];
        enum context_state_e thread_valid;
        char thread_uuid[MAX_UUID_LENGTH + 1];
    } context_t;

    typedef struct client_s {
        network_server_t *network_client;
        context_t *context;
        enum cmd_e requested_cmd;
    } client_t;


#endif /* !my_teams_client_h */
