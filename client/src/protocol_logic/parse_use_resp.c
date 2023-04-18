/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** parse_use_resp
*/

#include <string.h>
#include "logging_client.h"
#include "parse_logic.h"
#include "libstr.h"
#include "my_teams_client.h"

static void parse_state_ctx(char *state, enum context_state_e *ctx)
{
    if (!state)
        return;
    if (strcmp(state, "OK") == 0)
        *ctx = VALID_CTX;
    if (strcmp(state, "KO") == 0) {
        *ctx = INVALID_CTX;
    }
}

void parse_use(client_t *client, char *args)
{
    char *status = NULL;
    char *code = NULL;
    char **users_args = NULL;

    if (parse_resp(&status, &code, &users_args, args) == false
    || users_args == NULL)
        return;
    if (check_unauthorized_cmd(status, code, users_args))
        return;
    parse_state_ctx(users_args[0], &client->context->team_valid);
    parse_state_ctx(users_args[1], &client->context->channel_valid);
    parse_state_ctx(users_args[2], &client->context->thread_valid);
    destroy_array(users_args);
}
