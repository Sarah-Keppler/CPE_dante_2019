/*
** EPITECH PROJECT, 2019
** init_maze
** File description:
** Init the maze and construct the structure around it.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

static char init_list(gen_t *gen)
{
    maze_t *start = init_node(0, 0);
    maze_t *end = init_node(gen->width - 1, gen->height - 1);

    if (NULL == start || NULL == end)
        return ('1');
    my_push_node(&gen->stack, start);
    my_push_node(&gen->viewed, start);
    my_push_node(&gen->viewed, end);
    return ('0');
}

gen_t *init_gen(int x, int y)
{
    gen_t *gen = malloc(sizeof(gen_t));

    if (NULL == gen)
        return (NULL);
    gen->height = y;
    gen->width = x;
    gen->maze = generate_a_maze(x, y);
    gen->stack = NULL;
    gen->wall = NULL;
    gen->viewed = NULL;
    gen->len = x * y;
    if (NULL == gen->maze || '1' == init_list(gen))
        return (NULL);
    return (gen);
}
