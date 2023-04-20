/*
** EPITECH PROJECT, 2023
** command_utils.c
** File description:
** command_utils.c
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "my_teams_server.h"
#include "add_struct.h"
#include "init_struct.h"
#include "protocol_logic.h"
#include "commands.h"

bool is_thread_already_exist(list_ptr_t *threads, char *name)
{
    thread_t *thread = NULL;

    for (int i = 0; i < threads->len; i++) {
        thread = get_list_i_data(threads, i);
        if (thread == NULL)
            continue;
        if (strcmp(thread->title, name) == 0)
            return true;
    }
    return false;
}

bool is_channel_already_exist(list_ptr_t *channels, char *name)
{
    channel_t *channel = NULL;

    for (int i = 0; i < channels->len; i++) {
        channel = get_list_i_data(channels, i);
        if (channel == NULL)
            continue;
        if (strcmp(channel->name, name) == 0)
            return true;
    }
    return false;
}

bool is_team_already_exist(list_ptr_t *teams, char *name)
{
    team_t *team = NULL;

    for (int i = 0; i < teams->len; i++) {
        team = get_list_i_data(teams, i);
        if (team == NULL)
            continue;
        if (strcmp(team->name, name) == 0)
            return true;
    }
    return false;
}

int write_error(circular_buffer_t *write_buffer, const char *code,
const char *message)
{
    bool error = false;
    bool code_bool = false;
    bool space = false;
    bool message_bool = false;
    bool guy = false;

    error = write_circular_buffer(write_buffer, "ERROR ");
    code_bool = write_circular_buffer(write_buffer, code);
    space = write_circular_buffer(write_buffer, " ");
    message_bool = write_circular_buffer(write_buffer, message);
    guy = write_circular_buffer(write_buffer, GUY);
    if (error == false || code_bool == false || space == false ||
    message_bool == false || guy == false)
        return false;
    return true;
}

int write_success(circular_buffer_t *write_buffer, const char *code,
const char *message)
{
    bool ok = false;
    bool code_bool = false;
    bool space = false;
    bool message_bool = false;
    bool guy = false;

    ok = write_circular_buffer(write_buffer, "OK ");
    code_bool = write_circular_buffer(write_buffer, code);
    space = write_circular_buffer(write_buffer, " ");
    message_bool = write_circular_buffer(write_buffer, message);
    guy = write_circular_buffer(write_buffer, GUY);
    if (ok == false || code_bool == false || space == false ||
    message_bool == false || guy == false)
        return false;
    return true;
}
