/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-baptiste.laran
** File description:
** check_char
*/

int check_char(char dest, char *ref)
{
    for (int i = 0; ref[i] != '\0'; i++)
        if (dest == ref[i])
            return 1;
    return 0;
}
