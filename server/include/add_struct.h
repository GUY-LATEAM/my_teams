/*
** EPITECH PROJECT, 2023
** add_struct.h
** File description:
** add_struct.h
*/

#ifndef add_struct_H
    #define add_struct_H

    #include "my_teams_server.h"
    #include <stdbool.h>

    bool add_conversation_to_user(user_t *user, conversation_t *conversation);
    bool add_message_to_conversation(conversation_t *conversation,
    message_t *message);
    bool add_reply_to_thread(thread_t *thread, reply_t *reply);
    bool add_user_to_conversation(conversation_t *conversation, user_t *user);
    bool add_user_to_server(server_t *server, user_t *user);
    bool add_user_to_team(team_t *team, user_t *user);
    channel_t *create_and_add_channel(team_t *team, user_t *user, char *name,
    char *description);
    reply_t *create_and_add_reply(thread_t *thread, user_t *user,
    char *content);
    team_t *create_and_add_team(server_t *server, char *name,
    char *description);
    thread_t *create_and_add_thread(channel_t *channel, user_t *user,
    char *title, char *message);

#endif /* !add_struct_H */
