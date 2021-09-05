/*
** EPITECH PROJECT, 2020
** move_pnj.c
** File description:
** move pnj
*/

#include "../include/rpg.h"

void move_pnj1(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 1050, y = 325;
    static int a = 1;
    static sfIntRect top = {0, 60, 30, 30};

    if (a == 0) {
        x += 3; top.top = 64;
        walk1(&top, clock);
        if (x >= 1050)
            a = 1;
    } else if (a == 1) {
        x -= 3; top.top = 32;
        walk1(&top, clock);
        if (x <= 775)
            a = 0;
    }
    player->sprite = draw_player("tout/galler17.png",
window, (sfVector2f){x, y}, top);
}

void move_pnj2(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 100, y = 1400;
    static int a = 0;
    static sfIntRect top = {0, 48, 32, 48};

    if (a == 0) {
        x += 1; top.top = 95;
        walk(&top, clock);
        if (x >= 750)
            a = 1;
    } else if (a == 1) {
        x -= 1; top.top = 48;
        walk(&top, clock);
        if (x <= 100)
            a = 0;
    }
    player->sprite = draw_player("tout/villager/villager_0.png",
window, (sfVector2f){x, y}, top);
}

void move_pnj3(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 1250, y = 1400;
    static int a = 0;
    static sfIntRect top = {0, 48, 32, 48};

    if (a == 0) {
        x += 1; top.top = 95;
        walk(&top, clock);
        if (x >= 1500)
            a = 1;
    } else if (a == 1) {
        x -= 1; top.top = 48;
        walk(&top, clock);
        if (x <= 1250)
            a = 0;
    }
    player->sprite = draw_player("tout/villager/villager_1.png",
window, (sfVector2f){x, y}, top);
}

void move_pnj4(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 600, y = 2375;
    static int a = 0;
    static sfIntRect top = {0, 48, 32, 48};

    if (a == 0) {
        x += 1; top.top = 95;
        walk(&top, clock);
        if (x >= 1250)
            a = 1;
    } else if (a == 1) {
        x -= 1; top.top = 48;
        walk(&top, clock);
        if (x <= 600)
            a = 0;
    }
    player->sprite = draw_player("tout/villager/villager_2.png",
window, (sfVector2f){x, y}, top);
}

void move_pnj5(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 1400, y = 600;
    static int a = 0;
    static sfIntRect top = {0, 48, 32, 48};

    if (a == 0) {
        y += 1; top.top = 0;
        walk(&top, clock);
        if (y >= 1250)
            a = 1;
    } else if (a == 1) {
        x -= 1; top.top = 45;
        walk(&top, clock);
        if (x <= 600)
            a = 0;
    }
    player->sprite = draw_player("tout/villager/villager_5.png",
window, (sfVector2f){x, y}, top);
}
