/*
** EPITECH PROJECT, 2020
** fight_bar.c
** File description:
** bar for fight
*/

#include "../include/rpg.h"

void draw_xexpbar(sfRenderWindow *window, int a, int b, sfVector2f vec)
{
    int nb_red = (10 * a) / b, nb_white = 10 - nb_red;
    int s = (10 * nb_red) + 4;
    char red[10], white[10];
    red[0] = '\0';
    white[0] = '\0';
    for (; nb_red > 0; nb_red--)
        my_catt(red, ".");
    for (; nb_white > 0; nb_white--)
        my_catt(white, ".");
    draw_text_yellow(window, red,
vec, 1);
    draw_text_yellow(window, white,
(sfVector2f){vec.x + s, vec.y}, 0);
}

void draw_xdefbar(sfRenderWindow *window, int a, int b, sfVector2f vec)
{
    int nb_red = (a * 10) / b, nb_white = 10 - nb_red;
    int s = (10 * nb_red) + 4;
    char red[10], white[10];
    red[0] = '\0';
    white[0] = '\0';
    for (; nb_red > 0; nb_red--)
        my_catt(red, ".");
    for (; nb_white > 0; nb_white--)
        my_catt(white, ".");
    draw_text_green(window, red,
vec, 1);
    draw_text_green(window, white,
(sfVector2f){vec.x + s, vec.y}, 0);
}

void draw_xviebar(sfRenderWindow *window, int a, int b, sfVector2f vec)
{
    int nb_red = (a * 10) / b, nb_white = 10 - nb_red;
    int s = (10 * nb_red) + 4;
    char red[10], white[10];
    red[0] = '\0';
    white[0] = '\0';
    for (; nb_red > 0; nb_red--)
        my_catt(red, ".");
    for (; nb_white > 0; nb_white--)
        my_catt(white, ".");
    draw_text_red(window, red,
vec, 1);
    draw_text_red(window, white,
(sfVector2f){vec.x + s, vec.y}, 0);
}

void draw_xattbar(sfRenderWindow *window, int a, int b, sfVector2f vec)
{
    int nb_red = (a * 10) / b, nb_white = 10 - nb_red;
    int s = (10 * nb_red) + 4;
    char red[10], white[10];
    red[0] = '\0';
    white[0] = '\0';
    for (; nb_red > 0; nb_red--)
        my_catt(red, ".");
    for (; nb_white > 0; nb_white--)
        my_catt(white, ".");
    draw_text_blue(window, red,
vec, 1);
    draw_text_blue(window, white,
(sfVector2f){vec.x + s, vec.y}, 0);
}

void draw_capacities(sfRenderWindow *window)
{
    int a = player_name[11] - 48;
    draw_text(window, info.name[a],
(sfVector2f){1000, 100}, 20);
    draw_text(window, "Garde Royal",
(sfVector2f){300, 100}, 20);
    draw_xexpbar(window, info.exp[a], 800, (sfVector2f){1000, 150});
    draw_xattbar(window, info.att[a], 800, (sfVector2f){1000, 200});
    draw_xdefbar(window, info.def[a], 800, (sfVector2f){1000, 250});
    draw_xviebar(window, vie, 1000, (sfVector2f){1000, 300});
    draw_xexpbar(window, exp_x, 800, (sfVector2f){300, 150});
    draw_xattbar(window, att_x, 800, (sfVector2f){300, 200});
    draw_xdefbar(window, def_x, 800, (sfVector2f){300, 250});
    draw_xviebar(window, vie_x, 1000, (sfVector2f){300, 300});
}

void draw_info(sfRenderWindow *window)
{
    int a = player_name[11] - 48;
    draw_text(window, info.name[a],
(sfVector2f){1000, 100}, 20);
    draw_text(window, "Garde Royal",
(sfVector2f){300, 100}, 20);
    draw_xexpbar(window, info.exp[a], 800, (sfVector2f){1000, 150});
    draw_xattbar(window, info.att[a], 800, (sfVector2f){1000, 200});
    draw_xdefbar(window, info.def[a], 800, (sfVector2f){1000, 250});
    draw_xviebar(window, vie, 1000, (sfVector2f){1000, 300});
    draw_xexpbar(window, exp_x, 800, (sfVector2f){300, 150});
    draw_xattbar(window, att_x, 800, (sfVector2f){300, 200});
    draw_xdefbar(window, def_x, 800, (sfVector2f){300, 250});
    draw_xviebar(window, vie_x, 1000, (sfVector2f){300, 300});
}
