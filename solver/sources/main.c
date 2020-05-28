/*
** EPITECH PROJECT, 2019
** Solver
** File description:
** Solver a maze.
*/

#include <stddef.h>
#include <stdlib.h>
#include "dante.h"

int main(int ac, char **av)
{
    if (2 != ac) {
        my_puterror("Error :: Solver need at least one argument\n");
        return (84);
    }
    return (0);
    my_putstr(av[0]);
}
