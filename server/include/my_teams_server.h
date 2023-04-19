/*
** EPITECH PROJECT, 2023
** my_teams_server.h
** File description:
** my_teams_server.h
*/

#ifndef MY_TEAMS_H_
    #define MY_TEAMS_H_

    #include <sys/select.h> // Pour les fd_set
    #include <netinet/in.h> // Pour les strucs sockaddr
    #include "list_lib.h" // Pour la lib list
    #include "network_structures.h"

    #define EXIT_EPITECH 84
    #define MAX_NAME_LENGTH 32
    #define MAX_UUID_LENGTH 36
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    typedef struct user_s {
        char uuid[MAX_UUID_LENGTH + 1];
        char name[MAX_NAME_LENGTH + 1]; // +1 for the null terminator
        int nb_users;
        list_ptr_t *conversations;
        time_t timestamp;
    } user_t;

    typedef struct conversation_s {
        char uuid_create[MAX_UUID_LENGTH + 1];
        list_ptr_t *messages; // Liste de messages
        time_t timestamp;
    } conversation_t;

    typedef struct message_s {
        char content[MAX_BODY_LENGTH + 1];
        char uuid[MAX_UUID_LENGTH + 1]; // uid du message
        time_t timestamp;
    } message_t;

    typedef struct reply_s {
        char uuid[MAX_UUID_LENGTH];
        char uuid_create[MAX_UUID_LENGTH + 1];
        char content[MAX_BODY_LENGTH + 1];
        time_t timestamp;
    } reply_t;

    typedef struct thread_s {
        char uuid[MAX_UUID_LENGTH + 1];
        char uuid_create[MAX_UUID_LENGTH + 1];
        char title[MAX_NAME_LENGTH + 1];
        char message[MAX_BODY_LENGTH + 1];
        list_ptr_t *replies;
        time_t timestamp;
    } thread_t;

    typedef struct channel_s {
        char uuid[MAX_UUID_LENGTH + 1];
        char uuid_create[MAX_UUID_LENGTH + 1];
        char name[MAX_NAME_LENGTH + 1];
        char description[MAX_DESCRIPTION_LENGTH + 1];
        list_ptr_t *threads;
        time_t timestamp;
    } channel_t;

    typedef struct team_s {
        char uuid[MAX_UUID_LENGTH + 1];
        char name[MAX_NAME_LENGTH + 1];
        char description[MAX_DESCRIPTION_LENGTH + 1];
        list_ptr_t *subscribed_users;
        list_ptr_t *channels;
        time_t timestamp;
    } team_t;

    typedef struct context_s {
        char team_uuid[MAX_UUID_LENGTH + 1];
        char channel_uuid[MAX_UUID_LENGTH + 1];
        char thread_uuid[MAX_UUID_LENGTH + 1];
    } context_t;

    typedef struct server_s {
        network_server_t *network_server;
        list_ptr_t *teams;
        list_ptr_t *all_users;
        time_t timestamp;
    } server_t;

#endif /* !MY_TEAMS_H_ */
