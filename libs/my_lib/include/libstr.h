/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** libstr
*/

#ifndef LIBSTR_H_
    #define LIBSTR_H_

    typedef enum side {
        LEFT = 0,
        RIGHT = 1,
        START = 0,
        END = 1,
        IN = 2,
    } side_t;

    void my_putchar(char c);

    int my_strstr(char *str, char const *to_find);

    int my_isneg(int nb);

    int my_strcmp(char const *s1, char const *s2);

    int my_strncmp(char const *s1, char const *s2, int n);

    void my_swap(int *a, int *b);

    char *my_strupcase(char *str);

    int my_putstr(char const *str);

    char *my_strlowcase(char *str);

    int my_strlen(char const *str);

    char *my_strcapitalize(char *str);

    int my_str_isalpha(char const *str);

    int my_str_isnum(char const *str);

    int my_str_islower(char const *str);

    int my_str_isupper(char const *str);

    int my_str_isprintable(char const *str);

    char *my_strcpy(char *dest, char const *src);

    char *my_strncpy(char *dest, char const *src, int n);

    char *my_revstr(char *str);

    char *my_strncat(char *dest, char const *src, int nb);

    char *int_to_string(int nb);

    int my_puts(const char *str);

    void pac(void);

    int my_arrlen(char **array);

    int display_arr(char **arr, char *separator);

    int is_same_str(char *s1, char *s2);

    int destroy_array(char **array);

    char *my_strdup(char *str);

    int my_putstr_error(const char *str);

    int my_puts_error(const char *str);

    char *my_split(char *ref, char *mark, side_t side);

    char *my_split_right(char *ref, char *mark);

    char *my_split_left(char *ref, char *mark);

    int str_with(char *dest, char *ref, side_t side);

    int end_with(char *dest, char *ref);

    int start_with(char *dest, char *ref);

    int is_in(char *dest, char *ref);

    char *get_file(char *filepath);

    char *my_memset(char *str, int value, char set);

    char **str_to_word_array(char *str, char *ref);

    int check_char(char dest, char *ref);

    char *get_file_no_stats(char *filepath);
#endif /* !LIBSTR_H_ */
