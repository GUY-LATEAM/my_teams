/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_info_channel_resp
*/

#include <string.h>
#include <stdio.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "list_lib.h"
#include "libstr.h"
#include "client_func.h"
#include "my_teams_client.h"

void parse_help(__attribute__((unused)) client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    printf("size :%d\n", my_arrlen(users_args));
    printf("%s\n", users_args[0]);
    destroy_array(users_args);
}
