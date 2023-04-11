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

static void *attribute_new_events_method(server_events_t *events, void *lib, int i)
{
    switch (i) {
        case 0:
            events->server_event_team_created = dlsym(lib, events_names[i]);
            return events->server_event_team_created;
        case 1:
            events->server_event_channel_created = dlsym(lib, events_names[i]);
            return events->server_event_channel_created;
        case 2:
            events->server_event_thread_created = dlsym(lib, events_names[i]);
            return events->server_event_thread_created;
        case 3:
            events->server_event_reply_created = dlsym(lib, events_names[i]);
            return events->server_event_reply_created;
        case 4:
            events->server_event_user_subscribed = dlsym(lib, events_names[i]);
            return events->server_event_user_subscribed;
        case 5:
            events->server_event_user_unsubscribed = dlsym(lib, events_names[i]);
            return events->server_event_user_unsubscribed;
        case 6:
            events->server_event_user_created = dlsym(lib, events_names[i]);
            return events->server_event_user_created;
        case 7:
            events->server_event_user_loaded = dlsym(lib, events_names[i]);
            return events->server_event_user_loaded;
        case 8:
            events->server_event_user_logged_in = dlsym(lib, events_names[i]);
            return events->server_event_user_logged_in;
        case 9:
            events->server_event_user_logged_out = dlsym(lib, events_names[i]);
            return events->server_event_user_logged_out;
        case 10:
            events->server_event_private_message_sended = dlsym(lib, events_names[i]);
            return events->server_event_private_message_sended;
    }
    return NULL;
}

server_events_t *init_events(void)
{
    void *lib = NULL;
    server_events_t *events = NULL;

    lib = open_shared_library(EVENTS_PATH);
    if (!lib)
        return;
    events = malloc(sizeof(server_events_t));
    if (!events)
        return;
    for (int i = 0; events_names[i]; i++) {
        if (attribute_new_events_method(events, lib, i) == NULL) {
            fprintf(stderr, "%s", dlerror());
            dlclose(lib);
            return NULL;
        }
    }
    return events;
}

int terminate_events(server_events_t *events)
{
    free(events);
    return EXIT_SUCCESS;
}
