/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_response
*/

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "my_teams_client.h"
#include "protocol_logic.h

char *get_status(char *response)
{
    char *status = NULL;

    status = strtok(response, " ");
    return (status);
}

char *get_code(char *response)
{
    char *code = NULL;

    code = strtok(response, " ");
    return (code);
}

char **get_argument_parse(char *args)
{
    char **tab = NULL;
    char **users_args = NULL;

    if (!args)
        return (NULL);
    tab = str_to_word_array(args, "\"");
    if (!tab)
        return (NULL);
    if (my_arrlen(tab) < 2)
        return (NULL);
    users_args = str_to_word_array(tab[1], ";");
    if (!users_args)
        return (NULL);
    return (users_args);
}
