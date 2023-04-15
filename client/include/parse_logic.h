/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_logic
*/

#ifndef PARSE_LOGIC_H_
    #define PARSE_LOGIC_H_

    #include "protocol_logic.h"

    // No specific data returned

    void parse_no_info(client_t *client, char *buffer);
    void parse_logout(client_t *client, char *buffer);

    // With specific data returned

    void parse_list(client_t *client, char *buffer);
    void parse_user(client_t *client, char *buffer);
    void parse_users(client_t *client, char *buffer);
    void parse_use(client_t *client, char *buffer);
    void parse_info(client_t *client, char *buffer);
    void parse_messages(client_t *client, char *buffer);
    void parse_subscribed_teams(client_t *client, char *buffer);
    void parse_subscribed_users(client_t *client, char *buffer);
    void parse_help(client_t *client, char *buffer);

    // Usefull functions

    bool is_code_valid(char *code, enum cmd_e cmd);
    char *get_response_arg(char *buffer, size_t size);
    time_t get_timestamp(char *buffer);
    char *get_help(char *buffer);
    bool get_status_use(char *buffer);



#endif /* !PARSE_LOGIC_H_ */
