/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** protocol_logic
*/

#ifndef PROTOCOL_LOGIC_H_
    #define PROTOCOL_LOGIC_H_

    #include "my_teams_client.h"

    #define GUY "\x67\x75\x79"
    #define SP " "
    #define SEPARATORS "\"\n"

    typedef struct cmd_s {
        enum cmd_e id;
        char *cmd;
        int nb_args;
        void (*logic)(client_t *client, char **args);
    } cmd_t;

    typedef struct cmd_code_s {
        enum cmd_e id;
        char *expected_code;
    } cmd_code_t;

    typedef struct cmd_parse_s {
        enum cmd_e id;
        void (*check)(client_t *client, char *args);
    } cmd_parse_t;

    char *read_input(void);
    void parse_input(client_t *client, network_client_t *net_cli, char *input);

    void manage_input(client_t *client);

    void apply_logic_cmd(client_t *client, char *cmd, char **args);
    char *get_cmd(char *input, int *nb_args);
    char **get_args(int nb_args);

    void display_error(char *cmd, char **args);

    void free_parse_info(char *cmd, char **args);

#endif /* !PROTOCOL_LOGIC_H_ */
