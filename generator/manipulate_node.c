/*
** EPITECH PROJECT, 2019
** manipulate_node
** File description:
** Get and set nodes.
*/

#include <stddef.h>
#include "dante.h"

int get_number_in_list(maze_t *list)
{
    int number = 0;
    maze_t *tmp = list;

    while (NULL != tmp) {
        ++number;
        tmp = tmp->next;
    }
    return (number);
}

char check_if_in_the_list(maze_t *list, int x, int y)
{
    maze_t *tmp = list;

    while (NULL != tmp) {
        if (x == tmp->x && y == tmp->y)
            return ('0');
        tmp = tmp->next;
    }
    return ('1');
}
