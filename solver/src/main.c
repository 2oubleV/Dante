/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** B-CPE-200-LIL-2-1-dante-antoine.podvin
*/

#include "../include/solver.h"

void my_put_int_tab(char **map, int width, int height)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (map[i][j] == 'X') {
                my_printf("no path\n");
                exit(84);
            }
            my_putchar('o');
        }
        if (i != height - 1)
            my_putchar('\n');
    }
}

void handle_map_size(char **map, int width, int height)
{
    if (width == 1) {
        my_put_int_tab(map, width, height);
        exit(EXIT_SUCCESS);
    }
}

void print_debug_maze(int **maze, int height, int width)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width - 1; ++j) {
            if (maze[i][j + 1] >= 0 && maze[i][j + 1] < 10)
                my_putchar(' ');
            my_put_nbr(maze[i][j]);
            my_putstr(" |");
        }
        my_putchar('\n');
    }
}

void solver(char *fp)
{
    maze_t *maze = malloc(sizeof(maze_t));

    maze->solved_maze = get_map_from_file(fp);
    maze->height = my_tablen(maze->solved_maze);
    maze->width = my_strlen(maze->solved_maze[0]);
    maze->max_dist = 2;
    if (my_strlen(maze->solved_maze[0]) == 2) {
        for (int i = 0; i < maze->height; ++i) {
            my_putchar('o');
            if (i != maze->height - 1)
                my_putchar('\n');
        }
        exit(EXIT_SUCCESS);
    }
    handle_map_size(maze->solved_maze, maze->width, maze->height);
    maze->map = get_num_map(maze->solved_maze, maze->height, maze->width);
    calc_distance(maze);
    solve_maze(maze);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        solver(av[1]);
        return (0);
    }
    return 84;
}
