/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** get_file_no_stats
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int len_file(char *filepath)
{
    char buffer[1] = "p";
    int len = 0;
    int file = 0;

    if (filepath == NULL)
        return -1;
    file = open(filepath, O_RDONLY);
    if (file < 0) {
        return -1;
    }
    while (read(file, buffer, 1)) {
        len += 1;
    }
    close(file);
    return len;
}

char *get_file_no_stats(char *filepath)
{
    int file = 0;
    char *buffer = NULL;
    int stsize = 0;

    if (filepath == NULL) {
        return NULL;
    }
    file = open(filepath, O_RDONLY);
    stsize = len_file(filepath);
    if (file < 0 || stsize < 0) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (stsize + 1));
    if (buffer == NULL) {
        return NULL;
    }
    buffer[stsize] = '\0';
    read(file, buffer, stsize);
    close(file);
    return buffer;
}
