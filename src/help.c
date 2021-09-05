/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** help
*/

#include "../include/rpg.h"

sfSprite *draw(sfRenderWindow *window, char *filepath, sfVector2f position)
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

void my_text(sfRenderWindow *window)
{
    sfText *text = NULL;

    text = draw_text(window, "How to play!!!!\n", (sfVector2f){500, 0}, 50);
    text = draw_text(window, "• Tu es un  joueur doit sauver le village en rapportant un\
    artefact au chef du village pour stopper la pluie,\n", (sfVector2f){20, 60}, 25);
    text = draw_text(window, "• Pour y parvenir tu doit affronter des ennemis et leur reprendre\
    le livre contenant le sort pour sauver le village\n", (sfVector2f){20, 120}, 25);
    text = draw_text(window, "• Pour te promener dans la map\
    utilise les touches directionnelles,\n", (sfVector2f){200, 180}, 25);
    text = draw_text(window, "• Et sauve le village avant qu'il ne soit trop tard\n", (sfVector2f){20, 240}, 25);
    text = draw_text(window, "• Nous comptons sur toi\n", (sfVector2f){200, 300}, 25);
}

void help_events(sfRenderWindow *window, button_t button, sfEvent event)
{
    sfVector2f text_position = sfText_getPosition(button.text);
    sfFloatRect bound = sfText_getGlobalBounds(button.text);
    sfVector2i click_position;

    for (; sfRenderWindow_pollEvent(window, &event); ) {
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace))
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            click_position = sfMouse_getPositionRenderWindow(window);
            if ((text_position.x <= click_position.x && click_position.x
            <= text_position.x + bound.width)&& (text_position.y <=
            click_position.y && click_position.y <= text_position.y
            + bound.height))
                (*button.my_ptr)(window);
        }
    }
}

void help(sfRenderWindow *window)
{
    sfSprite *sprite = NULL;
    button_t button;
    sfEvent event;

    button.my_ptr = &menu;
    button.text = draw_text(window, "<-<-Previous", (sfVector2f){600, 500}, 50);
    while (sfRenderWindow_isOpen(window)) {
        help_events(window, button, event);
        sprite = draw(window, give_back(), (sfVector2f){0, 0});
        my_text(window);
        button.my_ptr = &menu;
        button.text = draw_text(window, "<-<-Previous", (sfVector2f){600, 500},
        50);
        sfRenderWindow_display(window);
    }
    sfText_destroy(button.text);
    sfSprite_destroy(sprite);
}