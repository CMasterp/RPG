/*
** EPITECH PROJECT, 2020
** move_player.c
** File description:
** move player
*/

#include "../include/rpg.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    vie_x = 1000;
    att_x = 700;
    def_x = 650;
    exp_x = 680;
    player->rect = (sfIntRect){0, 95, 32, 48};
    player->sprite = NULL;
    player->position.x = b_x;
    player->position.y = b_y;
    return (player);
}

void free_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++)
        free(map[y]);
    free(map);
}

int move(double row, double col)
{
    int x = (int)round(row / 25);
    int y = (int)round(col / 25);

    if (x > 0 && y > 0 && map[y] != NULL && map[y][x] != '\0') {
        if (map[y][x] == 'J')
            return (2);
        else if (map[y][x] == 'S')
            return (3);
    }
    if (x > 0 && y > 0 && map[y] != NULL && map[y][x] != '\0' &&
    (map[y][x] == '1' || map[y][x] == 'P' || map[y][x] == 'C'))
        return (1);
    return (0);
}

void walk(sfIntRect *rect, sfClock *clock)
{
    sfTime ti = sfClock_getElapsedTime(clock);

    if (sfTime_asSeconds(ti) > 0.15) {
        if (rect->left == 96)
            rect->left = 0;
        rect->left += 32;
        sfClock_restart(clock);
    }
}

void player_moves(player_t *player, sfEvent event, sfClock *clock,
sfRenderWindow *window)
{
    if (event.key.code == sfKeyLeft &&
    move(player->position.x - 2, player->position.y)) {
        player->position.x -= 2; player->rect.top = 48;
        walk(&player->rect, clock);
    } else if (event.key.code == sfKeyRight
    && move(player->position.x + 2, player->position.y)) {
        player->rect.top = 95; player->position.x += 2;
        walk(&player->rect, clock);
    } if (event.key.code == sfKeyUp
    && move(player->position.x, player->position.y - 2)) {
        player->rect.top = 145; player->position.y -= 2;
        walk(&player->rect, clock);
    } else if (event.key.code == sfKeyDown
    && move(player->position.x, player->position.y + 2)) {
        player->rect.top = 0; player->position.y += 2;
        walk(&player->rect, clock);
    }
}
