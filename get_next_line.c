/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_next_line
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *re_alloc(char *str)
{
    char *tchoutchou = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (tchoutchou == NULL)
        return (NULL);
    for (; i <= my_strlen(str); i++)
        tchoutchou[i] = str[i];
    if (str[0] != '\0')
        free(str);
    tchoutchou[i] = '\0';
    return (tchoutchou);
}

char *get_next_line(int fd)
{
    int x = 0;
    int toto = 0;
    char buffer[READ_SIZE];
    char *str = "\0";

    for (int y = 0; 1; x++, y++) {
        str = re_alloc(str);
        if (x >= toto) {
            if ((toto = read(fd, buffer, READ_SIZE)) < 0)
                return (NULL);
            x = 0;
        }
        if (toto == 0)
            return (NULL);
        if (buffer[x] == '\n') {
            x++;
            return (str);
        }
        str[y] = buffer[x];
    }
}