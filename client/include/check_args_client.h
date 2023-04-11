/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_args_client
*/

#ifndef CHECK_ARGS_CLIENT_H_
    #define CHECK_ARGS_CLIENT_H_

    #include <stdio.h>
    #include <stdbool.h>

    void print_help(void);
    bool is_arg_port(char *arg);
    bool is_arg_ip(char *arg);
    bool is_args_client_valid(int ac, char **av);


#endif /* !CHECK_ARGS_CLIENT_H_ */
