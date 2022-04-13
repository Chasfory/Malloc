/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_get_address_from_header
*/

#include "struct_malloc.h"

void *superblock_get_address_from_header(block_header_t *header)
{
    void *address = ((void *)header) + sizeof(block_header_t);

    return address;
}
