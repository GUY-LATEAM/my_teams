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
    #define SEPARATORS " \n\t"

    typedef struct cmd_s {
        char *cmd;
        int nb_args;
    } cmd_t;

    char *read_input(void);
    void parse_input(network_client_t *client, char *input);

    void manage_input(client_t *client);

    char *get_cmd(char *input, int *nb_args);
    char **get_args(int nb_args);

    void display_error(char *cmd, char **args);

    void free_parse_info(char *cmd, char **args);

#endif /* !PROTOCOL_LOGIC_H_ */
