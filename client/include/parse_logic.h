/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_logic
*/

#ifndef PARSE_LOGIC_H_
    #define PARSE_LOGIC_H_

    #include "protocol_logic.h"

    // Parsing functions

    void parse_create_channel(client_t *client, char *args);
    void parse_create_team(client_t *client, char *args);
    void parse_create_thread(client_t *client, char *args);
    void parse_create_reply(client_t *client, char *args);
    void parse_info_channel(client_t *client, char *args);
    void parse_info_team(client_t *client, char *args);
    void parse_info_thread(client_t *client, char *args);
    void parse_info_user(client_t *client, char *args);
    void parse_list_channel(client_t *client, char *args);
    void parse_list_reply(client_t *client, char *args);
    void parse_list_team(client_t *client, char *args);
    void parse_list_threads(client_t *client, char *args);
    void parse_login(__attribute__((unused)) client_t *client,
    __attribute__((unused)) char *args);
    void parse_logout(client_t *client, char *args);
    void parse_message(client_t *client, char *args);
    void parse_send(client_t *client, char *args);
    void parse_subscribe(client_t *client, char *args);
    void parse_subscribed_team(client_t *client, char *args);
    void parse_subscribed_user(client_t *client, char *args);
    void parse_unsubscribe(client_t *client, char *args);
    void parse_use(client_t *client, char *args);
    void parse_user(client_t *client, char *args);
    void parse_users(client_t *client, char *args);
    void parse_help(client_t *client, char *args);



    // Usefull functions

    bool is_code_valid(char *code, enum cmd_e cmd);
    char **get_argument_parse(char *args);
    char *get_status(char *response);
    char *get_code(char *response);
    time_t get_timestamp(char *buffer);
    char *get_help(char *buffer);
    int get_status_use(char *buffer);

    // Error func for parse
    bool check_unauthorized_cmd(const char *status, const char *code, const char **args);
    bool check_already_exist_cmd(const char *status, const char *code, const char **args);
    bool check_unknown_thread_cmd(const client_t *client, const char *status,
    const char *code, const char **args);
    bool check_unknown_team_cmd(const client_t *client, const char *status,
                                const char *code, const char **args);
    bool check_unknown_channel_cmd(const client_t *client, const char *status,
                                   const char *code, const char **args);
    bool check_unknown_user_cmd(const char *status, const char *code, const char **args);

#endif /* !PARSE_LOGIC_H_ */
