/*
** EPITECH PROJECT, 2019
** Generator
** File description:
** Generate a maze.
*/

#include "dante.h"

static char check_arguments(int ac, char **av)
{
    if (3 > ac) {
        my_puterror("Error :: Generator need at least 2 arguments\n");
        return ('1');
    }
    for (int i = 1; ac > i; ++i)
        if (0 == my_str_isnum(av[i])) {
            my_puterror("Error :: Options as to be positive integers\n");
            return ('1');
        }
    if (0 == my_getnbr(av[1]) || 0 == my_getnbr(av[2])) {
        my_puterror("Error :: Options as to be greater than 0\n");
        return ('1');
    }
    return ('0');
}

int main(int ac, char **av)
{
    if ('1' == check_arguments(ac, av))
        return (84);
    if ('1' == generate_a_perfect_maze(my_getnbr(av[1]), my_getnbr(av[2])))
        return (84);
    return (0);
}
