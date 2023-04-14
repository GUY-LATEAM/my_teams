/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myrunner-romain.panno
** File description:
** str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>
#include "libstr.h"

static int get_nbr_words(char *str, char *ref)
{
    int nb_words = 0;
    int i = 0;
    int mark = 0;

    while (str[i] != '\0') {
        if (check_char(str[i], ref) == 0 && mark == 0) {
            nb_words += 1;
            mark = 1;
        }
        if (check_char(str[i], ref) == 1 && mark == 1)
            mark = 0;
        i++;
    }
    return nb_words;
}

static int get_word_len(char *str, char *ref)
{
    int len = 0;

    for (; str[len] != '\0' && check_char(str[len], ref) == 0; len++);
    return len;
}

static char *add_words(char *str, char *ref)
{
    char *result = NULL;
    int i = 0;
    int indx = 0;

    result = malloc(sizeof(char) * (get_word_len(str, ref) + 1));
    while (str[i] != '\0') {
        if (check_char(str[i], ref) == 0) {
            result[indx] = str[i];
            indx++;
        } else {
            result[indx] = '\0';
            return result;
        }
        i++;
    }
    result[indx] = '\0';
    return result;
}

char **str_to_word_array(char *str, char *ref)
{
    char **result = NULL;
    int nb_words = 0;
    int indx = 0;
    int mark = 0;

    if (str == NULL || ref == NULL)
        return NULL;
    nb_words = get_nbr_words(str, ref);
    result = malloc(sizeof(char *) * (nb_words + 1));
    result[nb_words] = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_char(str[i], ref) == 0 && mark == 0) {
            result[indx] = add_words(&(str[i]), ref);
            mark = 1;
            indx++;
        }
        if (check_char(str[i], ref) == 1 && mark == 1)
            mark = 0;
    }
    return result;
}
