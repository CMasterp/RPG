/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game.c
*/

#include "../include/rpg.h"

float ps_x;
float ps_y;

void game_event(sfRenderWindow *window, player_t *player,
sfClock *clock, sfView *view)
{
    sfEvent event;

    for (; sfRenderWindow_pollEvent(window, &event);) {
        if (event.type == sfEvtClosed
        || (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace))
            sfRenderWindow_close(window);
        else if (check_pos_pause(window, event, view) == 1)
            pause_the_game(window, event, view, player);
        else
            if (event.type == sfEvtKeyPressed)
                player_moves(player, event, clock, window);
    }
}

void rain(sfView *view, sfRenderWindow *window)
{
    static sfIntRect rectangle = {0, 0, 1300, 700};
    int a = 0;
    a = draw_story("tout/rain.png", window, &rectangle, 2600);
    if (a == 1)
        rectangle = (sfIntRect){0, 0, 1300, 700};
}

void game(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create(), *clock1 = sfClock_create();
    player_t *player = init_player();
    sfView *view = sfView_create();
    my_clock = sfClock_create();
    my_time = sfClock_getElapsedTime(my_clock);
    my_clock1 = sfClock_create();
    my_time1 = sfClock_getElapsedTime(my_clock1);
    ps_x = 0, ps_y = 0, pluie = 0;
    sfView_setSize(view, (sfVector2f){1300, 700});
    for (; sfRenderWindow_isOpen(window);) {
        sfRenderWindow_clear(window, sfBlack);
        draw_sprite("tout/map.jpg", window, (sfVector2f){0, 0});
        player->sprite = draw_player(player_name,
        window, player->position, player->rect);
        /* if (pluie == 1) */
        /*     rain(view, window); */
        game_event(window, player, clock, view);
        set_view_pnj(window, view, player->position, clock1, player);
        enter(player, window);
        sfRenderWindow_display(window);
    }
}
