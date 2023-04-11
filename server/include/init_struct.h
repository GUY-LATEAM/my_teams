/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_struct
*/

#ifndef INIT_STRUCT_H_
    #define INIT_STRUCT_H_

    #include "my_teams_server.h"

    user_t *init_user(char *name);
    conversation_t *init_conversation(user_t *user);
    message_t *init_message(char *content);
    reply_t *init_reply(user_t *user, char *content);
    thread_t *init_thread(user_t *user, char *title, char *message);
    channel_t *init_channel(char *name, char *description);
    team_t *init_team(char *name, char *description);
    context_t *init_context(void);
    server_t *init_server(int port);

#endif /* !INIT_STRUCT_H_ */
