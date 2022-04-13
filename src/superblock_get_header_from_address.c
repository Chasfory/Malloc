/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_get_header_from_address
*/

#include "struct_malloc.h"

block_header_t *superblock_get_header_from_address(void *address)
{
    block_header_t *tmp = address - sizeof(block_header_t);

    return tmp;
}
