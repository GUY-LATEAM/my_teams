/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** subscribe_logic
*/

#include <string.h>
#include "my_teams_client.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "libstr.h"

void subscribe_logic(__attribute__((unused)) client_t *client,
__attribute__((unused)) enum cmd_e cmd ,char **args, __attribute__((unused)) int *nb_args)
{
    if (my_arrlen(args) != 1) {
        client->requested_cmd = SUBSCRIBED_TEAMS;
    } else {
        client->requested_cmd = SUBSCRIBED_USERS;
    }
}