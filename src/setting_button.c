/*
** EPITECH PROJECT, 2020
** setting_button.c
** File description:
** settings
*/

#include "../include/rpg.h"

button_t *my_txt(sfRenderWindow *window, button_t *button)
{
    button[0].text = draw_text(window, "SETTINGS\n", (sfVector2f){500, 0}, 50);
    button[1].text = draw_text(window, "• MUSIC ", (sfVector2f){200, 100}, 25);
    button[2].text = draw_text(window, "• FULLSCREEN ", (sfVector2f){200, 400},
    25);
    button[3].text = draw_text(window, "ON ", (sfVector2f){500, 100}, 25);
    button[3].my_music = &music_on;
    button[4].text = draw_text(window, "OFF\n", (sfVector2f){700, 100}, 25);
    button[4].my_music = &music_on;
    button[5].text = draw_text(window, "ON ", (sfVector2f){500, 400}, 25);
    button[5].my_music = &fullscreen_on;
    button[6].text = draw_text(window, "OFF\n", (sfVector2f){700, 400}, 25);
    button[6].my_music = &fullscreen_on;
    button[7].my_ptr = &menu;
    button[7].text = draw_text(window, "<<<-Previous", (sfVector2f){600, 500},
    50);
    return (button);
}

void check_them(button_t *button, sfRenderWindow *window)
{
    if (check_position(button[7].text, window) == 1)
        (*button[7].my_ptr)(window);
    else if (check_position(button[3].text, window) == 1)
        (*button[3].my_music)(window, 0);
    else
        if (check_position(button[4].text, window) == 1)
            (*button[4].my_music)(window, 1);
}

void setting(sfRenderWindow *window)
{
    sfSprite *sprite = NULL;
    button_t *button = malloc(sizeof(button_t) * 8);
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        sprite = draw_sprite("assets/menu.png", window, (sfVector2f){0, 0});
        button = my_txt(window, button);
        setting_events(window, button, event);
        sfRenderWindow_display(window);
    } sfSprite_destroy(sprite);
}
