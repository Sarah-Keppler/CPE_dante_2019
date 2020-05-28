/*
** EPITECH PROJECT, 2019
** init_maze
** File description:
** Init the maze and construct the structure around it.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

void my_push_node(maze_t **list, maze_t *node)
{
    maze_t *tmp = *list;
    maze_t *fst = *list;

    if (NULL == tmp)
        fst = node;
    else {
        fst = node;
        fst->next = tmp;
    }
    *list = fst;
}

void my_remove_node(maze_t **list)
{
    maze_t *tmp = *list;
    maze_t *first = NULL;

    if (NULL == tmp)
        return;
    first = tmp->next;
    free(tmp);
    *list = first;
}

void my_show_list(maze_t *list)
{
    maze_t *tmp = list;

    while (tmp != NULL) {
        my_putstr("y: ");
        my_put_nbr(tmp->y);
        my_putchar(' ');
        my_putstr("x: ");
        my_put_nbr(tmp->x);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

maze_t *init_node(int x, int y)
{
    maze_t *node = malloc(sizeof(maze_t));

    if (NULL == node)
        return (NULL);
    node->x = x;
    node->y = y;
    node->next = NULL;
    return (node);
}
