/*
** EPITECH PROJECT, 2019
** Generator
** File description:
** Generate a maze.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

void print_a_maze(char **maze, int lines)
{
    for (int i = 0; lines > i; ++i) {
        my_putstr(maze[i]);
        my_putchar('\n');
    }
}

static char **create_empty_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * y);

    if (NULL == maze)
        return (NULL);
    for (int i = 0; y > i; ++i) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        if (NULL == maze[i])
            return (NULL);
        maze[i][x] = '\0';
        for (int n = 0; x > n; ++n)
            maze[i][n] = 'X';
    }
    maze[0][0] = '*';
    maze[y - 1][x - 1] = '*';
    return (maze);
}

char **generate_a_maze(int x, int y)
{
    char **maze = create_empty_maze(x, y);

    if (NULL == maze)
        return (NULL);
    return (maze);
}
