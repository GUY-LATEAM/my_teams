/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_struct
*/

#ifndef INIT_STRUCT_H_
    #define INIT_STRUCT_H_

    #include "my_teams_server.h"

    channel_t *init_channel(char *user_create, char *name, char *description);
    context_t *init_context(void);
    conversation_t *init_conversation(char *user_create);
    message_t *init_message(char *content, char *create_uuid);
    reply_t *init_reply(char *user_create, char *content);
    server_t *init_server(int port);
    team_t *init_team(char *name, char *description);
    thread_t *init_thread(char *user_create, char *title, char *message);
    user_t *init_user(char *name);

#endif /* !INIT_STRUCT_H_ */
