/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** load my_map
*/

#include "../include/rpg.h"

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    for ( ; str[len] != '\0'; len++);
    return (len);
}

char *my_strcpy(char *str)
{
    int i = 0;
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));

    copy[0] = '\0';
    for (; str[i] != '\0' && str[i] != '\n'; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return (copy);
}

char **malloc_map(void)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * 121);
    for (int i = 0; i < 120; i++) {
        map[i] = malloc(sizeof(char) * 77);
        map[i][0] = '\0';
    } map[120] = NULL;
    return (map);
}

char **fill_map(char *filepath)
{
    char *str = NULL, **map = malloc_map();
    FILE *file = fopen(filepath, "r");
    ssize_t rd = 0;
    size_t n = 0;
    int i = 0;

    if (file == NULL)
        return (NULL);
    rd = getline(&str, &n, file);
    for (; map[i] != NULL && rd != -1 && str[0] != '\0' && str[0] != '\n';
    rd = getline(&str, &n, file), i++)
        map[i] = my_strcpy(str);
    map[i] = NULL;
    fclose(file);
    return (map);
}
