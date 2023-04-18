/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** info_command
*/

#include <string.h>
#include "my_teams_server.h"
#include "circular_buffer.h"
#include "commands.h"
#include "libstr.h"

static int check_context_error(char *args, circular_buffer_t *write)
{
    if (strstr(args, "KO") != NULL) {
        write_error(write, "404", "Bad context");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int info_command(__attribute__((unused)) void *user_data,
void *protocol_data, char *args,
circular_buffer_t *write_buffer)
{
    char **context = NULL;

    if (check_is_user_login(protocol_data,
    user_data, write_buffer) == EXIT_FAILURE
    || check_context_error(args, write_buffer) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    context = str_to_word_array(args, "\":");
    if (is_context_loggedin_user(context))
        send_info_logged_in(protocol_data, context, write_buffer);
    if (is_context_team(context))
        send_info_current_team(protocol_data, context, write_buffer);
    if (is_context_channel(context))
        send_info_current_channel(protocol_data, context, write_buffer);
    if (is_context_thread(context))
        send_info_current_thread(protocol_data, context, write_buffer);
    destroy_array(context);
    return EXIT_SUCCESS;
}
