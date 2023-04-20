/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_struct
*/

#ifndef DESTROY_STRUCT_H_
    #define DESTROY_STRUCT_H_

    #include "my_teams_server.h"

    void destroy_reply(reply_t *reply);
    void destroy_thread(thread_t *thread);
    void destroy_channel(channel_t *channel);
    void destroy_team(team_t *team);

    void destroy_message(message_t *message, char *uuid);
    void destroy_conversation(conversation_t *conversation, char *uuid);
    void destroy_user(user_t *user);

    void destroy_server(server_t *server);

#endif /* !DESTROY_STRUCT_H_ */
