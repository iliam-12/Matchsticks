/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define READ_SIZE 1
struct elem
{
    int djoul;
    int homar;
    int jump;
    int kevin;
    char *str;
    char *str2;
}; typedef struct elem elem_t;

int main(int ac, char **av);
int error_main(int ac, char **av);
char **my_map(char *str);
char **printtab(char **tab, char **av, elem_t *elem);
int empty(char **tab, int line);
int go_to_line(char **tab);
int check_win(char **tab);
int nb_pipes(char **tab, int line);
char **delete(char **tab, char **av, elem_t *elem, int enter);
char **ia_turn(char **tab, char **av, elem_t *elem);
int my_getnbr(char const *str);
char *get_next_line(int fd);
char *re_alloc(char *str);
int my_put_nbr(int nb);
void my_putstr(char const *str);
void my_putchar(char c);
int check_av(char **av, int i, int j);
int check_str(elem_t *elem, int i);
int check_str2(elem_t *elem, int i);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);

#endif /* !MY_H_ */
