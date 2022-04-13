/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** find_next_power_of_two
*/

#include "struct_malloc.h"

size_t find_next_power_of_two(size_t size)
{
    size_t tmp = 32;

    while (tmp < size) {
        tmp *= 2;
    }
    return tmp;
}
