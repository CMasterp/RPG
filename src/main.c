/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "../include/rpg.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = NULL;

    ok = 0;
    my_position = (sfVector2f){900, 380};
    his_position = (sfVector2f){400, 380};
    attack = 0;
    the_weap = 0;
    defend = 0;
    the_wp = 0;
    map = fill_map("map");
    lose = 0;
    window = sfRenderWindow_create((sfVideoMode){1366, 768, 32},
    "My rpg", sfFullscreen | sfClose, NULL);
    for (int o = 0; o <= 23; o++)
        inventory[o] = 0;
    menu(window);
    free_map(map);
    sfRenderWindow_destroy(window);
    return (0);
}
