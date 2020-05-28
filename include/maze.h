/*
** EPITECH PROJECT, 2019
** maze.h
** File description:
** Struct of Dante's Star maze.
*/

#ifndef MAZE_H_
#define MAZE_H_

typedef struct maze {
    int x;
    int y;
    struct maze *next;
} maze_t;

#endif /* MAZE_H_ */
