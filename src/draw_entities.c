/*
** EPITECH PROJECT, 2020
** draw_entities
** File description:
** draw sprites text
*/

#include "../include/rpg.h"

void draw_pj(char *filepath, sfRenderWindow *window,
sfVector2f position, sfClock *clock)
{
    sfSprite *sprite;
    sfTexture *texture;

    walk(&rect_perso, clock);
    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTextureRect(sprite, rect_perso);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int draw_story(char *filepath, sfRenderWindow *window,
sfIntRect *rectangle, int limit)
{
    sfSprite *sprite = NULL;
    sfVector2f position = (sfVector2f){0, 0};
    sfTexture *texture;
    static float o = 0;
    if (rectangle->left >= limit)
        return (1);
    (rectangle->left < limit) ? rectangle->left += 5 : 0;
    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTextureRect(sprite, *rectangle);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}

sfText *draw_text(sfRenderWindow *window, char *str, sfVector2f position,
int size)
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
    if (check_position(text, window) == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfBlue);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}

sfSprite *draw_sprite(char *filepath, sfRenderWindow *window,
sfVector2f position)
{
    sfSprite *sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    return (sprite);
}

sfSprite *draw_player(char *filepath, sfRenderWindow *window,
sfVector2f position, sfIntRect rect)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return (sprite);
}
