/*
** EPITECH PROJECT, 2019
** dante.h
** File description:
** Functions of Dante's Star.
*/

#ifndef DANTE_H_
#define DANTE_H_

#include "generator.h"
#include "maze.h"
#include "my.h"
#include "solver.h"

/*---------------------------------------------*/
/*                                             */
/*                 GENERATOR                   */
/*                                             */
/*---------------------------------------------*/

//Init
gen_t *init_gen(int, int);
char **generate_a_maze(int, int);
maze_t *init_node(int, int);
//Lists
void my_push_node(maze_t **, maze_t *);
void my_remove_node(maze_t **);
void my_show_list(maze_t *);
//Main functions
char generate_a_perfect_maze(int, int);
char put_walls(gen_t *, int, int);
//Check
int get_number_in_list(maze_t *);
char check_if_in_the_list(maze_t *, int, int);
char check_outlimit(gen_t *, int, int);
char check_near_by(gen_t *, int, int, int);
char check_if_block(gen_t *, int, int);
//Print
void print_a_maze(char **, int);

/*---------------------------------------------*/
/*                                             */
/*                   SOLVER                    */
/*                                             */
/*---------------------------------------------*/

//Init
char recup_a_maze(solver_t *, char *);
maze_t *init_maze(int, int);
//Lists
void my_push_maze(maze_t **, maze_t *);
void my_remove_maze(maze_t **);
//Main functions
char find_the_exit(solver_t *);
int move_to_next_case(solver_t *);
//Check
int recup_number_in_list(maze_t *);
char check_in_the_list(maze_t *, int, int);
char check_outside(solver_t *, int, int);
char check_next_cases(solver_t *, int, int, int);
char check_if_fail(solver_t *, int, int);
//Print
void print_a_solved_maze(solver_t *);

#endif /* DANTE_H_ */
