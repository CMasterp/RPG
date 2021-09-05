/*
** EPITECH PROJECT, 2019
** radar.h
** File description:
** header
*/

#ifndef RPG_H_
#define RPG_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"

sfClock *my_clock;
sfTime my_time;
sfClock *my_clock1;
sfTime my_time1;
int sav;
int b_x;
int b_y;

void help(sfRenderWindow *window);

//bars
void draw_xexpbar(sfRenderWindow *window, int a, int b, sfVector2f vec);
void draw_xdefbar(sfRenderWindow *window, int a, int b, sfVector2f vec);
void draw_xviebar(sfRenderWindow *window, int a, int b, sfVector2f vec);
void draw_xattbar(sfRenderWindow *window, int a, int b, sfVector2f vec);
void draw_capacities(sfRenderWindow *window);
int move(double row, double col);
sfVector2f get_vec(sfRenderWindow *window, sfVector2i vector,
sfView *view);
void draw_info(sfRenderWindow *window);
int my_getnbr(char const *str);

//fight
void defender(sfRenderWindow *window);
void saber(sfRenderWindow *window);
int end(player_t *player, sfRenderWindow *window);
void loser(player_t *player, sfRenderWindow *window);
void winner(player_t *player, sfRenderWindow *window);
void draw_fire(sfVector2f position, sfRenderWindow *window);
sfSprite **draw_weapons(sfRenderWindow *window, sfSprite **weap);
sfSprite **init_weapons(sfRenderWindow *window);
sfSprite **draw_weaps(sfRenderWindow *window, sfSprite **weap);
sfSprite **init_weaps(sfRenderWindow *window);
void fight_events(sfSprite **weap, sfSprite **wp, sfRenderWindow *window);
void check_sprite(sfSprite **weap, sfSprite **wp, sfRenderWindow *window);
void draw_boxes(sfVector2f position, sfRenderWindow *window);
int fight(char *house, char *boss, player_t *player, sfRenderWindow *window);

// enter in house
int enter(player_t *player, sfRenderWindow *window);

//talks
int talk_event(sfRenderWindow *window, sfView *view);
void basic_talk(sfView *view, sfRenderWindow *window);
void combat_talk(sfView *view, sfRenderWindow *window);
void talk_simple(sfView *view, sfRenderWindow *window, player_t *player);

//draw bar
void draw_expbar(int a, int b, sfRenderWindow *window, sfView *view);
void draw_defbar(int a, int b, sfRenderWindow *window, sfView *view);
void draw_viebar(int a, int b, sfRenderWindow *window, sfView *view);
void draw_attbar(int a, int b, sfRenderWindow *window, sfView *view);

//draw text in color
sfText *draw_text_red(sfRenderWindow *window, char *str, sfVector2f position,
int si);
sfText *draw_text_blue(sfRenderWindow *window, char *str, sfVector2f position,
int si);
sfText *draw_text_yellow(sfRenderWindow *window, char *str, sfVector2f position,
int si);
sfText *draw_text_green(sfRenderWindow *window, char *str, sfVector2f position,
int si);

//draw_pnj and hand view
void draw_pnj(sfRenderWindow *window);
void walk1(sfIntRect *rect, sfClock *clock);
void move_pnj(sfRenderWindow *window, sfClock *clock);
void move_pnj1(sfRenderWindow *window, sfClock *clock);
void move_pnj2(sfRenderWindow *window, sfClock *clock);
void move_pnj3(sfRenderWindow *window, sfClock *clock);
void move_pnj4(sfRenderWindow *window, sfClock *clock);
void move_pnj5(sfRenderWindow *window, sfClock *clock);
void set_view_pnj(sfRenderWindow *window, sfView *view,
sfVector2f position, sfClock *clock, player_t *player);
void init_info(void);
sfText *draw_text_view(sfRenderWindow *window, char *str,
sfVector2f position, int size);

//background loop
char *give_back(void);
char *my_catt(char *dest, char *src);
char *my_getstring(int nb);

//status && inventory
void draw_status(sfRenderWindow *window, sfView *view);
void draw_weap(sfRenderWindow *window, sfView *view);
void draw_weap1(sfRenderWindow *window, sfView *view);
void display_status(sfRenderWindow *window, sfView *view);
void display_y(int y, sfRenderWindow *window, sfView *view, player_t *player);
void display_inventory(sfRenderWindow *window, sfView *view);

//pause
sfSprite *draw_button_pause(char *filepath, sfRenderWindow *window,
sfView *view);
int check_pos_pause(sfRenderWindow *window, sfEvent event,
sfView *view);
void pause_the_game(sfRenderWindow *window, sfEvent event,
sfView *viw, player_t *player);
int pause_events(sfRenderWindow *window, button_t *button,
int *y, sfView *view);
int ch_wh_ps_button(sfRenderWindow *window, button_t *button,
int *y, sfView *view);
button_t *pause_button(sfRenderWindow *window, button_t *button,
sfView *view);

//load binary map
char **malloc_map(void);
int my_strlen(char *str);
char *my_strcpy(char *str);
char **fill_map(char *filepath);
void free_map(char **map);


//first game part
void game(sfRenderWindow *window);
void game_event(sfRenderWindow *window,
player_t *player, sfClock *clock, sfView *view);

//global variables
sfVector2f my_position;
sfVector2f his_position;
int attack;
int the_weap;
int defend;
int the_wp;
sfMusic *skp_music;
extern sfMusic *skp_music;
int which_perso;
sfIntRect rect_perso;
char *player_name;
int inventory[23];
allinfo info;
int vie;
int pluie;
int att_x;
int exp_x;
int def_x;
int lose;
int vie_x;
char **map;
int ok;
int end_g;

//move character
player_t *init_player(void);
void walk(sfIntRect *rect, sfClock *clock);
void player_moves(player_t *player, sfEvent event, sfClock *clock,
sfRenderWindow *window);

//settings
void menu(sfRenderWindow *window);
void setting(sfRenderWindow *window);
void music_on(sfRenderWindow *window, int a);
void fullscreen_on(sfRenderWindow *window, int a);
void ch_them(button_t *button, sfRenderWindow *window);
int check_position(sfText* text, sfRenderWindow *window);
void check_them(button_t *button, sfRenderWindow *window);
void setting_events(sfRenderWindow *window, button_t *button,
sfEvent event);

//draw sprite
void draw_pj(char *filepath, sfRenderWindow *window,
sfVector2f position, sfClock *clock);
sfSprite *draw_player(char *filepath, sfRenderWindow *window,
sfVector2f position, sfIntRect rect);
sfSprite *draw_sprite(char *filepath, sfRenderWindow *window,
sfVector2f position);
sfText *draw_text(sfRenderWindow *window, char *str,
sfVector2f position, int size);

//story
void skip_music(void);
int draw_story(char *filepath, sfRenderWindow *window,
sfIntRect *rectangle, int limit);
int story_events(sfRenderWindow *window, button_t button,
sfEvent event);
int check_skip(button_t button, sfRenderWindow *window);
button_t create_skip(sfRenderWindow *window, button_t button);
void story(sfRenderWindow *window);

//config
void start_rpg(sfRenderWindow *window);
void config(sfRenderWindow *window);
button_t *create_chose_perso(sfRenderWindow *window,
button_t *button);
void print_rest_perso(sfRenderWindow *window, sfClock *clock);
void check_which_button(button_t *button, sfRenderWindow *window,
sfEvent event);
void print_pers_move(sfRenderWindow *window, sfClock *clock);
void chose_perso_events(sfRenderWindow *window, button_t *button,
sfEvent event);
void print_perso_move(sfRenderWindow *window, sfClock *clock);
void draw_perso(sfRenderWindow *window, sfClock *clock);

#endif /*!RPG_H_*/
