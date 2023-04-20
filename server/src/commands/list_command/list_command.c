/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** list_command
*/

#include <string.h>
#include "commands.h"
#include "libstr.h"
#include "add_struct.h"
#include "create_command_utils.h"

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

static int do_list_command(
server_t *server, user_t *user, char **context, circular_buffer_t *write_buffer)
{
    if (server == NULL || context == NULL) {
        return EXIT_FAILURE;
    }
    if (strcmp(context[0], UNDEFINED) == 0) {
        return list_team(server, user, context, write_buffer);
    }
    if (strcmp(context[1], UNDEFINED) == 0) {
        return list_channel(server, user, context, write_buffer);
    }
    if (strcmp(context[2], UNDEFINED) == 0) {
        return list_thread(server, user, context, write_buffer);
    } else {
        return list_reply(server, user, context, write_buffer);
    }
}

int list_command(__attribute__((unused)) void *user_data,
__attribute__((unused)) void *protocol_data, __attribute__((unused)) char *args,
circular_buffer_t *write_buffer)
{
    server_t *server = protocol_data;
    char **context = NULL;

    if (user_data == NULL) {
        write_error(write_buffer, "401", "The client needs to authenticate");
        return EXIT_FAILURE;
    }
    context = get_context(args);
    if (is_a_good_context(context) == false) {
        write_error(write_buffer, "404", "Path not found");
    } else {
        return do_list_command(server, user_data, context, write_buffer);
    }
    return EXIT_SUCCESS;
}
