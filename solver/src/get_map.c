/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-dante-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/solver.h"

int get_map_len(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat file;
    char *str = NULL;
    int len = 1;

    if (fd == -1)
        exit(my_putstr_error("Error : wrong filepath.\n"));
    stat(path, &file);
    str = malloc(sizeof(char) * file.st_size);
    read(fd, str, file.st_size);
    for (int a = 0; a < file.st_size; a++)
        if (str[a] == '\n')
            len++;
    for (int i = 0; i < file.st_size; i++)
        if (str[i] != '*' && str[i] != '\n' && str[i] != 'X')
            exit(my_putstr_error("Error : the map is invalid.\n"));
    return (len);
}

char **get_map_from_file(char *path)
{
    char **map = malloc(sizeof(char *) * (get_map_len(path) + 1));
    char *line = NULL;
    size_t size = 0;
    FILE *fp = fopen(path, "r");
    int i = 0;

    while (getline(&line, &size, fp) != -1) {
        map[i] = my_strcpy(line);
        i++;
    }
    map[get_map_len(path)] = NULL;
    for (int i = 1; map[i + 1] != NULL; i++) {
            if (my_strlen(map[i]) != my_strlen(map[i - 1])) {
                my_putstr_error("Error : wrong map.\n");
                exit(84);
            }
        }
    return (map);
}
