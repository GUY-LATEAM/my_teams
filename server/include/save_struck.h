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

#endif /* !save_struck_H */
