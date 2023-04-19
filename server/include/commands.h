/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** commands
*/

#ifndef MY_TEAMS_COMMANDS_H
    #define MY_TEAMS_COMMANDS_H
    #include "circular_buffer.h"
    #include "my_teams_server.h"

    #define CODE_404             "404"
    #define CODE_200             "200"
    #define BROADCAST            "broadcast "
    #define RESPONSE             "OK "
    #define CODE_404 "404"
    #define CODE_200 "200"
    #define UNSUBSCRIBED_BROADCAST "broadcast UNSUBSCRIBE"
    #define SUBSCRIBED_BROADCAST "broadcast SUBSCRIBED"
    #define UNKNOW_COMMAND       "ERROR 400 Unknown command"
    #define MESSAGE_BRDCAST      "broadcast MESSAGE \""
    #define LOGOUT_BROADCAST     "broadcast LOGOUT \""
    #define LOGIN_BROADCAST      "broadcast LOGIN \""
    #define BROADCAST_MARK       "\""
    #define BROADCAST_COLON      ":"
    #define UNDEFINED            "UN"
    #define KO_UUID              "KO"

    int help_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int login_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int logout_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int users_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int user_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int send_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int messages_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int subscribe_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int subscribed_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int unsubscribe_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int use_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int create_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int list_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int info_command(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    int command_not_found(void *user_data, void *protocol_data, char *args,
    circular_buffer_t *write_buffer);
    user_t *find_user(server_t *server, char *uuid);
    int broadcast_teams(server_t *server, team_t *team, const char *message);
    bool broadcast_all_user(server_t *server, const char *message);
    int write_error(
    circular_buffer_t *write_buffer, const char *code, const char *message);
    int write_success(
    circular_buffer_t *write_buffer, const char *code, const char *message);
    int check_is_user_login(
    server_t *server, user_t *user, circular_buffer_t *write_buffer);
    bool is_user_login(server_t *server, const char *name);
    conversation_t *check_is_conversation(user_t *user, char *uuid);
    network_client_t *find_circular_with_id(server_t *server, char *uuid);
    void send_broadcast_new_reply(
    server_t *server, team_t *team, thread_t *thread, user_t *user);
    void send_broadcast_new_thread(
    server_t *server, team_t *team, thread_t *thread, user_t *user);
    void send_broadcast_new_channel(
    server_t *server, team_t *team, channel_t *channel);
    void send_broadcast_new_teams(server_t *server, team_t *team);
    int subscribed_argument(
    server_t *server, char *uuid, circular_buffer_t *write_buffer);
    int subscribed_no_argument(
    server_t *server, user_t *user, circular_buffer_t *write_buffer);
    char *get_subscribe_team_uuid(char *args);
    int subscribed_argument(server_t *server,
    char *uuid, circular_buffer_t *write_buffer);
    int subscribed_no_argument(server_t *server, user_t *user,
    circular_buffer_t *write_buffer);

    // list command
    int list_team(server_t *server, __attribute__((unused)) user_t *user,
    char **args, circular_buffer_t *write_buffer);
    int list_channel(server_t *server, user_t *user, char **args,
    circular_buffer_t *write_buffer);
    int list_thread(server_t *server, user_t *user,
    char **args, circular_buffer_t *write_buffer);
    int list_reply(server_t *server,
    user_t *user, char **args, circular_buffer_t *write_buffer);

    // send response lits command
    void send_response_list_teams(
    server_t *server, circular_buffer_t *write_buffer);
    void send_response_list_channel(
    server_t *server, team_t *team, circular_buffer_t *write_buffer);
    void send_response_list_thread(
    server_t *server, channel_t *team, circular_buffer_t *write_buffer);
    void send_response_list_reply(server_t *server, thread_t *thread,
    circular_buffer_t *write_buffer);
    void send_broadcast_list(
    circular_buffer_t *write_buffer, list_ptr_t *args_list);


    // info utils

    void send_info_logged_in(server_t *serv, char **context,
    circular_buffer_t *write);
    void send_info_current_channel(server_t *serv, char **context,
    circular_buffer_t *write);
    void send_info_current_team(server_t *serv, char **context,
    circular_buffer_t *write);
    void send_info_current_thread(server_t *serv, char **context,
    circular_buffer_t *write);
    bool is_context_channel(char **context);
    bool is_context_team(char **context);
    bool is_context_thread(char **context);
    bool is_context_loggedin_user(char **context);

    team_t *get_team_by_context(char **context, server_t *serv);
    channel_t *get_channel_by_context(char **context, team_t *team);
    thread_t *get_thread_by_context(char **context, channel_t *channel);
    int find_write(network_client_t *client,
        user_t *user, char **tab);
    int broadcast_message(circular_buffer_t *write, char *message,
        char *uuid);
    int add_in_list(network_client_t *client, user_t *user, char **tab);
    int send_message_if(network_client_t *client, user_t *user, char **tab,
        int *check_bool);

#endif //MY_TEAMS_COMMANDS_H
