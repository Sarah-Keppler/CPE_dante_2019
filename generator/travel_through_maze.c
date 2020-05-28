/*
** EPITECH PROJECT, 2019
** Travel through maze.
** File description:
** Function to travel the maze.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

char check_outlimit(gen_t *gen, int x, int y)
{
    if (0 > x || 0 > y)
        return ('1');
    if (x >= gen->width || y >= gen->height)
        return ('1');
    return ('0');
}

char check_near_by(gen_t *gen, int move, int x, int y)
{
    int pos[4][2] = {{x, y + 1}, {x + 1, y}, {x, y - 1}, {x - 1, y}};

    if ('1' == check_outlimit(gen, pos[move][0], pos[move][1]))
        return ('1');
    if ('0' == check_if_in_the_list(gen->wall, pos[move][0], pos[move][1]) ||
        '0' == check_if_in_the_list(gen->stack, pos[move][0], pos[move][1]))
        return ('1');
    return ('0');
}

char check_if_block(gen_t *gen, int x, int y)
{
    int pos[4][2] = {{x, y + 1}, {x + 1, y}, {x, y - 1}, {x - 1, y}};
    int nb_block = 0;

    for (int i = 0; 4 > i; ++i)
        if ('1' == check_outlimit(gen, pos[i][0], pos[i][1]) ||
            '0' == check_if_in_the_list(gen->viewed, pos[i][0], pos[i][1]))
            ++nb_block;
    if (4 == nb_block)
        return ('0');
    return ('1');
}
