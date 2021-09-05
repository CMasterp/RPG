/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** draw inventory
*/

#include "../include/rpg.h"

void draw_weap(sfRenderWindow *window, sfView *view)
{
    draw_sprite("tout/inventory.png", window,
    get_vec(window, (sfVector2i){700, 100}, view));
    draw_sprite("tout/inventory/weap.png", window,
    get_vec(window, (sfVector2i){855, 260}, view));
    draw_sprite("tout/inventory/weap1.png", window,
    get_vec(window, (sfVector2i){840, 326}, view));
    draw_sprite("tout/inventory/weap2.png", window,
    get_vec(window, (sfVector2i){840, 380}, view));
    draw_sprite("tout/inventory/weap3.png", window,
    get_vec(window, (sfVector2i){840, 455}, view));
    draw_sprite("tout/inventory/weap4.png", window,
    get_vec(window, (sfVector2i){910, 260}, view));
    draw_sprite("tout/inventory/weap5.png", window,
    get_vec(window, (sfVector2i){915, 326}, view));
    draw_sprite("tout/inventory/weap6.png", window,
    get_vec(window, (sfVector2i){915, 380}, view));
    draw_sprite("tout/inventory/weap7.png", window,
    get_vec(window, (sfVector2i){915, 455}, view));
    draw_sprite("tout/inventory/weap8.png", window,
    get_vec(window, (sfVector2i){985, 260}, view));
}

void draw_weap1(sfRenderWindow *window, sfView *view)
{
    draw_sprite("tout/inventory/weap9.png", window,
    get_vec(window, (sfVector2i){985, 326}, view));
    draw_sprite("tout/inventory/weap10.png", window,
    get_vec(window, (sfVector2i){985, 380}, view));
    draw_sprite("tout/inventory/weap11.png", window,
    get_vec(window, (sfVector2i){985, 440}, view));
    draw_sprite("tout/inventory/weap12.png", window,
    get_vec(window, (sfVector2i){1040, 260}, view));
    draw_sprite("tout/inventory/weap13.png", window,
    get_vec(window, (sfVector2i){1040, 326}, view));
    draw_sprite("tout/inventory/weap14.png", window,
    get_vec(window, (sfVector2i){1055, 380}, view));
    draw_sprite("tout/inventory/weap15.png", window,
    get_vec(window, (sfVector2i){1055, 440}, view));
}

void display_inventory(sfRenderWindow *window, sfView *view)
{
    int x = 770, y = 520;
    draw_weap(window, view);
    draw_weap1(window, view);
    for (int  j = 0; j < 2; j++, y += 55)
        for (int i = 0, x = 860; i < 4 ; i++, x += 70)
            draw_sprite("tout/qm.png", window,
get_vec(window, (sfVector2i){x, y}, view));
}

void display_gps(sfRenderWindow *window, sfView *view, player_t *player)
{
    char p[2];
    int s = player_name[11] - 48, x = (925 / 1900) + 710, y = (275 / 3000) - 10;
    int a = ((player->position.x * 486) / 1900 + 710);
    int b = (((player->position.y * 768) / 3000) - 10);
    p[0] = info.name[s][0];
    p[1] = '\0';
    draw_sprite("tout/gps.jpg", window,
    get_vec(window, (sfVector2i){700, 0}, view));
    draw_text(window, p,
    get_vec(window, (sfVector2i){a, b}, view), 20);
    /* draw_text(window, "S", */
    /* get_vec(window, (sfVector2i){x, y}, view), 20); */
}

char *get_save(player_t *player)
{
    char *save = my_strcpy("save_0");
    int fd = 0, c = 'a', s = player_name[11] - 48;
    for (; fd != -1; c++) {
        save[5] = c;
        fd = open(save, O_RDONLY);
        close(fd);
    }
    fd = open(save, O_WRONLY | O_APPEND | O_CREAT,
S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    write(fd, player_name, my_strlen(player_name));
    write(fd, "\n", 1);
    write(fd, my_getstring(info.att[s]), my_strlen(my_getstring(info.att[s])));
    write(fd, "\n", 1);
    write(fd, my_getstring(info.def[s]), my_strlen(my_getstring(info.def[s])));
    write(fd, "\n", 1);
    write(fd, my_getstring(info.exp[s]), my_strlen(my_getstring(info.exp[s])));
    write(fd, "\n", 1);
    write(fd, my_getstring(vie), my_strlen(my_getstring(vie)));
    write(fd, "\n", 1);
    write(fd, my_getstring((int)player->position.x), my_strlen(my_getstring((int)player->position.x)));
    write(fd, "\n", 1);
    write(fd, my_getstring((int)player->position.y), my_strlen(my_getstring((int)player->position.y)));
    close(fd);
    return (save);
}

void save(sfRenderWindow *window, sfView *view, player_t *player)
{
    sfEvent evt;
    int o = 0;
    if (sav == 0) {
        char sve[200] = "Saved in --> ";
        char *save = my_catt(sve, get_save(player));
        draw_text(window, save,
get_vec(window, (sfVector2i){700, 300}, view), 60);
    }
}

void display_y(int y, sfRenderWindow *window, sfView *view, player_t *player)
{
    if (y == 1)
        display_status(window, view);
    if (y == 2)
        display_inventory(window, view);
    if (y == 3)
        display_gps(window, view, player);
    if (y == 4) {
        save(window, view, player);
        sav += 1;
    }
}
