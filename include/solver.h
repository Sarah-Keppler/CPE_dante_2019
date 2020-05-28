/*
** EPITECH PROJECT, 2019
** solver.h
** File description:
** Functions of Dante's Star Solver.
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "maze.h"

typedef struct solver {
    int height;
    int width;
    char **maze;
    maze_t *stack;
    maze_t *wall;
    maze_t *viewed;
} solver_t;

#endif /* SOLVER_H_ */
