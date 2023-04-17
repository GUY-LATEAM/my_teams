/*
** EPITECH PROJECT, 2023
** save_users_to_file
** File description:
** save_users_to_file
*/

#include "save_struck.h"

char *time_to_string(time_t timestamp)
{
    char *timestamp_str = NULL;

    timestamp_str = malloc(sizeof(char) * 21);
    if (timestamp_str == NULL) {
        return NULL;
    }
    sprintf(timestamp_str, "%ld", (long)timestamp);
    return timestamp_str;
}

time_t string_to_time(const char *timestamp_str)
{
    long read_long = 0;
    int result;

    result = sscanf(timestamp_str, "%ld", &read_long);
    if (result != 1) {
        return (time_t)-1;
    }
    return (time_t)read_long;
}

void remove_newline(char *str)
{
    int len = 0;

    if (str == NULL) {
        return;
    }
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
