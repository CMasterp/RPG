/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct info_player {
    char name[10][30];
    int exp[10];
    int att[10];
    int def[10];
} allinfo;

typedef struct player {
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} player_t;


typedef struct button {
    sfText *text;
    void (*my_ptr)(sfRenderWindow*);
    void (*my_music)(sfRenderWindow*, int);
} button_t;

#endif /* !STRUCT_H_ */
