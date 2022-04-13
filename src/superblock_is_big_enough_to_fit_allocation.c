/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_is_big_enough_to_fit_allocation
*/

#include "struct_malloc.h"

bool superblock_is_big_enough_to_fit_allocation(block_header_t *header,
                                            size_t real_allocation_size)
{
    return header->size >= real_allocation_size;
}
