/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** B-CPE-200-LIL-2-1-dante-antoine.podvin
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void create_maze(int width, int height, int id);
void imperfect_maze(char **maze, int width, int height);
void print_map(char **map, int width, int height);
void error_handling(char **av);
