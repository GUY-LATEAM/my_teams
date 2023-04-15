/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-antman-brice.desousa
** File description:
** open_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *get_file(char *filepath)
{
    int file = 0;
    char *buffer = NULL;
    struct stat stats;

    if (filepath == NULL) {
        return NULL;
    }
    file = open(filepath, O_RDONLY);
    if (file < 0) {
        return NULL;
    }
    stat(filepath, &stats);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (buffer == NULL) {
        return NULL;
    }
    buffer[stats.st_size] = '\0';
    read(file, buffer, stats.st_size);
    close(file);
    return buffer;
}
