/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** destroy_threads
*/

#include "list_lib.h"
#include "destroy_struct.h"
#include "my_teams_server.h"

void destroy_thread(thread_t *thread)
{
    if (!thread)
        return;
    for (int i = 0; i < thread->replies->len; i++)
        destroy_reply(get_list_i_data(thread->replies, i));
    free_list_no_data(thread->replies);
    free(thread);
}
