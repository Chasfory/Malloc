/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_add_header
*/

#include "struct_malloc.h"

block_header_t *superblock_add_header(void *address, size_t superblock_size)
{
    block_header_t *tmp = address;

    tmp->is_used = false;
    tmp->size = superblock_size - sizeof(block_header_t);
    tmp->next = NULL;
    tmp->previous = NULL;
    return tmp;
}
