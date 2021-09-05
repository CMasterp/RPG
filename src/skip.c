/*
** EPITECH PROJECT, 2020
** story_music.c
** File description:
** story music
*/

#include "../include/rpg.h"

button_t create_skip(sfRenderWindow *window, button_t button)
{
    button.text = draw_text(window, "SKIP/->/", (sfVector2f){1200, 700}, 20);
    button.my_ptr = &config;
    return (button);
}

int check_skip(button_t button, sfRenderWindow *window)
{
    if (check_position(button.text, window) == 1) {
        (*button.my_ptr)(window);
        return (1);
    } return (0);
}

void skip_music(void)
{
    skp_music = sfMusic_createFromFile("tout/story.ogg");
    sfMusic_play(skp_music);
}

char *give_back(void)
{
    char *str = malloc(sizeof(char) * 100);
    int a = 0;
    str[0] = '\0';
    srand(time(NULL));
    a = rand() % 20;
    (a <= 0) ? a += 20 : a;
    (a >= 20) ? a -= 20 : a;
    (a == 0) ? a = 1 : a;
    if (a < 10) {
        str = my_catt(str, "tout/back/0");
        str = my_catt(str, my_getstring(a));
    } else {
        str = my_catt(str, "tout/back/");
        str = my_catt(str, my_getstring(a));
    } str = my_catt(str, ".jpg");
    return (str);
}
