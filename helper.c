/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** helper
*/

#include "my.h"

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
    if (ac != 3) {
        write(2, "type: ./matchstick -h\n", 23);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("WELCOME TO MATCHSTICK GAME !!\n\n");
        my_putstr("_av[2] ne doit pas être nul.\n");
        my_putstr("_av[1] et av[2] doivent être des nombres.\n\n");
        my_putstr("=> type: ./matchstick av[1] av[2]\n");
        return (84);
    }
    if (my_getnbr(av[1]) < 2 || my_getnbr(av[2]) == 0 || my_getnbr(av[1]) > 99)
        return (84);
    if (check_av(av, 0, 0) == 84)
        return (84);
    return (0);
}