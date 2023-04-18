/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** help_command
*/

#include "commands.h"
#include "circular_buffer.h"

static const char help_message[] =
"  /help -> Show this help list\n"
"  /login \'username\'-> Log in with the specified username\n"
"  /logout -> Log out from the server\n"
"  /users -> List all users in the domain\n"
"  /user \'user_uuid\' -> Show information about a specific user\n"
"  /send \'user_uuid\' \'message_body\' -> Send a private message to a user\n"
"  /messages \'user_uuid\' -> List all messages exchanged with a user\n"
"  /subscribe \'team_uuid\' -> Subscribe to a team and its subdirectories\n"
"  /subscribed? \'team_uuid\' -> List all subscribed teams or users subscribed\
to a team\n"
"  /unsubscribe \'team_uuid\' -> Unsubscribe from a team\n"
"  /use \'team_uuid\' \'channel_uuid\' \'thread_uuid\' -> Specify a context of\
team/channel/thread\n"
"  /create -> Create a subresource based on the current context\n"
"  /list -> List all subresources based on the current context\n"
"  /info -> Show information about the current context\n";

int help_command(__attribute__((unused)) void *user_data,
__attribute__((unused)) void *protocol_data, __attribute__((unused)) char *args,
circular_buffer_t *write_buffer)
{
    write_success(write_buffer, "200", help_message);
    return EXIT_SUCCESS;
}
