/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-dante-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/generator.h"

void error_handling(char **av)
{
    if (my_str_isnum(av[1]) == -1 || my_str_isnum(av[2]) == -1) {
        my_putstr_error("Invalid character.\n");
        exit(84);
    }
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0) {
        my_putstr_error("Invalid map size.\n");
        exit(84);
    }
}

void print_map(char **map, int width, int height)
{
    char *str = malloc(sizeof(char) * width * height + height);
    int k = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            str[k] = map[i][j];
            k++;
        }
        if (i != height) {
            str[k] = '\n';
            k++;
        }
    }
    str[width * height + height - 1] = '\0';
    printf("%s", str);
}

void imperfect_maze(char **maze, int width, int height)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i][j] == 'X' && rand() % 5 == 0) {
                maze[i][j] = '*';
            }
        }
    }
}
