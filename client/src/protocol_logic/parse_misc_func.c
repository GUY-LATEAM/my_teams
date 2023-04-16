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
#include "libstr.h"
#include "protocol_logic.h"

static char *get_status(char *response)
{
    char *status = NULL;

    status = strtok(response, " ");
    return (status);
}

static char *get_code(char *response)
{
    char *code = NULL;

    code = strtok(response, " ");
    return (code);
}

static char **get_argument_parse(char *args)
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

bool parse_resp(char **status, char **code, char ***users_args, char *args)
{
    *status = get_status(args);
    if (!*status)
        return false;
    args = args + strlen(*status) + 1;
    *code = get_code(args);
    if (!*code)
        return false;
    args = args + strlen(*code) + 1;
    *users_args = get_argument_parse(args);
    if (!*users_args)
        return false;
    return true;
}
