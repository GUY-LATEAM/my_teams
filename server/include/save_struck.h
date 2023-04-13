/*
** EPITECH PROJECT, 2023
** save_struck.h
** File description:
** save_struck.h
*/

#ifndef save_struck_H
    #define save_struck_H

    #include <stdio.h>
    #include <string.h>
    #include "list_lib.h"
    #include "my_teams_server.h"

    bool save_channel_loop(list_ptr_t *channels, FILE *file, char sep);
    bool save_reply_loop(list_ptr_t *replies, FILE *file, char sep);
    bool save_server_to_file(list_ptr_t *teams, const char *filename);
    bool save_team_loop(list_ptr_t *teams, FILE *file, char sep);
    bool save_thread_loop(list_ptr_t *threads, FILE *file, char sep);
    list_ptr_t *create_conversation_list_from_line(char *conv_info,
    char sep);
    list_ptr_t *create_message_list_from_line(char *message_info, char sep);
    bool load_user_loop(list_ptr_t *users, FILE *file, char sep);
    bool load_users_from_file(list_ptr_t *users, const char *filename);
    bool save_conversation_loop(list_ptr_t *conversation, FILE *file,
    char sep);
    bool save_message_loop(list_ptr_t *messages, FILE *file, char sep);
    bool save_user_loop(list_ptr_t *users, FILE *file, char sep);
    bool save_users_to_file(list_ptr_t *users, const char *filename);
    bool save_server_data(server_t *server, const char *users_filename,
    const char *teams_filename);
    bool load_server_data(server_t *server, const char *users_filename,
    const char *teams_filename);
    bool clear_file_content(const char *filename);
    char **str_split(char *line, const char separator);
    char *time_to_string(time_t timestamp);
    time_t string_to_time(const char *timestamp_str);
    bool is_file_not_empty(const char *filename);

#endif /* !save_struck_H */
