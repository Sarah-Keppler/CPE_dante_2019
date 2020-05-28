/*
** EPITECH PROJECT, 2019
** Perfect maze.
** File description:
** Generate a perfect maze.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

static void follow_ancient_path_if_block(gen_t *gen)
{
    while ('0' == check_if_block(gen, gen->stack->x, gen->stack->y) &&
        1 != get_number_in_list(gen->stack))
        my_remove_node(&gen->stack);
}

static char add_in_lists(gen_t *gen, int move)
{
    int pos[4][2] = {{gen->stack->x, gen->stack->y + 1},
        {gen->stack->x + 1, gen->stack->y},
        {gen->stack->x, gen->stack->y - 1},
        {gen->stack->x - 1, gen->stack->y}};
    maze_t *node = init_node(pos[move][0], pos[move][1]);
    maze_t *v_node = init_node(pos[move][0], pos[move][1]);

    if (NULL == node || NULL == v_node)
        return ('1');
    my_push_node(&gen->stack, node);
    my_push_node(&gen->viewed, v_node);
    return ('0');
}

static int move_around(gen_t *gen)
{
    int move = 0;

    if ('1' == my_rand(&move, 0, 4))
        return (84);
    while ('1' == check_near_by(gen, move, gen->stack->x, gen->stack->y)) {
        if ('1' == my_rand(&move, 0, 4))
            return (84);
    }
    return (move);
}

static char pass_through_the_maze(gen_t *gen)
{
    int move = move_around(gen);
    int pos[4][2] = {{gen->stack->x, gen->stack->y + 1},
        {gen->stack->x + 1, gen->stack->y},
        {gen->stack->x, gen->stack->y - 1},
        {gen->stack->x - 1, gen->stack->y}};

    if (84 == move)
        return ('1');
    gen->maze[pos[move][1]][pos[move][0]] = '*';
    if ('1' == add_in_lists(gen, move))
        return ('1');
    if ('1' == put_walls(gen, gen->stack->x, gen->stack->y))
        return ('1');
    follow_ancient_path_if_block(gen);
    return ('0');
}

char generate_a_perfect_maze(int x, int y)
{
    gen_t *gen = init_gen(x, y);
    int rtn = 0;

    if (NULL == gen)
        return ('1');
    while (1 != rtn) {
        if ('1' == pass_through_the_maze(gen))
            return ('1');
        rtn = get_number_in_list(gen->stack);
    }
    print_a_maze(gen->maze, gen->height);
    return ('0');
}
