/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-dante-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/solver.h"

int *get_cord(maze_t *maze, int i, int j)
{
    int *cord = malloc(sizeof(int) * 4);

    cord[0] = (i == 0) ? maze->w_val : maze->map[i - 1][j];
    cord[1] = (j == maze->width - 1) ? maze->w_val : maze->map[i][j + 1];
    cord[2] = (i == maze->height - 1) ? maze->w_val : maze->map[i + 1][j];
    cord[3] = (j == 0) ? maze->w_val : maze->map[i][j - 1];
    return cord;
}

int move_buffer_x(maze_t *maze, int *c)
{
    if (c[3] <= c[2] && c[3] <= c[1] && c[3] <= c[0]) {
        maze->x--;
        return 0;
    } else if (c[1] <= c[2] && c[1] <= c[0] && c[1] <= c[3]) {
        maze->x++;
        return 0;
    } else
        return 1;
}

int move_buffer_y(maze_t *maze, int *c)
{
    if (c[2] <= c[1] && c[2] <= c[0] && c[2] <= c[3]) {
        maze->y++;
        return 0;
    } else if (c[0] <= c[2] && c[0] <= c[1] && c[0] <= c[3]) {
        maze->y--;
        return 0;
    } else
        return 1;
}

void update_buffer(int *c, maze_t *maze)
{
    if (move_buffer_x(maze, c) == 1)
        if (move_buffer_y(maze, c) == 1)
            maze->map[maze->y][maze->x] = maze->max_dist + 2;
}

void solve_maze(maze_t *maze)
{
    int *c = NULL;

    maze->y = 0;
    maze->x = 0;
    while (maze->map[maze->y][maze->x] != 1) {
        if (maze->map[maze->y][maze->x] >= 0) {
            maze->map[maze->y][maze->x] = maze->max_dist;
            c = get_cord(maze, maze->y, maze->x);
            update_buffer(c, maze);
        }
    }
    print_solved_maze(maze);
}