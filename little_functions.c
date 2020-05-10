/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** little_functions
*/

#include "my.h"

char **printtab(char **tab, char **av, elem_t *elem)
{
    int y = 0;

    while (y < my_getnbr(av[1]) + 2) {
        my_putstr(tab[y]);
        my_putchar('\n');
        y++;
    }
    if (elem->jump == 0)
        my_putchar('\n');
    return (tab);
}

int empty(char **tab, int line)
{
    int x = 0;

    while (tab[line]) {
        while (tab[line][x]) {
            if (tab[line][x] == '|')
                return (line);
            x++;
        }
        x = 0;
        line++;
    }
    return (line);
}

int go_to_line(char **tab)
{
    int x = 0;
    int y = 0;

    while (tab[y]) {
        while (tab[y][x]) {
            if (tab[y][x] == '|')
                return (y);
            x++;
        }
        x = 0;
        y++;
    }
    return (84);
}

int check_win(char **tab)
{
    int x = 0;
    int y = 0;

    while (tab[y]) {
        while (tab[y][x]) {
            if (tab[y][x] == '|')
                return (84);
            x++;
        }
        x = 0;
        y++;
    }
    return (0);
}

int nb_pipes(char **tab, int line)
{
    int pipes = 0;
    int x = 0;

    while (tab[line][x]) {
        if (tab[line][x] == '|')
            pipes++;
        x++;
    }
    return (pipes);
}