/*
** EPITECH PROJECT, 2023
** save_struck.h
** File description:
** save_struck.h
*/

#ifndef save_struck_H
    #define save_struck_H

    #include <stdio.h>
    #include "list_lib.h"
    #include "my_teams_server.h"

    bool save_conversation(conversation_t *conversation, FILE *file);
    bool save_conversation_loop(list_ptr_t *conversation, FILE *file);
    bool save_message(message_t *message, FILE *file);
    bool save_message_loop(list_ptr_t *messages, FILE *file);
    bool save_user(user_t *user, FILE *file);
    bool save_user_loop(list_ptr_t *users, FILE *file);
    bool save_server_data(server_t *server, const char *users_filename,
    const char *teams_filename);
    bool clear_file_content(const char *filename);
    bool save_users_to_file(list_ptr_t *users, const char *filename);
    char *time_to_string(time_t timestamp);
    time_t string_to_time(const char *timestamp_str);

    bool save_server_to_file(list_ptr_t *teams, const char *filename);
    bool save_team_loop(list_ptr_t *teams, FILE *file);
    bool save_team(team_t *team, FILE *file);
    bool save_sub_user_loop(list_ptr_t *users, FILE *file);
    bool save_channel_loop(list_ptr_t *channels, FILE *file);
    bool save_channel(channel_t *channel, FILE *file);
    bool save_thread_loop(list_ptr_t *threads, FILE *file);
    bool save_thread(thread_t *thread, FILE *file);
    bool save_reply_loop(list_ptr_t *replies, FILE *file);
    bool save_reply(reply_t *reply, FILE *file);

#endif /* !save_struck_H */
