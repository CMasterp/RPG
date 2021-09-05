/*
** EPITECH PROJECT, 2020
** choose_player2.c
** File description:
** chooser player part 2
*/

#include "../include/rpg.h"

button_t *create_chose_perso(sfRenderWindow *window, button_t *button)
{
    button[0].text = draw_text(window, "/<-/PREVIOUS", (sfVector2f){100, 500},
    20);
    button[1].text = draw_text(window, "CHOOSE", (sfVector2f){600, 400}, 20);
    button[1].my_ptr = &game;
    button[2].text = draw_text(window, "NEXT/->/", (sfVector2f){1000, 500}, 20);
    return (button);
}
