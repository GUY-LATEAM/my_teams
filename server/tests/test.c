/*
** EPITECH PROJECT, 2023
** my_teams_server.h
** File description:
** my_teams_server.h
*/

#include <criterion/criterion.h>
#include "../include/my_teams_server.h"
#include <criterion/redirect.h>

Test(funcname, name, .init = cr_redirect_stdout)
{
    char *av[] = {"./my_teams_server.h", ""};
    int ac = 2;
    char *res = "";

    cr_assert_stdout_eq_str(res);
}
