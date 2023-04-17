/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** handle_signal
*/

#include <stdio.h>
#include "signal_management_server.h"
#include "save_struck.h"

static const signal_dict_t signal_tab[] = {
    {SIGINT_RECEIVED, &save_server_config},
    {MAX_ENUM_SIGNAL, NULL},
};

signal_t signal_flag(signal_t signal, bool set)
{
    static signal_t signal_flag = NOTHING_RECEIVED;

    if (set == true) {
        signal_flag = signal;
    }
    return signal_flag;
}

void save_server_config(server_t *server)
{
    if (server) {
        printf("Saving server config...\n");
        save_server_data(server, "data/users.txt", "data/teams.txt");
    }
    return;
}

void handle_signal(int sig)
{
    if (sig == SIGINT) {
        SET_SIGNAL_FLAG(SIGINT_RECEIVED);
    } else  {
        SET_SIGNAL_FLAG(NOTHING_RECEIVED);
    }
}

void apply_signal_action(server_t *server)
{
    int i = 0;

    while (signal_tab[i].signal != MAX_ENUM_SIGNAL) {
        if (signal_tab[i].signal == SIGNAL_FLAG) {
            signal_tab[i].action(server);
            break;
        }
        i++;
    }
}
