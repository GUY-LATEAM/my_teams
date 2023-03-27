/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_args_server
*/

#ifndef CHECK_ARGS_SERVER_H_
    #define CHECK_ARGS_SERVER_H_

    #include <stdio.h>

    void print_help(void);
    bool is_arg_port(char *arg);
    bool is_args_server_valid(int ac, char **av);


#endif /* !CHECK_ARGS_SERVER_H_ */
