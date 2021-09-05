/*
** EPITECH PROJECT, 2020
** talk2.c
** File description:
** talk part 2
*/

#include "../include/rpg.h"

int talk_event(sfRenderWindow *window, sfView *view)
{
    sfEvent event;

    for (; sfRenderWindow_pollEvent(window, &event);) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            return (1);;
    }
    return (0);
}

void basic_talk(sfView *view, sfRenderWindow *window)
{
    char str[160] = "Salut ";
    char src[100] = "!\nBienvenue, ici c'est le monde de Princesca!^ ^!\n";
    char ss[90] = "Le Seigneur t'attend au chateau, je t'y conduis !!";
    int c = player_name[11] - 48;
    my_catt(str, info.name[c]);
    my_catt(src, ss);
    my_catt(str, src);
    for (; sfRenderWindow_isOpen(window);) {
        if (talk_event(window, view) == 1)
            break;
        draw_sprite("tout/dialogue/text_box.png", window,
get_vec(window, (sfVector2i){650, 300}, view));
        draw_text_view(window, str,
get_vec(window, (sfVector2i){780, 620}, view), 20);
        sfRenderWindow_display(window);
    }
}
