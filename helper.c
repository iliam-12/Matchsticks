/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** helper
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2)) return (84);
    while (s1[i] && s2[i]) {
        if (s1[i] == s2[i])
            i++;
        else
            return (84);
    } return (0);
}

int check_str2(elem_t *elem, int j)
{
    while (elem->str2[j]) {
        if (elem->str2[j] < '0' || elem->str2[j] > '9')
            return (84);
        j++;
    }
    return (0);
}

int check_str(elem_t *elem, int i)
{
    while (elem->str[i]) {
        if (elem->str[i] < '0' || elem->str[i] > '9')
            return (84);
        i++;
    }
    return (0);
}

int check_av(char **av, int i, int j)
{
    while (av[1][i]) {
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
        i++;
    }
    while (av[2][j]) {
        if (av[2][j] < '0' || av[2][j] > '9')
            return (84);
        j++;
    }
    return (0);
}

int error_main(int ac, char **av)
{
    if (ac == 1) {
        write(2, "type: ./matchstick -h\n", 23);
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr("WELCOME TO MY MATCHSTICK!!\n\n");
        my_putstr("_av[2] ne doit pas être nul.\n");
        my_putstr("_av[1] et av[2] doivent être des nombres.\n\n");
        my_putstr("=> type: ./matchstick nb1 nb2\n");
        return (84);
    }
    if (my_getnbr(av[1]) < 2 || my_getnbr(av[2]) == 0 || my_getnbr(av[1]) > 99)
        return (84);
    if (check_av(av, 0, 0) == 84)
        return (84);
    return (0);
}