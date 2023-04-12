/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** handle_signal
*/

#include <stdio.h>
#include "signal_management_client.h"

static const signal_dict_t signal_tab[] = {
    {SIGINT_RECEIVED, &save_client_config},
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

void save_client_config(client_t *server)
{
    printf("Closing Client...\n");
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

void apply_signal_action(client_t *server)
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
