/*
** EPITECH PROJECT, 2020
** story
** File description:
** story
*/

#include "../include/rpg.h"

int story_events(sfRenderWindow *window, button_t button, sfEvent event)
{
    int a = 0;
    for (; sfRenderWindow_pollEvent(window, &event); )
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
        } else if (event.type == sfEvtMouseButtonPressed)
            a = check_skip(button, window);
    return (a);
}

sfIntRect init_rect(sfIntRect rectangle)
{
    rectangle.left = 0;
    rectangle.top = 0;
    rectangle.width = 1423;
    rectangle.height = 1000;
    return (rectangle);
}

void story(sfRenderWindow *window)
{
    button_t button;
    sfIntRect rectangle;
    sfEvent event;
    int a = 0;
    rectangle = init_rect(rectangle);
    skip_music();
    while (sfRenderWindow_isOpen(window)) {
        a = draw_story("tout/story.jpg", window, &rectangle, (3 * 1423));
        if (a == 1)
            break;
        button = create_skip(window, button);
        a = story_events(window, button, event);
        if (a == 1)
            break;
        sfRenderWindow_display(window);
    }
}

char *my_catt(char *dest, char *src)
{
    int j = 0, k = 0;

    if (src == NULL) {
        dest = NULL;
        return (dest);
    } k = my_strlen(dest);
    for (; src[j] != '\0'; j++)
        dest[k + j] = src[j];
    dest[k + j] = '\0';
    return (dest);
}

void start_rpg(sfRenderWindow *window)
{
    player_name = malloc(sizeof(char) * 20);
    player_name[0] = '\0';
    my_catt(player_name, "tout/pj/pj_0.png");
    story(window);
    config(window);
}
