/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** my_teams
*/

#include <criterion/criterion.h>
#include "../include/my_teams.h"
#include <criterion/redirect.h>

Test(funcname, name, .init = cr_redirect_stdout)
{
    char *av[] = {"./my_teams", ""};
    int ac = 2;
    char *res = "";

    cr_assert_stdout_eq_str(res);
}
