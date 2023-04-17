/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** manage_response
*/

#include <string.h>
#include <stdio.h>
#include "my_teams_client.h"
#include "protocol_logic.h"
#include "manage_response_client.h"
#include "parse_logic.h"

static const cmd_code_t CMD_CODE_TAB[] = {
        {LOGIN, "204"},
        {LOGOUT, "204"},
        {USERS, "200"},
        {USER, "200"},
        {SEND, "204"},
        {MESSAGES, "200"},
        {SUBSCRIBE, "204"},
        {SUBSCRIBED, "200"},
        {UNSUBSCRIBE, "200"},
        {USE, "200"},
        {CREATE, "201"},
        {LIST, "200"},
        {INFO, "200"},
        {HELP, "200"},
        {UNKNOWN, "0"}
};

static const cmd_parse_t parse_tab[] = {
        {LOGIN, parse_login},
        {LOGOUT, parse_logout},
        {SEND, parse_send},
        {SUBSCRIBE, parse_subscribe},
        {UNSUBSCRIBE, parse_unsubscribe},
        {CREATE_TEAM, parse_create_team},
        {CREATE_CHANNEL, parse_create_channel},
        {CREATE_THREAD, parse_create_thread},
        {CREATE_REPLY, parse_create_reply},
        {USER, parse_user},
        {USERS, parse_users},
        {SUBSCRIBED_TEAMS, parse_subscribed_team},
        {SUBSCRIBED_USERS, parse_subscribed_user},
        {USE, parse_use},
        {LIST_TEAM, parse_list_team},
        {LIST_CHANNEL, parse_list_channel},
        {LIST_THREAD, parse_list_threads},
        {LIST_REPLY, parse_list_reply},
        {INFO_TEAM, parse_info_team},
        {INFO_CHANNEL, parse_info_channel},
        {INFO_THREAD, parse_info_thread},
        {INFO_USER, parse_info_user},
        {HELP, parse_help},
        {MESSAGES, parse_message},
        {UNKNOWN, NULL}
};


void manage_response(client_t *protocol, char *response)
{
    for (int i = 0; parse_tab[i].id != UNKNOWN; i++) {
        if (protocol->requested_cmd == parse_tab[i].id) {
            printf("cmd :%d\n", protocol->requested_cmd);
            parse_tab[i].check(protocol, response);
            return;
        }
    }
    printf("Unexpected command executed\n");
}

bool is_code_valid(char *code, enum cmd_e cmd)
{
    char *expected = NULL;

    for (int i = 0; CMD_CODE_TAB[i].id != UNKNOWN; i++) {
        if (CMD_CODE_TAB[i].id == cmd)
            expected = CMD_CODE_TAB[i].expected_code;
    }
    if (expected && strcmp(expected, code) == 0)
        return true;
    return false;
}
