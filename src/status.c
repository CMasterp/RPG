/*
** EPITECH PROJECT, 2020
** status.c
** File description:
** status prms
*/

#include "../include/rpg.h"

void display_status(sfRenderWindow *window, sfView *view)
{
    int a = player_name[11] - 48;
    sfIntRect rect = (sfIntRect){0, 0, 32, 48};
    draw_sprite("tout/st.png", window,
    get_vec(window, (sfVector2i){700, 100}, view));
    draw_player(player_name, window,
    get_vec(window, (sfVector2i){910, 260}, view), rect);
    draw_text(window, info.name[a],
    get_vec(window, (sfVector2i){950, 380}, view), 20);
    draw_expbar(info.exp[a], 800, window, view);
    draw_attbar(info.att[a], 800, window, view);
    draw_defbar(info.def[a], 800, window, view);
    draw_viebar(vie, 1000, window, view);
}

void draw_status(sfRenderWindow *window, sfView *view)
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_perso  = (sfIntRect){0, 0, 32, 48};

    draw_sprite("tout/player_status2.png", window,
get_vec(window, (sfVector2i){1100, 0}, view));
    texture = sfTexture_createFromFile(player_name, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite,
    get_vec(window, (sfVector2i){1120, 20}, view));
    sfSprite_setTextureRect(sprite, rect_perso);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

sfVector2f get_vec(sfRenderWindow *window, sfVector2i vector,
sfView *view)
{
    sfVector2f vec;
    vec = sfRenderWindow_mapPixelToCoords(window, vector, view);
    return (vec);
}
