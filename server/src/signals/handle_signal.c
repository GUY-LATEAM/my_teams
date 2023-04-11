/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** handle_signal
*/

#include <stdio.h>
#include "signal_management.h"

static signal_t signal_flag = NOTHING_RECEIVED;

static const signal_dict_t signal_tab[] = {
    {SIGINT_RECEIVED, &save_server_config},
    {MAX_ENUM_SIGNAL, NULL},
};

void save_server_config(server_t *server)
{
    printf("Saving server config...\n");
    return;
}

void handle_signal(int sig)
{
    if (sig == SIGINT) {
        signal_flag = SIGINT_RECEIVED;
    } else  {
        signal_flag = NOTHING_RECEIVED;
    }
}

signal_t get_signal_flag(void)
{
    return signal_flag;
}

void set_signal_flag(signal_t flag)
{
    signal_flag = flag;
}

void apply_signal_action(server_t *server)
{
    int i = 0;

    while (signal_tab[i].signal != MAX_ENUM_SIGNAL) {
        if (signal_tab[i].signal == signal_flag) {
            signal_tab[i].action(server);
            break;
        }
        i++;
    }
}
