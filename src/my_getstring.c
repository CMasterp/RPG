/*
** EPITECH PROJECT, 2019
** my_getstring
** File description:
** transform a number in a string
*/

#include <stdlib.h>

int count_nbr(int nb)
{
    int n = 0;
    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb = nb / 10;
        n++;
    } return (n);
}

int get_a(int nb)
{
    int g = (count_nbr(nb) - 1), a = 1;
    for (int i = 0; i < g; i++)
        a = a * 10;
    return (a);
}

char *my_getstring(int nb)
{
    int g = (count_nbr(nb) - 1), a = get_a(nb), b = 10, c = get_a(nb);
    int i = 0, q = get_a(nb) / 100;
    char *str = malloc(sizeof(char) * (count_nbr(nb) + 1));
    q = (a / 100);
    for (i = 0; ((a - 1) >= 0) && (i < count_nbr(nb)) && nb >= 0; i++)
        if (a < c) {
            str[i] = (((nb / a) % b) + 48);
            a = a / 10;
        } else if (a == c) {
            str[i] = ((nb / a) + 48);
            a = a / 10;
        } str[i] = '\0';
    return (str);
}
