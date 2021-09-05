/*
** EPITECH PROJECT, 2020
** fight.c
** File description:
** hand fight
*/

#include "../include/rpg.h"

int please(sfRenderWindow *window)
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

void winner(player_t *player, sfRenderWindow *window)
{
    pluie = 0;
    draw_sprite("tout/home.jpg", window, (sfVector2f){0, 0});
    draw_text(window, "Felicitation tu viens de trouver le livre",
    (sfVector2f){300, 200}, 50);
    draw_text(window, "Qui sauvera le village!!!!!!!!!",
    (sfVector2f){400, 300}, 50);
    draw_sprite("tout/book.png", window, (sfVector2f){450, 400});
    draw_text(window, "Cours le remettre au chef!!!!!!!!!!!!",
    (sfVector2f){650, 500}, 50);
}

void loser(player_t *player, sfRenderWindow *window)
{
    vie = 1000;
    draw_sprite("tout/home.jpg", window, (sfVector2f){0, 0});
    draw_text(window, "Desole ;( tu as perdu",
    (sfVector2f){300, 200}, 50);
    draw_text(window, "Essaye encore tout le village compte sur toi",
    (sfVector2f){400, 300}, 50);
    draw_text(window, "Courage, Que la force soit avec toi!!!!!!!!!!!!",
    (sfVector2f){500, 400}, 50);
}

int end(player_t *player, sfRenderWindow *window)
{
    if (lose == 1) {
        ok = 1;
        winner(player, window);
        attack = 0;
        defend = 0;
        return (1);
    } else if (lose == 2) {
        loser(player, window);
        attack = 0;
        defend = 0;
        return (2);
    }
    return (0);
}

char *init_attack()
{
    char weaps[5][27] = {"tout/inventory/weap2.png", "tout/inventory/weap6.png", 
    "tout/inventory/weap7.png", "tout/inventory/weap8.png",
    "tout/inventory/weap10.png"};

    return (my_strcpy(weaps[the_weap]));
}

char *init_defense()
{
    char weaps[5][27] = {"tout/wp.png", "tout/wp1.png", "tout/wp2.png",
    "tout/wp3.png", "tout/wp4.png"};

    return (my_strcpy(weaps[the_wp]));
}

void saber(sfRenderWindow *window)
{
    char *str = init_attack();
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("assets/305.ogg");

    sfSound_setBuffer(sound, soundbuffer);
    if (sfTime_asMilliseconds(my_time) >= 150) {
        my_position.x -= 75;
        sfClock_restart(my_clock);
    }
    draw_sprite(str, window, my_position);
    if (my_position.x <= 270) {
        sfSound_play(sound); my_position.x = 900;
        draw_fire((sfVector2f){270, 380}, window);
        attack = 0, the_wp = the_weap, the_weap = 0;
        vie_x -= 300, def_x -= 80;
        if (vie_x <= 0)
            lose = 1;
        defend = 1;
    }
    sfSoundBuffer_destroy(soundbuffer);
    sfSound_destroy(sound);
}

void defender(sfRenderWindow *window)
{
    char *str = init_defense();
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("assets/305.ogg");
    int a = player_name[11] - 48;
    sfSound_setBuffer(sound, soundbuffer);
    if (sfTime_asMilliseconds(my_time) >= 150) {
        his_position.x += 75;
        sfClock_restart(my_clock);
    }
    draw_sprite(str, window, his_position);
    if (his_position.x >= 850) {
        his_position.x = 400;
        sfSound_play(sound);
        draw_fire((sfVector2f){970, 380}, window);
        defend = 0;
        if (vie <= 0)
            lose = 2;
        sfClock_restart(my_clock1);
        vie -= 100; info.def[a] -= 40;
    } sfSoundBuffer_destroy(soundbuffer);
    sfSound_destroy(sound);
}
