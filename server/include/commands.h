/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** commands
*/

#ifndef MY_TEAMS_COMMANDS_H
    #define MY_TEAMS_COMMANDS_H

    const char *help_command(void *user_data, void *protocol_data, char *args);
    const char *login_command(void *user_data, void *protocol_data, char *args);
    const char *logout_command(void *user_data, void *protocol_data, char *args);
    const char *users_command(void *user_data, void *protocol_data, char *args);
    const char *user_command(void *user_data, void *protocol_data, char *args);
    const char *send_command(void *user_data, void *protocol_data, char *args);
    const char *messages_command(void *user_data, void *protocol_data, char *args);
    const char *subscribe_command(void *user_data, void *protocol_data, char *args);
    const char *subscribed_command(void *user_data, void *protocol_data, char *args);
    const char *unsubscribe_command(void *user_data, void *protocol_data, char *args);
    const char *use_command(void *user_data, void *protocol_data, char *args);
    const char *create_command(void *user_data, void *protocol_data, char *args);
    const char *list_command(void *user_data, void *protocol_data, char *args);
    const char *info_command(void *user_data, void *protocol_data, char *args);
#endif //MY_TEAMS_COMMANDS_H
