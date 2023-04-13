/*
** EPITECH PROJECT, 2023
** bs_teams
** File description:
** ciruclar_buffer
*/

#ifndef CIRUCLAR_BUFFER_H_
    #define CIRUCLAR_BUFFER_H_

    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct circular_buffer_s {
        char *buffer;
        size_t size;
        size_t cursor_read;
        size_t cursor_write;
        char *end_pattern;
    } circular_buffer_t;

    // cbuf_misc
    bool is_circular_buffer_full(circular_buffer_t *cbuff);
    bool is_circular_buffer_empty(circular_buffer_t *cbuff);
    size_t get_available_space_circular_buffer(circular_buffer_t *cbuff);
    size_t get_used_space_circular_buffer(circular_buffer_t *cbuff);
    bool is_circular_buffer_completed(circular_buffer_t *cbuff);

    // cbuf_create
    circular_buffer_t *create_circular_buffer(size_t size, const char *pattern);
    bool write_circular_buffer(circular_buffer_t *cbuff, const char *data);

    // cbuf_destroy
    size_t read_circular_buffer(circular_buffer_t *cbuff, char *data);
    void destroy_circular_buffer(circular_buffer_t *cbuff);
    void clear_circular_buffer(circular_buffer_t *cbuff);

#endif /* !CIRUCLAR_BUFFER_H_ */
