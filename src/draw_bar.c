/*
** EPITECH PROJECT, 2020
** draw_bar.c
** File description:
** draw bar
*/

#include "../include/rpg.h"

void draw_expbar(int a, int b, sfRenderWindow *window, sfView *view)
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
    get_vec(window, (sfVector2i){950, 395}, view), 1);
    draw_text_yellow(window, white,
    get_vec(window, (sfVector2i){950 + s, 395}, view), 0);
}

void draw_defbar(int a, int b, sfRenderWindow *window, sfView *view)
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
    get_vec(window, (sfVector2i){950, 465}, view), 1);
    draw_text_green(window, white,
    get_vec(window, (sfVector2i){950 + s, 465}, view), 0);
}

void draw_viebar(int a, int b, sfRenderWindow *window, sfView *view)
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
    get_vec(window, (sfVector2i){950, 500}, view), 1);
    draw_text_red(window, white,
    get_vec(window, (sfVector2i){950 + s, 500}, view), 0);
}

void draw_attbar(int a, int b, sfRenderWindow *window, sfView *view)
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
    get_vec(window, (sfVector2i){950, 430}, view), 1);
    draw_text_blue(window, white,
    get_vec(window, (sfVector2i){950 + s, 430}, view), 0);
}
