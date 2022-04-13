/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** get_page_size
*/

#include <unistd.h>

#include "struct_malloc.h"

size_t get_page_size(void)
{
    return 2 * getpagesize();
}
