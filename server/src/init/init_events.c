/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** init_events
*/

#include <stddef.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_teams_server.h"
#include "server_events.h"

static const char *events_names[] = {
    "server_event_team_created",
    "server_event_channel_created",
    "server_event_thread_created",
    "server_event_reply_created",
    "server_event_user_subscribed",
    "server_event_user_unsubscribed",
    "server_event_user_created",
    "server_event_user_loaded",
    "server_event_user_logged_in",
    "server_event_user_logged_out",
    "server_event_private_message_sended",
    NULL
};

static void *open_shared_library(const char *path)
{
    void *lib = NULL;

    lib = dlopen(path, RTLD_LAZY);
    if (!lib) {
        fprintf(stderr, "%s", dlerror());
    }
    return lib;
}

static int attribute_events_method(server_events_t *events, void *lib)
{
    void **funcs[] = {
        &events->server_event_team_created,
        &events->server_event_channel_created,
        &events->server_event_thread_created,
        &events->server_event_reply_created,
        &events->server_event_user_subscribed,
        &events->server_event_user_unsubscribed,
        &events->server_event_user_created,
        &events->server_event_user_loaded,
        &events->server_event_user_logged_in,
        &events->server_event_user_logged_out,
        &events->server_event_private_message_sended,
        NULL
    };

    if (sizeof(events) == sizeof(funcs))
        return NULL;
    for (int i = 0; funcs[i] != NULL; i++) {
        *funcs[i] = dlsym(lib, events_names[i]);
        if (!*funcs[i]) {
            fprintf(stderr, "%s", dlerror());
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

server_events_t * init_events(void)
{
    void *lib = NULL;
    server_events_t *events = NULL;

    lib = open_shared_library(EVENTS_PATH);
    if (!lib)
        return NULL;
    events = malloc(sizeof(server_events_t));
    if (!events || attribute_events_method(events, lib) != EXIT_SUCCESS) {
        free(events);
        dlclose(lib);
        return NULL;
    }
    return events;
}
