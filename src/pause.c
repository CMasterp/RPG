/*
** EPITECH PROJECT, 2020
** pause.c
** File description:
** pause
*/

#include "../include/rpg.h"

button_t *pause_button(sfRenderWindow *window,
button_t *button, sfView *view)
{
    button[0].text = draw_text_view(window, "/STATUS\\",
get_vec(window, (sfVector2i){220, 150}, view), 50);
    button[1].text = draw_text_view(window, "/INVENTORY\\",
get_vec(window, (sfVector2i){220, 240}, view), 50);
    button[2].text = draw_text_view(window, "/RETURN TO MAIN MENU\\",
get_vec(window, (sfVector2i){220, 600}, view), 30);
    button[2].my_ptr = &menu;
    button[3].text = draw_text_view(window, "/RETURN TO THE GAME\\",
get_vec(window, (sfVector2i){220, 720}, view), 30);
    button[4].text = draw_text_view(window, "/QUIT\\",
get_vec(window, (sfVector2i){220, 350}, view), 50);
    button[5].text = draw_text_view(window, "/GPS(-:-)\\",
get_vec(window, (sfVector2i){220, 50}, view), 50);
    button[6].text = draw_text_view(window, "/SAVE\\",
get_vec(window, (sfVector2i){220, 480}, view), 50);
    return (button);
}

int check_pos_pause(sfRenderWindow *window, sfEvent event, sfView *view)
{
    sfVector2i click;
    sfVector2i click_position;

    click_position = sfMouse_getPositionRenderWindow(window);
    if (event.key.code == sfKeyEscape)
        return (1);
    if (event.type == sfEvtMouseButtonPressed
        && (0 <= (float)click_position.x && (float)click_position.x
    <= 0 + 50) && (0 <= (float)click_position.y
    && (float)click_position.y <= 0 + 50))
        return (1);
    return (0);
}

sfSprite *draw_button_pause(char *filepath, sfRenderWindow *window
, sfView *view)
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position = get_vec(window, (sfVector2i){0, 0}, view);
    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    return (sprite);
}
