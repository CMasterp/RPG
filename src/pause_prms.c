/*
** EPITECH PROJECT, 2020
** pause_prms.c
** File description:
** hand pause button
*/

#include "../include/rpg.h"

extern float ps_x;
extern float ps_y;
sfView *wiev;
sfEvent event;

int check_pos_view(sfText* text, sfRenderWindow *window)
{
    sfVector2f tt_position = sfText_getPosition(text);
    sfFloatRect bound = sfText_getGlobalBounds(text);
    sfVector2i click_position;
    sfVector2i text_position;

    text_position = sfRenderWindow_mapCoordsToPixel(window,
    tt_position, wiev);
    click_position = sfMouse_getPositionRenderWindow(window);
    if ((text_position.x <= click_position.x && click_position.x
    <= text_position.x + bound.width) && (text_position.y <=
    click_position.y && click_position.y <= text_position.y
    + bound.height))
        return (1);
    return (0);
}

sfText *draw_text_view(sfRenderWindow *window, char *str,
sfVector2f position, int size)
{
    sfFont* font = NULL;
    sfText* text = NULL;
    font = sfFont_createFromFile("tout/button.ttf");
    if (!font)
        return (NULL);
    text = sfText_create();
    sfText_setPosition(text, position);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    if (check_pos_view(text, window) == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfBlue);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}

int ch_wh_ps_button(sfRenderWindow *window, button_t *button,
int *y, sfView *view)
{
    sfFloatRect rect = {0, 0, 1366, 768};
    if (check_pos_view(button[0].text, window) == 1)
        *y = 1;
    else if (check_pos_view(button[1].text, window) == 1)
        *y = 2;
    else
        if (check_pos_view(button[2].text, window) == 1) {
            sfView_reset(view, rect);
            sfRenderWindow_setView(window, view);
            (*button[2].my_ptr)(window);
        } else if (check_pos_view(button[3].text, window) == 1
        || event.key.code == sfKeyEscape) {
            sav = 0;
            return (1);
        }
    return (0);
}

int pause_events(sfRenderWindow *window, button_t *button,
int *y, sfView *view)
{
    int a = 0;
    for (; sfRenderWindow_pollEvent(window, &event); )
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed
&& event.key.code == sfKeyQ) || (event.type == sfEvtMouseButtonPressed
&& check_pos_view(button[4].text, window) == 1)) {
            sfRenderWindow_close(window);
        } else if (event.type == sfEvtMouseButtonPressed &&
check_pos_view(button[5].text, window) == 1) {
            *y = 3;
        } else if (event.type == sfEvtMouseButtonPressed &&
check_pos_view(button[6].text, window) == 1) {
            *y = 4;
        } else
              if (event.type == sfEvtMouseButtonPressed
|| event.type == sfEvtKeyPressed)
                  a = ch_wh_ps_button(window, button, y, view);
    return (a);
}

void pause_the_game(sfRenderWindow *window, sfEvent event,
sfView *viw, player_t *player)
{
    sfSprite *sprite = NULL;
    button_t *button = malloc(sizeof(button_t) * 7);
    int a = 0, y = 0;
    viw = sfView_createFromRect((sfFloatRect){0, 0, 1300, 700});
    draw_sprite("tout/pause.png", window, get_vec(window,
    (sfVector2i){0, 0}, viw));
    for (; sfRenderWindow_isOpen(window); ) {
        draw_sprite(give_back(), window,
        get_vec(window, (sfVector2i){0, 0}, viw));
        button = pause_button(window, button, viw);
        if (pause_events(window, button, &y, viw) == 1)
            break;
        display_y(y, window, viw, player);
        sfRenderWindow_setView(window, viw);
        sfRenderWindow_display(window);
    }
    draw_sprite("tout/pause.png", window, (sfVector2f){ps_x, ps_y});
}
