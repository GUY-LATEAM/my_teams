/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** check_unknown_func
*/

#ifndef CHECK_UNKNOWN_FUNC_H_
    #define CHECK_UNKNOWN_FUNC_H_

    #include "my_teams_client.h"
    #include "parse_logic.h"

    int check_unknown_channel(client_t *client, char *status,
    char *code, char **args);
    int check_unknown_thread(client_t *client, char *status,
    char *code, char **args);

#endif /* !CHECK_UNKNOWN_FUNC_H_ */
