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
        {SUBSCRIBED_USERS, "200"},
        {SUBSCRIBED_TEAMS, "200"},
        {UNSUBSCRIBE, "200"},
        {USE, "200"},
        {CREATE, "201"},
        {LIST, "200"},
        {INFO, "200"},
        {HELP, "200"},
        {UNKNOWN, "0"}
};

static const cmd_parse_t NO_INFO[] = {
        {LOGIN, parse_no_info},
        {LOGOUT, parse_logout},
        {SEND, parse_no_info},
        {SUBSCRIBE, parse_no_info},
        {UNSUBSCRIBE, parse_no_info},
        {CREATE, parse_no_info},
        {UNKNOWN, NULL}
};

static const cmd_parse_t WITH_INFO[] = {
        {USER, NULL},
        {USERS, NULL},
        {SUBSCRIBED_USERS, NULL},
        {SUBSCRIBED_TEAMS, NULL},
        {USE, NULL},
        {LIST, NULL},
        {INFO, NULL},
        {HELP, NULL},
        {UNKNOWN, NULL}
};


void manage_response(client_t *protocol, char *response)
{
    for (int i = 0; NO_INFO[i].id != UNKNOWN; i++) {
        if (protocol->requested_cmd == NO_INFO[i].id) {
            NO_INFO[i].check(protocol, response);
            return;
        }
    }
    for (int i = 0; WITH_INFO[i].id != UNKNOWN; i++) {
        if (protocol->requested_cmd == WITH_INFO[i].id) {
            WITH_INFO[i].check(protocol, response);
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
