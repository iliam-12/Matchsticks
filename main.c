/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include "my.h"

char **my_map(char *str)
{
    int av = my_getnbr(str);
    int x = 0;
    int y = 0;
    int k = 1;
    char **tab = malloc(sizeof(char *) * (av + 4));

    for (int i = 0; i != av + 3; i++) {
        if ((tab[i] = malloc(sizeof(char) * av * 2 + 2)) == NULL)
            tab[i][av*2+1] = '\0';
    }
    while (y < av + 2) {
        while (x < av*2 + 1) {
            if (x == 0 || x == av * 2 || y == 0 || y == av + 1)
                tab[y][x] = '*';
            else
                tab[y][x] = ' ';
            x++;
        }
        x = 0;
        y++;
    }
    while (y != 2) {
        while (x != av*2 - k) {
            tab[y-2][x+1] = '|';
            x++;
        }
        x = 0;
        k++;
        x = k - 1;
        y--;
    }
    return (tab);
}

char **delete(char **tab, char **av, elem_t *elem, int enter)
{
    int line = my_getnbr(elem->str);
    int matches;
    int x = 0;
    int i = 0;
    if (line > my_getnbr(av[1]))
        enter = -2;
    if (enter == 0)
        matches = my_getnbr(elem->str2);
    elem->kevin = 0;
    elem->djoul = 0;

    if (enter > -1 && enter != 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        elem->djoul++;
        elem->kevin++;
        return (NULL);
    }
    while (elem->str[i] != '\0') {
        if (elem->str[i] == '-') {
            my_putstr("Error: this line is out of range\n");
            elem->kevin++;
            elem->djoul++;
            return (NULL);
        }
        i++;
    }
    if (line > my_getnbr(av[1]) || line <= 0) {
        my_putstr("Error: this line is out of range\n");
        elem->djoul++;
        elem->kevin++;
        return (NULL);
    }
    if (my_getnbr(av[2]) < matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(my_getnbr(av[2]));
        my_putstr(" matches per turn\n");
        elem->djoul++;
        elem->kevin++;
        return (NULL);
    }
    if (matches > nb_pipes(tab, line)) {
        my_putstr("Error: not enough matches on this line\n");
        elem->kevin++;
        elem->djoul++;
        return (NULL);
    }
    if (matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        elem->djoul = 1;
        elem->kevin = 1;
        return (NULL);
    }
    if (enter == 0) {
        my_putstr("Player removed ");
        my_put_nbr(matches);
        my_putstr(" match(es) from line ");
        my_put_nbr(line);
        my_putchar('\n');
        if (nb_pipes(tab, line) >= matches && matches > 0) {
            while (tab[line][x+1] != '\0')
                x++;
            while (tab[line][x] && matches != 0
            && nb_pipes(tab, line) >= matches) {
                while (tab[line][x] == '|') {
                    tab[line][x] = ' ';
                    matches--;
                }
                x--;
            }
            if (check_win(tab) == 0)
                elem->jump = 1;
            printtab(tab, av, elem);
        }
    }
    return (tab);
}

char **ia_turn(char **tab, char **av, elem_t *elem)
{
    int x, y, random, matches = 0;
    int nb = my_getnbr(av[2]);
    int av1 = my_getnbr(av[1]);
    int jul;

    if (elem->kevin == 0) {
        my_putstr("AI's turn...\n");
        while (y < av1 + 2) {
            while (x < av1*2 + 1)
                x++;
            x = 0;
            y++;
        }
        while (x < av1*2 + 1)
            x++;
        x--;
        y = y - 2;
        srand(time(NULL));
        random = go_to_line(tab);
        while (random == 0) {
            random = 1;
            if (nb_pipes(tab, random) == 0)
                random = rand() % av1;
        }
        while (tab[random][x]) {
            while (tab[random][x] == '|' && jul < nb_pipes(tab, random)
            && jul <= nb) {
                jul++;
                tab[random][x] = ' ';
                matches++;
            }
            x--;
        }
        my_putstr("AI removed ");
        my_put_nbr(matches);
        my_putstr(" match(es) from line ");
        my_put_nbr(random);
        my_putchar('\n');
        if (check_win(tab) == 0)
            elem->jump = 1;
        printtab(tab, av, elem);
    }
    elem->kevin = 0;
    return (tab);
}


int loop(char **tab, char **av, elem_t *elem)
{
    int enter = 0;

    while (1) {
        if (elem->djoul == 0)
            my_putstr("Your turn:\n");
        my_putstr("Line: ");
        elem->str = get_next_line(0);
        if (elem->str == NULL) {
            return (0);
        }
        if (elem->str[0] == '\0' || my_getnbr(elem->str) <= 0 ||
            elem->str[0] == '-')
            enter = -1;
        if (check_str(elem, 0) == 84)
            enter = 1;
        if (my_getnbr(elem->str) != 0
        && my_getnbr(elem->str) <= my_getnbr(av[1]) && enter == 0) {
            my_putstr("Matches: ");
            elem->str2 = get_next_line(0);
            if (check_str2(elem, 0) == 84)
                enter = 1;
            if (elem->str2 == NULL) {
                return (0);
                if (elem->str2[0] == '-')
                    enter = -4;
            }
        }
        delete(tab, av, elem, enter);
        if (elem->jump == 1) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        ia_turn(tab, av, elem);
        enter = 0;
        if (elem->jump == 1) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}

int main(int ac, char **av)
{
    char **tab;
    elem_t *elem = malloc(sizeof(elem_t));

    elem->jump = 0;
    if (error_main(ac, av) == 84)
        return (84);
    tab = my_map(av[1]);
    printtab(tab, av, elem);
    return (loop(tab, av, elem));
}