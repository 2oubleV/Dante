/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** B-CPE-200-LIL-2-1-dante-antoine.podvin
*/

#include "../include/generator.h"

void argument_error(void)
{
    my_putstr_error("Error : wrong arguments.\n");
    exit(84);
}

void binary_path(char **map, int i, int j)
{
    if (map[i][j] == '*') {
        if (rand() % 2 == 0)
            map[i - 1][j] = '*';
        else
            map[i][j - 1] = '*';
    }
}

void build_perfect_maze(char **map, int width, int height)
{
    srand(time(NULL));
    for (int i = 2; i < height; ++i) {
        for (int j = 2; j < width; ++j) {
            binary_path(map, i, j);
        }
    }
}

void create_maze(int width, int height, int id)
{
    char **maze = malloc(sizeof(char *) * (height + 1));

    for (int i = 0; i < height; ++i) {
        maze[i] = malloc(sizeof(char) * width + 1);
        for (int j = 0; j < width; ++j) {
            if (j == 0 || i == 0)
                maze[i][j] = '*';
            else if (i % 2 == 0 && j % 2 == 0)
                maze[i][j] = '*';
            else
                maze[i][j] = 'X';
        }
        maze[i][width] = '\0';
    }
    maze[height - 1][width - 1] = '*';
    maze[height] = NULL;
    build_perfect_maze(maze, width, height);
    if (id == 1)
        imperfect_maze(maze, width, height);
    print_map(maze, width, height);
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        error_handling(argv);
        create_maze(my_getnbr(argv[1]), my_getnbr(argv[2]), 1);
    } else if (argc == 4 && my_strcmp(argv[3], "perfect") == 1) {
        error_handling(argv);
        create_maze(my_getnbr(argv[1]), my_getnbr(argv[2]), 0);
    } else
        argument_error();
    return (0);
}
