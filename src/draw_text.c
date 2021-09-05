/*
** EPITECH PROJECT, 2020
** draw_text.c
** File description:
** draw text in color
*/

#include "../include/rpg.h"

void draw_boxes(sfVector2f position, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){80, 70});
    sfRectangleShape_setPosition(rect, (sfVector2f){position.x, position.y});
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 5);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
}

sfText *draw_text_red(sfRenderWindow *window, char *str, sfVector2f position,
int si)
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
    sfText_setCharacterSize(text, 50);
    if (si == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfRed);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}

sfText *draw_text_blue(sfRenderWindow *window, char *str, sfVector2f position,
int si)
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
    sfText_setCharacterSize(text, 50);
    if (si == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfBlue);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}

sfText *draw_text_yellow(sfRenderWindow *window, char *str, sfVector2f position,
int si)
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
    sfText_setCharacterSize(text, 50);
    if (si == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfYellow);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}

sfText *draw_text_green(sfRenderWindow *window, char *str, sfVector2f position,
int si)
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
    sfText_setCharacterSize(text, 50);
    if (si == 1) {
        sfText_setOutlineThickness(text, 5);
        sfText_setOutlineColor(text, sfGreen);
    }
    sfRenderWindow_drawText(window, text, NULL);
    return (text);
}
