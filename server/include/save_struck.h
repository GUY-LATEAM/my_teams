/*
** EPITECH PROJECT, 2023
** save_struck.h
** File description:
** save_struck.h
*/

#ifndef save_struck_H
    #define save_struck_H

    #define  SERVER_FILEPATH "data/server.txt"
    #define  USERS_FILEPATH "data/users.txt"

    #include <stdio.h>
    #include <string.h>
    #include "list_lib.h"
    #include "my_teams_server.h"

    bool save_channel_loop(list_ptr_t *channels, FILE *file, const char sep);
    bool save_reply_loop(list_ptr_t *replies, FILE *file, const char sep);
    bool save_server_to_file(list_ptr_t *teams, const char *filename);
    bool save_team_loop(list_ptr_t *teams, FILE *file, const char sep);
    bool save_thread_loop(list_ptr_t *threads, FILE *file, const char sep);
    list_ptr_t *create_conversation_list_from_line(char *conv_info,
    const char sep);
    list_ptr_t *create_message_list_from_line(char *message_info,
    char const sep);
    bool load_user_loop(list_ptr_t *users, FILE *file, const char sep);
    bool load_users_from_file(list_ptr_t *users, const char *filename);
    bool save_conversation_loop(list_ptr_t *conversation, FILE *file,
    const char sep);
    bool save_message_loop(list_ptr_t *messages, FILE *file, const char sep);
    bool save_user_loop(list_ptr_t *users, FILE *file, const char sep);
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

    list_ptr_t *create_channel_list_from_line(char *line, const char sep);
    list_ptr_t *create_reply_list_from_line(char *line, const char sep);
    bool load_server_from_file(list_ptr_t *teams, const char *filename);
    bool load_teams_loop(list_ptr_t *teams, FILE *file, const char sep);
    list_ptr_t *create_thread_list_from_line(char *line, const char sep);
    list_ptr_t *create_user_list_from_line(char *line, const char sep);

    void free_tokens(char **tokens);
    void remove_newline(char *str);

    size_t count_tokens(char *str, const char separator);
    char **malloc_tokens(size_t count);
    void fill_tokens(char **tokens, char *str, const char separator,
    size_t count);
    bool duplication_string(char *line, char **str, char **tmp);
    bool load_file_data(server_t *server, const char *filepath_user,
    const char *filepath_server);

#endif /* !save_struck_H */
