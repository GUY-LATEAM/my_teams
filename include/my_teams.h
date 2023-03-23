/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** my_teams
*/

#ifndef MY_TEAMS_H_
    #define MY_TEAMS_H_
    #define EXIT_EPITECH 84

#include <sys/select.h> // Pour les fd_set
#include <netinet/in.h> // Pour les strucs sockaddr
#include "list_lib.h" // Pour la lib list

#define MAX_NAME_LENGTH 32
#define MAX_UUID_LENGTH 37
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef struct user_s {
    char uuid[MAX_UUID_LENGTH];
    char name[MAX_NAME_LENGTH + 1]; // +1 for the null terminator
    int socket_fd;
} user_t;

typedef struct reply_s {
    char uuid[MAX_UUID_LENGTH];
    char content[MAX_BODY_LENGTH + 1];
} reply_t;

typedef struct thread_s {
    char uuid[MAX_UUID_LENGTH];
    char title[MAX_NAME_LENGTH + 1];
    char message[MAX_BODY_LENGTH + 1];
    list_ptr_t *replies;
} thread_t;

typedef struct channel_s {
    char uuid[MAX_UUID_LENGTH];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    list_ptr_t *threads;
} channel_t;

typedef struct team_s {
    char uuid[MAX_UUID_LENGTH];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    list_ptr_t *channels;
} team_t;

typedef struct context_s {
    char team_uuid[MAX_UUID_LENGTH];
    char channel_uuid[MAX_UUID_LENGTH];
    char thread_uuid[MAX_UUID_LENGTH];
} context_t;

typedef struct server_s {
    int fd_server;
    int port;
    int max_clients;
    int max_fd;
    fd_set readfds;
    fd_set writefds;
    list_ptr_t *users;
    list_ptr_t *teams;
} server_t;

typedef struct client_s {
    int socket_fd;
    struct sockaddr_in addr;
    user_t *user;//(NULL si non connecté)
    context_t context;// Le contexte actuel du client pour les commandes en gros /use
} client_t;

typedef struct app_s { // honnetement je sais pas si c'est utile
    server_t server;
    list_ptr_t *clients;
} app_t;


#endif /* !MY_TEAMS_H_ */
