/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** signal_management
*/

#ifndef SIGNAL_MANAGEMENT_SERVER_H_
    #define SIGNAL_MANAGEMENT_SERVER_H_


    #include <signal.h>
    #include "list_lib.h"
    #include "my_teams_server.h"

    typedef enum signal_e {
        NOTHING_RECEIVED,
        SIGINT_RECEIVED,
        MAX_ENUM_SIGNAL
    } signal_t;

    typedef struct signal_dict_s {
        signal_t signal;
        void (*action)(server_t *server);
    } signal_dict_t;

    void signal_handler(int signal);
    void handle_signal(int sig);
    signal_t get_signal_flag(void);
    void set_signal_flag(signal_t flag);
    void apply_signal_action(server_t *server);
    void save_server_config(server_t *server);

#endif /* !SIGNAL_MANAGEMENT_H_ */
