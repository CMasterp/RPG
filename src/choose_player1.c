/*
** EPITECH PROJECT, 2020
** choose_player1.c
** File description:
** choose player first part
*/

#include "../include/rpg.h"

void check_which_button(button_t *button, sfRenderWindow *window, sfEvent event)
{
    if (check_position(button[0].text, window) == 1
|| event.key.code == sfKeyLeft)
        which_perso--;
    else if (check_position(button[1].text, window) == 1
|| event.key.code == sfKeyReturn)
        (*button[1].my_ptr)(window);
    else
        if (check_position(button[2].text, window) == 1
|| event.key.code == sfKeyRight)
            which_perso++;
}

void chose_perso_events(sfRenderWindow *window, button_t *button, sfEvent event)
{
    for (; sfRenderWindow_pollEvent(window, &event); )
        if (event.type == sfEvtClosed ||
(event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
        } else if (event.type == sfEvtMouseButtonPressed
|| event.type == sfEvtKeyPressed)
            check_which_button(button, window, event);
}

void config(sfRenderWindow *window)
{
    sfSprite *sprite = NULL;
    sfClock *clock = sfClock_create();
    button_t *button = malloc(sizeof(button_t) * 3);
    sfEvent event; int c = 0, which_perso = 1;

    rect_perso  = (sfIntRect){0, 0, 32, 48};
    sfMusic_stop(skp_music);
    for (c = 1; sfRenderWindow_isOpen(window); c = 1) {
        sprite = draw_sprite("tout/select_back.jpg", window,
        (sfVector2f){0, 0});
        button = create_chose_perso(window, button);
        chose_perso_events(window, button, event);
        draw_perso(window, clock);
        sfRenderWindow_display(window);
    } sfSprite_destroy(sprite);
}
