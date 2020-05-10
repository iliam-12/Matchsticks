/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** easy_functions
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i])
        my_putchar(str[i++]);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        my_put_nbr(nb);
        return (0);
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 10 && nb > 0) {
        my_putchar(nb + '0');
        return (0);
    }
    if (nb / 10 > 0) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int cnt = i-1;

    while ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
        i++;
    while (str[i] >= 48 && str[i] <= 57) {
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    while (cnt >= 0 && (str[cnt] == '-' || str[cnt] == '+')) {
        if (str[cnt] == '-')
            nb = nb * -1;
        cnt--;
    }
    return (nb);
}