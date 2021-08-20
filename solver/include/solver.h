/*
** EPITECH PROJECT, 2021
** solver.h
** File description:
** B-CPE-200-LIL-2-1-dante-antoine.podvin
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct maze_s {
    int height;
    int width;
    int **map;
    char **solved_maze;
    int w_val;
    int max_dist;
    int x;
    int y;
} maze_t;

char **get_map_from_file(char *path);
void parse_maze(maze_t *maze);
void print_debug_maze(int **maze, int height, int width);
void solve_maze(maze_t *maze);
int **get_num_map(char **map, int height, int width);
void calc_distance(maze_t *maze);
void print_solved_maze(maze_t *maze);