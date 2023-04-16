/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** cmd_client_manager
*/

#ifndef CMD_CLIENT_MANAGER_H
    #define CMD_CLIENT_MANAGER_H
    #define BROADCAST_CMD "broadcast"
    #define BROADCAST_FUNCS &broadcast_client_event_logged_in,\
        &broadcast_client_event_logged_out,\
        &broadcast_client_event_private_message_received,\
        &broadcast_client_print_subscribed,\
        &broadcast_client_event_channel_created,\
        &broadcast_client_event_team_created,\
        &broadcast_client_event_thread_created,\
        &broadcast_client_event_thread_reply_received

    #include "protocol_logic.h"
    #include "circular_buffer.h"

    int broadcast_client_event_logged_in(char *);
    int broadcast_client_event_logged_out(char *);
    int broadcast_client_event_private_message_received(char *);
    int broadcast_client_print_subscribed(char *);
    int broadcast_client_event_channel_created(char *);
    int broadcast_client_event_team_created(char *);
    int broadcast_client_event_thread_created(char *);
    int broadcast_client_event_thread_reply_received(char *);
    int manage_cmd_client(char *data);
#endif /* CMD_CLIENT_MANAGER_H */
