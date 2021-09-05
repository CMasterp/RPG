/*
** EPITECH PROJECT, 2020
** draw_fight.c
** File description:
** draw fight
*/

#include "../include/rpg.h"

void draw_fire(sfVector2f position, sfRenderWindow *window)
{
    sfIntRect rect = {400, 0, 100, 100};
    draw_player("tout/explosion.png", window,
    position, rect);
}

sfSprite **draw_weapons(sfRenderWindow *window, sfSprite **weap)
{
    weap[0] = draw_sprite("tout/inventory/weap2.png", window,
    (sfVector2f){1200, 200});
    draw_boxes((sfVector2f){1200, 200}, window);
    weap[1] = draw_sprite("tout/inventory/weap6.png", window,
    (sfVector2f){1200, 300});
    draw_boxes((sfVector2f){1200, 300}, window);
    weap[2] = draw_sprite("tout/inventory/weap7.png", window,
    (sfVector2f){1200, 400});
    draw_boxes((sfVector2f){1200, 400}, window);
    weap[3] = draw_sprite("tout/inventory/weap8.png", window,
    (sfVector2f){1200, 500});
    draw_boxes((sfVector2f){1200, 500}, window);
    weap[4] = draw_sprite("tout/inventory/weap10.png", window,
    (sfVector2f){1200, 600});
    draw_boxes((sfVector2f){1200, 600}, window);
    weap[5] = NULL;
    return (weap);
}

sfSprite **init_weapons(sfRenderWindow *window)
{
    sfSprite **weap = malloc(sizeof(sfSprite*) * 6);

    weap[0] = draw_sprite("tout/inventory/weap2.png", window,
    (sfVector2f){1200, 200});
    draw_boxes((sfVector2f){1200, 200}, window);
    weap[1] = draw_sprite("tout/inventory/weap6.png", window,
    (sfVector2f){1200, 300});
    draw_boxes((sfVector2f){1200, 300}, window);
    weap[2] = draw_sprite("tout/inventory/weap7.png", window,
    (sfVector2f){1200, 400});
    draw_boxes((sfVector2f){1200, 400}, window);
    weap[3] = draw_sprite("tout/inventory/weap8.png", window,
    (sfVector2f){1200, 500});
    draw_boxes((sfVector2f){1200, 500}, window);
    weap[4] = draw_sprite("tout/inventory/weap10.png", window,
    (sfVector2f){1200, 600});
    draw_boxes((sfVector2f){1200, 600}, window);
    weap[5] = NULL;
    return (weap);
}

sfSprite **draw_weaps(sfRenderWindow *window, sfSprite **weap)
{
    weap[0] = draw_sprite("tout/wp.png", window,
    (sfVector2f){20, 200});
    draw_boxes((sfVector2f){20, 200}, window);
    weap[1] = draw_sprite("tout/wp1.png", window,
    (sfVector2f){20, 300});
    draw_boxes((sfVector2f){20, 300}, window);
    weap[2] = draw_sprite("tout/wp2.png", window,
    (sfVector2f){20, 400});
    draw_boxes((sfVector2f){20, 400}, window);
    weap[3] = draw_sprite("tout/wp3.png", window,
    (sfVector2f){20, 500});
    draw_boxes((sfVector2f){20, 500}, window);
    weap[4] = draw_sprite("tout/wp4.png", window,
    (sfVector2f){20, 600});
    draw_boxes((sfVector2f){20, 600}, window);
    weap[5] = NULL;
    return (weap);
}

sfSprite **init_weaps(sfRenderWindow *window)
{
    sfSprite **weap = malloc(sizeof(sfSprite*) * 6);

    weap[0] = draw_sprite("tout/wp.png", window,
    (sfVector2f){20, 200});
    draw_boxes((sfVector2f){20, 200}, window);
    weap[1] = draw_sprite("tout/wp1.png", window,
    (sfVector2f){20, 300});
    draw_boxes((sfVector2f){20, 300}, window);
    weap[2] = draw_sprite("tout/wp2.png", window,
    (sfVector2f){20, 400});
    draw_boxes((sfVector2f){20, 400}, window);
    weap[3] = draw_sprite("tout/wp3.png", window,
    (sfVector2f){20, 500});
    draw_boxes((sfVector2f){20, 500}, window);
    weap[4] = draw_sprite("tout/wp4.png", window,
    (sfVector2f){20, 600});
    draw_boxes((sfVector2f){20, 600}, window);
    weap[5] = NULL;
    return (weap);
}
