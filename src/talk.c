/*
** EPITECH PROJECT, 2020
** talk.c
** File description:
** talks
*/

#include "../include/rpg.h"

void combat_talk(sfView *view, sfRenderWindow *window)
{
    char str[160] = "\t---GARDE ROYALE---\nHo toi ";
    char src[100] = "\nViens ici montrer ce que t'as dans le ventre!";
    int c = player_name[11] - 48;
    my_catt(str, info.name[c]);
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

char *my_copy(char *dest, char *src)
{
    int j = 0, k = 0;

    if (src == NULL) {
        dest = NULL;
        return (dest);
    }
    for (; src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return (dest);
}

void tlk(char talk[7][1000])
{
    my_copy(talk[0], "SEIGNEUR NUMA : Bonjour ");
    my_copy(talk[1], "Me : Bonjour NUMA\nSEIGNEUR NUMA :\
Notre village est soumis a une \nmalediction d'ou cette pluie anormale!");
    my_copy(talk[2], "Me : Oui mon seigneur j'ai fait le constat\nSEIGNEUR\
NUMA : Le conseil et moi avions compris\nsuite aux\
informations provenant des sages du \nvillage que tu est le hero de la\
prophetie!\n");
    my_copy(talk[3], "Me : ...Et que se passera t-il alors ?\nSEIGNEUR NUMA :\
Il est dit dans la prophetie que \nseul un hero au coeur pur pourra sauver\
notre\nvillage en reunissant des artefacts qui ensembles ");
    my_copy(talk[4], "pourront mettre fin\
a cette malediction\nMe : Je dois donc reunir ces artefacts Seigneur\nNUMA ?\
\nSEIGNEUR NUMA : Oui tu devras donc combattre");
    my_copy(talk[5], "des \
capitaines invincibles de la garde royale qui\nprotegent ces artefacts et\
ne les donnent qu'a\ncelui qui pourra les vaincre.! Bonne chance ");
}

void draw_talk(sfView *view, char *str, sfRenderWindow *window)
{
    draw_sprite("tout/dialogue/text_box.png",
window, get_vec(window, (sfVector2i){650, 300}, view));
    draw_text_view(window, str,
get_vec(window, (sfVector2i){780, 620}, view), 20);
}

void quete_talk(sfRenderWindow *window, sfView *view)
{
    char talk[7][1000];
    int c = player_name[11] - 48, o = 0;
    tlk(talk);
    my_catt(talk[0], info.name[c]);
    my_catt(talk[5], info.name[c]);
    if (end_g == 1) {
    draw_sprite("tout/back/07.jpg",
window, get_vec(window, (sfVector2i){0, 0}, view));
        draw_talk(view,
"Felicitations, le village est sain et sauf", window);
        sfRenderWindow_display(window);
        while (talk_event(window, view) != 1);
        sfRenderWindow_close(window);
    }
    for (; sfRenderWindow_isOpen(window);) {
        if (talk_event(window, view) == 1)
            o++;
        if (o == 6)
            break;
        draw_talk(view, talk[o], window);
        sfRenderWindow_display(window);
    }
}

void talk_simple(sfView *view, sfRenderWindow *window, player_t *player)
{
    int a = 0, b = 0, c = 0, d = 0;
    a = move(player->position.x - 2, player->position.y);
    b = move(player->position.x + 2, player->position.y);
    c = move(player->position.x, player->position.y - 2);
    d = move(player->position.x, player->position.y + 2);
    if (a == 2 || b == 2 || c == 2 || d == 2) {
        basic_talk(view, window);
        pluie = 1;
        player->position.x = 950;
        player->position.y = 275;
    } else if (a == 3 || b == 3 || c == 3 || d == 3) {
        quete_talk(window, view);
        player->position.x = 400;
        player->position.y = 370;
    }
}
