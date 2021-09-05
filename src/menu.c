/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** my menu
*/

#include "../include/rpg.h"

int check_position(sfText* text, sfRenderWindow *window)
{
    sfVector2f text_position = sfText_getPosition(text);
    sfFloatRect bound = sfText_getGlobalBounds(text);
    sfVector2i click_position;

    click_position = sfMouse_getPositionRenderWindow(window);
    if ((text_position.x <= click_position.x && click_position.x
    <= text_position.x + bound.width) && (text_position.y <=
    click_position.y && click_position.y <= text_position.y
    + bound.height))
        return (1);
    return (0);
}

void check_text(sfRenderWindow *window, sfEvent event,
button_t *button, sfVector2i vect)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("assets/305.ogg");
    sfSound_setBuffer(sound, soundbuffer);

    for (int i = vect.x; i < vect.y; i++) {
        if (check_position(button[i].text, window)) {
            sfSound_play(sound);
            (*button[i].my_ptr)(window);
        }
    } sfSoundBuffer_destroy(soundbuffer);
    sfSound_destroy(sound);

}

int events(sfRenderWindow *window, sfEvent event, button_t *button,
sfVector2i vect)
{
    for (; sfRenderWindow_pollEvent(window, &event);) {
        if (event.type == sfEvtMouseButtonPressed) {
            check_text(window, event, button, vect);
        } else if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)) {
            sfRenderWindow_close(window);
        }
    } return (0);
}

void restore_the_game(int q, sfRenderWindow *window)
{
    int w = (q / 50) - 1, k = 0;
    char save[10] = "save_a";
    save[5] = 'a' + w;
    char **sa = fill_map(save);
    k = sa[0][11] - 48;
    player_name = my_strcpy(sa[0]);
    info.att[k] = my_getnbr(sa[1]);
    info.def[k] = my_getnbr(sa[2]);
    info.exp[k] = my_getnbr(sa[3]);
    vie = my_getnbr(sa[4]);
    b_x = my_getnbr(sa[5]);
    b_y = my_getnbr(sa[6]);
    game(window);
}

int load_events(sfRenderWindow *window, int y)
{
    button_t *button = malloc(sizeof(button_t) * 2);
    sfEvent evnt;
    button[0].my_ptr = &menu;
    button[0].text = draw_text(window, "<-<-Previous", (sfVector2f){700, 500}, 50);
    for (; sfRenderWindow_pollEvent(window, &evnt);) {
        if (evnt.type == sfEvtKeyPressed &&
            (evnt.key.code == sfKeyUp || evnt.key.code == sfKeyDown)) {
            return ((evnt.key.code == sfKeyDown) ? 50 : -50);
        } else if (evnt.type == sfEvtKeyPressed && evnt.key.code == sfKeyReturn) {
            restore_the_game(y, window);
        }else
            if (evnt.type == sfEvtClosed ||
(evnt.type == sfEvtKeyPressed && evnt.key.code == sfKeySpace)) {
            sfRenderWindow_close(window);
        }
        check_text(window, evnt,
        button, (sfVector2i){0, 1});
    } return (0);
}

void load(sfRenderWindow *window)
{
    char *save = my_strcpy("save_a");
    int fd = 0, c = 'a', y = 50, x = 50, s = 0, q = 0;
    while (sfRenderWindow_isOpen(window)) {
        fd = 0;
        c = 'a';
        y = 50;
        save[5] = 'a';
        draw_sprite(give_back(), window, (sfVector2f){0, 0});
        for (; fd != -1; c++, y += 50) {
            save[5] = c;
            fd = open(save, O_RDONLY);
            if (fd == -1)
                break;
            draw_text(window, save, (sfVector2f){500, y}, 50);
            close(fd);
            s = 1;
        }
        q += load_events(window, q);
        for (; q < 50; q += 50);
        for (; q > (y - 50); q -= 50);
        if (s == 1)
            draw_sprite("tout/p.png", window, (sfVector2f){300, q});
        sfRenderWindow_display(window);
    }
}

button_t *init_button(button_t *button, sfRenderWindow *window)
{
    button[0].text = draw_text(window, "Demon Slayer!!!", (sfVector2f){500, 100}
, 50);
    button[1].text = draw_text(window, "Settings", (sfVector2f){200, 500}, 50);
    button[1].my_ptr = &setting;
    button[2].text = draw_text(window, "Play", (sfVector2f){600, 300}, 50);
    button[2].my_ptr = &start_rpg;
    button[3].text = draw_text(window, "Quit", (sfVector2f){1000, 500}, 50);
    button[3].my_ptr = &sfRenderWindow_close;
    button[4].text = draw_text(window, "Load", (sfVector2f){600, 500}, 50);
    button[4].my_ptr = &load;
    button[5].text = draw_text(window, "How to play", (sfVector2f){600, 700}, 50);
    button[5].my_ptr = &help;
    return (button);
}

void menu(sfRenderWindow *window)
{
    sfEvent event;
    button_t *button = malloc(sizeof(button_t) * 6);
    init_info();
    b_x = 400;
    b_y = 370;
    while (sfRenderWindow_isOpen(window)) {
        draw_sprite(give_back(), window, (sfVector2f){0, 0});
        button = init_button(button, window);
        events(window, event, button, (sfVector2i){1, 6});
        sfRenderWindow_display(window);
    }
}
