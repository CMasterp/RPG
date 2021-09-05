/*
** EPITECH PROJECT, 2020
** draw_pnj.c
** File description:
** draw pnj
*/

#include "../include/rpg.h"

sfView *my_view(sfView *view, sfVector2f position, sfRenderWindow *window)
{
    if ((position.x > 600  && position.x < 8000) &&  position.y > 400) {
        sfView_setCenter(view, position);
        sfRenderWindow_setView(window, view);
    } else if (position.y > 400 && position.x < 600) {
        view = sfView_createFromRect((sfFloatRect){0, position.y - 300, 1300, 700});
        sfRenderWindow_setView(window, view);
    } if (position.y < 400 && position.x < 600) {
        view = sfView_createFromRect((sfFloatRect){0, 0, 1300, 700});
        sfRenderWindow_setView(window, view);
    } else if (position.y < 400 && position.x > 900) {
        view = sfView_createFromRect((sfFloatRect){600, 0, 1300, 700});
        sfRenderWindow_setView(window, view);
    } else if (position.y > 400 && position.x > 900) {
        view = sfView_createFromRect((sfFloatRect){600, position.y - 300, 1300, 700});
        sfRenderWindow_setView(window, view);
    } if (position.y < 400 && position.x < 600) {
        view = sfView_createFromRect((sfFloatRect){0, 0, 1300, 700});
        sfRenderWindow_setView(window, view);
    } if ((position.x >= (float)600 && position.x < 900) && position.y < 400)
        view = sfView_createFromRect((sfFloatRect){position.x - 400, 0, 1300, 700}); {
        sfRenderWindow_setView(window, view);
    } return (view);
}

void set_view_pnj(sfRenderWindow *window, sfView *view,
sfVector2f position, sfClock *clock, player_t *player)
{
    sfClock *clock1 = sfClock_copy(clock),
    *clock2 = sfClock_copy(clock), *clock3 = sfClock_copy(clock),
    *clock4 = sfClock_copy(clock), *clock5 = sfClock_copy(clock);

    view = my_view(view, position, window);
    talk_simple(view, window, player);
    /*sfView_setCenter(view, position);
    sfRenderWindow_setView(window, view);*/
    draw_status(window, view);
    draw_button_pause("tout/pause.png", window, view);
    draw_pnj(window);
    move_pnj(window, clock);
    move_pnj1(window, clock1);
    move_pnj2(window, clock2);
    move_pnj3(window, clock3);
    move_pnj4(window, clock4);
    move_pnj5(window, clock5);
}

void draw_pnj(sfRenderWindow *window)
{
    char pnj[12][30] = {"tout/villager/villager_0.png",
"tout/villager/villager_1.png",
"tout/villager/villager_2.png", "tout/villager/villager_3.png",
"tout/villager/villager_4.png", "tout/villager/villager_5.png",
"tout/villager/villager_6.png", "tout/villager/villager_7.png",
"tout/villager/villager_8.png", "tout/villager/villager_9.png",
"tout/villager/villager_10.png", "tout/villager/villager_11.png"};
    for (int y = 0, j = 0; map[y] != NULL; y++, j++) {
        (j == 12) ? j = 0 : j;
        for (int x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == 'J')
                draw_player(pnj[j], window, (sfVector2f){(float)(x * 25),
(float)(y * 25)}, (sfIntRect){0, 95, 32, 48});
            if (map[y][x] == 'S')
                draw_player("tout/starlord.png", window,
(sfVector2f){(float)(x * 25), (float)(y * 25)}, (sfIntRect){0, 0, 32, 48});
        }
    }
}

void walk1(sfIntRect *rect, sfClock *clock)
{
    sfTime ti = sfClock_getElapsedTime(clock);

    if (sfTime_asSeconds(ti) > 0.15) {
        if (rect->left == 60)
            rect->left = 0;
        rect->left += 30;
        sfClock_restart(clock);
    }
}

void move_pnj(sfRenderWindow *window, sfClock *clock)
{
    player_t *player = init_player();
    static float x = 775, y = 320;
    static int a = 0;
    static sfIntRect top = {0, 60, 30, 30};

    if (a == 0) {
        x += 3; top.top = 64;
        walk1(&top, clock);
        if (x >= 1050)
            a = 1;
    } else if (a == 1) {
        x -= 3; top.top = 30;
        walk1(&top, clock);
        if (x <= 775)
            a =	0;
    }
    player->sprite = draw_player("tout/galler17.png",
window, (sfVector2f){x, y}, top);
}
