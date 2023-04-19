/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** display_error
*/

#include <stdio.h>
#include "protocol_logic.h"

void display_error(char *cmd, char **args)
{
    if (!cmd) {
        printf("Invalid command\n");
        return;
    }
    if (!args) {
        printf("Invalid arguments\n");
    }
    free_parse_info(cmd, args);
}
