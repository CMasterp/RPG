/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enter_in_house.c
*/

#include "../include/rpg.h"

void fight_events(sfSprite **weap, sfSprite **wp, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed)
            check_sprite(weap, wp, window);
        else if (event.type == sfEvtClosed ||
        event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
}

void check_sprite(sfSprite **weap, sfSprite **wp, sfRenderWindow *window)
{
    sfVector2i click_position;
    sfFloatRect bound;
    sfVector2f sprite_position;

    for (int i = 0; i < 5; i++) {
        click_position = sfMouse_getPositionRenderWindow(window);
        bound = sfSprite_getGlobalBounds(weap[i]);
        sprite_position = sfSprite_getPosition(weap[i]);
        if ((sprite_position.x <= click_position.x && click_position.x
        <= (sprite_position.x + bound.width)) && (sprite_position.y <=
        click_position.y && click_position.y <= (sprite_position.y
        + bound.height))) {
            attack = 1;
            the_weap = i;
        }
    }
}

void fight1(char *house, char *boss, player_t *player, sfRenderWindow *window)
{
    sfSprite **weap = init_weapons(window), **wp = init_weaps(window);
    sfSprite *enemy = NULL; sfIntRect rect;
    if (boss[5] == 'g')
        rect = (sfIntRect){0, 64, 30, 30};
    else
        rect = (sfIntRect){0, 96, 32, 48};
    sfRenderWindow_clear(window, sfBlack);
    draw_sprite(house, window, (sfVector2f){0, 0}); draw_info(window);
    player->sprite = draw_player(player_name, window,
    (sfVector2f){1000, 400}, player->rect);
    enemy = draw_player(boss, window, (sfVector2f){300, 400}, rect);
    weap = draw_weapons(window, weap); wp = draw_weaps(window, wp);
    fight_events(weap, wp, window);
}

int lose_events(sfRenderWindow *window)
{
    button_t *button = malloc(sizeof(button_t) * 2);
    sfEvent evnt;
    button[0].my_ptr = &menu;
    button[0].text = draw_text(window, "<-<-quit", (sfVector2f){700, 700}, 50);
    for (; sfRenderWindow_pollEvent(window, &evnt);) {
         for (int i = 0; i < 1; i++) {
             if (check_position(button[i].text, window))
                 return 1;
         }
    }
    return (0);
}

int fight(char *house, char *boss, player_t *player, sfRenderWindow *window)
{
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, 1366, 768});
    sfSprite **weap = init_weapons(window), **wp = init_weaps(window);
    for (player->rect.top = 48; sfRenderWindow_isOpen(window);) {
        fight1(house, boss, player, window);
        weap = draw_weapons(window, weap); wp = draw_weaps(window, wp);
        my_time = sfClock_getElapsedTime(my_clock);
        my_time1 = sfClock_getElapsedTime(my_clock1);
        if (attack == 1)
            saber(window);
        if (sfTime_asSeconds(my_time1) > 3) {
            defender(window);
        }
        if (lose != 0) {
            end(player, window);
            if (lose_events(window))
                break;
        }
        sfRenderWindow_setView(window, view); sfRenderWindow_display(window);
    }
    player->position = (lose == 1) ? (sfVector2f){950, 275} : (sfVector2f){400, 370};
    if (lose == 1) {
         end_g = 1;
      lose = 0; return 1;
    } else {
        lose = 0; return 0;
    } return 2;
}

int enter(player_t *player, sfRenderWindow *window)
{
    int i = 0;
    int x = (int)round(player->position.x / 25);
    int y = (int)round(player->position.y / 25);

    if (x > 0 && y > 0 && map[y] != NULL && map[y][x] != '\0' &&
    map[y][x] == 'P') {
        i = fight("tout/home.jpg", "tout/galler17.png", player, window);
        return (i);
    } else if (x > 0 && y > 0 && map[y] != NULL && map[y][x] != '\0' &&
    map[y][x] == 'C')
        i = fight("tout/home.jpg", "tout/starlord.png", player, window);
    return (0);
}
