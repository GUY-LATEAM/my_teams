/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** create_command
*/

#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "add_struct.h"
#include "create_command_utils.h"
#include "protocol_logic.h"

static char **get_context(char *raw_args)
{
    char **tmp = NULL;
    char **args = NULL;

    if (raw_args == NULL) {
        return NULL;
    }
    tmp = str_to_word_array(raw_args, "\"");
    if (tmp == NULL) {
        return NULL;
    }
    if (my_arrlen(tmp) != 1) {
        destroy_array(tmp);
        return NULL;
    }
    args = str_to_word_array(tmp[0], ":");
    destroy_array(tmp);
    return args;
}

static bool is_a_good_context(char **context)
{
    if (context == NULL) {
        return false;
    }
    for (int i = 0; context[i] != NULL; i++) {
        if (strcmp(context[i], KO_UUID) == 0) {
            return false;
        }
    }
    return true;
}

static int do_create_command(server_t *server, user_t *user, char **context)
{
    if (server == NULL || context == NULL) {
        return EXIT_FAILURE;
    }
    if (strcmp(context[0], UNDEFINED) == 0) {
        return create_team(server, user, context);
    }
    if (strcmp(context[1], UNDEFINED) == 0) {
        return create_channel(server, user, context);
    }
    if (strcmp(context[2], UNDEFINED) == 0) {
        return create_thread(server, user, context);
    } else {
        return create_reply(server, user, context);
    }
}

int create_command(void *user_data, __attribute__((unused)) void *protocol_data,
__attribute__((unused)) char *args, circular_buffer_t *write_buffer)
{
    server_t *server = protocol_data;
    char **context = NULL;
    int result = EXIT_SUCCESS;

    if (user_data == NULL) {
        write_error(write_buffer, "401", "The client needs to authenticate");
        return EXIT_FAILURE;
    }
    context = get_context(args);
    if (is_a_good_context(context) == false) {
        write_error(write_buffer, "404", "Bad context");
    } else {
        result = do_create_command(server, user_data, context);
    }
    if (result == ALREADY_EXIST)
        write_error(write_buffer, "409", "Already Exist");
    return EXIT_SUCCESS;
}
