/*
** EPITECH PROJECT, 2019
** walls
** File description:
** Get and set walls.
*/

#include <stdlib.h>
#include "dante.h"

static char check_ancient_path(gen_t *gen, int x, int y)
{
    if (x == gen->stack->next->x && y == gen->stack->next->y)
        return ('0');
    return ('1');
}

static char check_if_viewed_around(gen_t *gen, int x, int y)
{
    int pos[4][2] = {{x, y + 1}, {x + 1, y}, {x, y - 1}, {x - 1, y}};
    int nb_viewed = 0;

    if ('0' == check_ancient_path(gen, x, y))
        return ('1');
    for (int i = 0; 4 > i; ++i) {
        if ('0' == check_outlimit(gen, pos[i][0], pos[i][1]) &&
            '0' == check_if_in_the_list(gen->stack, pos[i][0], pos[i][1]))
            ++nb_viewed;
    }
    if (2 <= nb_viewed)
        return ('0');
    return ('1');
}

static char add_walls(gen_t *gen, int x, int y)
{
    maze_t *wall = init_node(x, y);
    maze_t *v_wall = init_node(x, y);

    if (NULL == wall || NULL == v_wall)
        return ('1');
    my_push_node(&gen->wall, wall);
    my_push_node(&gen->viewed, v_wall);
    return ('0');
}

char put_walls(gen_t *gen, int x, int y)
{
    int pos[4][2] = {{x, y + 1}, {x + 1, y}, {x, y - 1}, {x - 1, y}};
    char rtn = '0';

    for (int i = 0; 4 > i; ++i)
        if ('0' == check_outlimit(gen, pos[i][0], pos[i][1]) &&
            '0' == check_if_viewed_around(gen, pos[i][0], pos[i][1]))
            rtn = add_walls(gen, pos[i][0], pos[i][1]);
    if ('1' == rtn)
        return ('1');
    return ('0');
}
