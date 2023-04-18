/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** get_info_users
*/

#include <string.h>
#include "libstr.h"
#include "protocol_logic.h"
#include "my_teams_server.h"

bool is_context_loggedin_user(char **context)
{
    if (my_arrlen(context) != 3)
        return false;
    if (strcmp(context[0], "UN") == 0
    && strcmp(context[1], "UN") == 0
    && strcmp(context[2], "UN") == 0) {
        return true;
    }
    return false;
}

void send_info_logged_in(server_t *serv,
__attribute__((unused)) char **context,
circular_buffer_t *write)
{
    user_t *user = NULL;

    write_circular_buffer(write, "OK 200 ");
    write_circular_buffer(write, "\"");
    for (int i = 0; i < serv->all_users->len; i++) {
        user = get_list_i_data(serv->all_users, i);
        if (user->nb_users > 0) {
            write_circular_buffer(write, user->uuid);
            write_circular_buffer(write, ":");
            write_circular_buffer(write, user->name);
            write_circular_buffer(write, ":");
            write_circular_buffer(write, "1");
            write_circular_buffer(write, ":");
        }
    }
    write_circular_buffer(write, "\"");
    write_circular_buffer(write, GUY);
}
