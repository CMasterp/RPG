/*
** EPITECH PROJECT, 2020
** print_perso.c
** File description:
** print perso
*/

#include "../include/rpg.h"

void print_rest_perso(sfRenderWindow *window, sfClock *clock)
{
    if (which_perso == 8) {
        draw_pj("tout/pj/pj_8.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '8';
    } if (which_perso == 9) {
        draw_pj("tout/pj/pj_9.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '9';
    }
}

void print_pers_move(sfRenderWindow *window, sfClock *clock)
{
    if (which_perso == 4) {
        draw_pj("tout/pj/pj_4.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '4';
    } if (which_perso == 5) {
        draw_pj("tout/pj/pj_5.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '5';
    } if (which_perso == 6) {
        draw_pj("tout/pj/pj_6.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '6';
    } if (which_perso == 7) {
        draw_pj("tout/pj/pj_7.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '7';
    } print_rest_perso(window, clock);
}

void print_perso_move(sfRenderWindow *window, sfClock *clock)
{
    if (which_perso == 0) {
        draw_pj("tout/pj/pj_0.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '0';
    } if (which_perso == 1) {
        draw_pj("tout/pj/pj_1.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '1';
    } if (which_perso == 2) {
        draw_pj("tout/pj/pj_2.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '2';
    } if (which_perso == 3) {
        draw_pj("tout/pj/pj_3.png", window, (sfVector2f){600, 200}, clock);
        player_name[11] = '3';
    } print_pers_move(window, clock);
}

void draw_perso(sfRenderWindow *window, sfClock *clock)
{
    if (which_perso < 0)
        for (; which_perso < 0; which_perso += 10);
    if (which_perso > 9)
        for (; which_perso > 9; which_perso -= 10);
    print_perso_move(window, clock);
}
