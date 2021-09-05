/*
** EPITECH PROJECT, 2020
** settings.c
** File description:
** settings
*/

#include "../include/rpg.h"

void fullscreen_on(sfRenderWindow *window, int a)
{
    if (a == 1) {
        sfRenderWindow_setSize(window, (sfVector2u){1366, 768});
    } if (a == 0) {
        sfRenderWindow_setSize(window, (sfVector2u){1422, 800});
    }
}

void music_on(sfRenderWindow *window, int a)
{
    sfMusic *music = sfMusic_createFromFile("assets/my_music.ogg");
    static int yes = 0;

    if (a == 0 && yes == 0) {
        yes = 1;
        sfMusic_play(music);
        sfMusic_setLoop(music, sfTrue);
    } if (a == 1 && yes == 1) {
        sfMusic_pause(music);
        sfMusic_stop(music);
        yes = 0;
    }
}

void ch_them(button_t *button, sfRenderWindow *window)
{
    if (check_position(button[5].text, window) == 1)
        (*button[5].my_music)(window, 0);
    else if (check_position(button[6].text, window) == 1)
        (*button[6].my_music)(window, 1);
}

void setting_events(sfRenderWindow *window, button_t *button, sfEvent event)
{
    for (; sfRenderWindow_pollEvent(window, &event); ) {
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)) {
            sfRenderWindow_close(window);
        } else if (event.type == sfEvtMouseButtonPressed) {
            check_them(button, window);
            ch_them(button, window);
        }
    }
}
