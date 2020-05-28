/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** Functions of Dante's Star Generator.
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "maze.h"

typedef struct generator {
    int height;
    int width;
    char **maze;
    maze_t *stack;
    maze_t *wall;
    maze_t *viewed;
    int len;
} gen_t;

#endif /* GENERATOR_H_ */
