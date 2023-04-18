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
#include "circular_buffer.h"

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
        if (strcmp(context[i], "KO") == 0){
            return false;
        }
    }
    return true;
}

static int do_create_command(server_t *server, char **context)
{
//    static int (*create_command[])(server_t *, char **) = {
//        create_team,
//        create_channel,
//        create_thread,
//        create_reply
//    };
    if (server == NULL || context == NULL) {
        return EXIT_FAILURE;
    }
//    if (strcmp(context->team_uuid, "OK") == 0) {
//        return create_team(server, context);
//    }
//    if (strcmp(context->channel_uuid, "OK") == 0) {
//        return create_channel(server, context);
//    }
//    if (strcmp(context->thread_uuid, "OK") == 0) {
//        return create_thread(server, context);
//    }
    return EXIT_FAILURE;
}

int create_command(void *user_data, __attribute__((unused)) void *protocol_data,
__attribute__((unused)) char *args, circular_buffer_t *write_buffer)
{
    server_t *server = user_data;
    char **context = NULL;

    if (user_data == NULL) {
        write_error(write_buffer, "401", "The client needs to authenticate");
        return EXIT_FAILURE;
    }
    context = get_context(args);
    if (is_a_good_context(context) == false) {
        write_error(write_buffer, "401", "The client needs to authenticate");
    } else {
        do_create_command(server, context);
    }
    return EXIT_SUCCESS;
}
