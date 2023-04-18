/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** context_getter
*/

#ifndef CONTEXT_GETTER_H_
    #define CONTEXT_GETTER_H_

    #include "list_lib.h"
    #include "my_teams_server.h"

    team_t *get_team_by_uuid(list_ptr_t *list_team, char *uuid);
    channel_t *get_channel_by_uuid(list_ptr_t *list_channel, char *uuid);
    thread_t *get_thread_by_uuid(list_ptr_t *list_thread, char *uuid);

#endif /* !CONTEXT_GETTER_H_ */
