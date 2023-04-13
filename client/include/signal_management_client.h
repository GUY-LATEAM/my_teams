/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** signal_management
*/

#ifndef SIGNAL_MANAGEMENT_H_
    #define SIGNAL_MANAGEMENT_H_
    #define SIGNAL_FLAG signal_flag(0, false)
    #define SET_SIGNAL_FLAG(s) signal_flag(s, true)


    #include <signal.h>
    #include "list_lib.h"
    #include "my_teams_client.h"

    typedef enum signal_e {
        NOTHING_RECEIVED,
        SIGINT_RECEIVED,
        MAX_ENUM_SIGNAL
    } signal_t;

    typedef struct signal_dict_s {
        signal_t signal;
        void (*action)(client_t *client);
    } signal_dict_t;

    signal_t signal_flag(signal_t signal, bool set);
    void signal_handler(int signal);
    void handle_signal(int sig);
    void apply_signal_action(client_t *client);
    void save_client_config(client_t *client);

#endif /* !SIGNAL_MANAGEMENT_H_ */
