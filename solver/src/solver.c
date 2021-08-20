/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-dante-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/solver.h"

void print_solved_maze(maze_t *m)
{
    char *str = malloc(sizeof(char) * (m->width + 1) * (m->height + 1));
    int k = 0;

    for (int i = 0; i < m->height; ++i) {
        for (int j = 0; j < m->width - 1; ++j) {
            if (m->map[i][j] == m->max_dist || m->map[i][j] == 1)
                str[k] = 'o';
            else if (m->map[i][j] == m->w_val)
                str[k] = 'X';
            else
                str[k] = '*';
            k++;
        }
        if (i != m->height - 1) {
            str[k] = '\n';
            k++;
        }
    }
    str[m->height * m->width - 1] = '\0';
    printf("%s", str);
}

void check_cell2(maze_t *maze, int i, int j)
{
    if (j != 0) {
        if (maze->map[i][j - 1] > 0) {
            maze->map[i][j] = maze->max_dist;
            maze->max_dist++;
        }
    }
    if (j != maze->width - 2) {
        if (maze->map[i][j + 1] > 0) {
            maze->map[i][j] = maze->max_dist;
            maze->max_dist++;
        }
    }
}

void check_cell1(maze_t *maze, int i, int j)
{
    if (maze->map[i][j] != 0)
        return;
    if (i != 0) {
        if (maze->map[i - 1][j] > 0) {
            maze->map[i][j] = maze->max_dist;
            maze->max_dist++;
        }
    }
    if (i != maze->height - 1) {
        if (maze->map[i + 1][j] > 0) {
            maze->map[i][j] = maze->max_dist;
            maze->max_dist++;
        }
    }
    check_cell2(maze, i, j);
}

void calc_distance(maze_t *maze)
{
    while (maze->map[1][0] == 0 || maze->map[0][1] == 0) {
        for (int i = maze->height - 1; i >= 0; i--) {
            for (int j = maze->width - 2; j >= 0; j--) {
                check_cell1(maze, i, j);
            }
        }
    }
    maze->max_dist += 10;
    maze->w_val = maze->max_dist + 20;
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width - 1; j++) {
            if (maze->map[i][j] == -1)
                maze->map[i][j] = maze->w_val;
            if (maze->map[i][j] == 0)
                maze->map[i][j] = maze->max_dist + 1;
        }
    }
}

int **get_num_map(char **map, int height, int width)
{
    int **maze = malloc(sizeof(int *) * height);

    for (int i = 0; i < height; ++i) {
        maze[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; ++j) {
            if (map[i][j] == 'X')
                maze[i][j] = -1;
            else
                maze[i][j] = 0;
        }
    }
    maze[height - 1][width - 2] = 1;
    return maze;
}
