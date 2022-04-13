/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_create
*/

#include <unistd.h>

#include "struct_malloc.h"

block_header_t *superblock_create(size_t real_allocation_size)
{
    size_t size = get_number_of_pages_to_fit_the_allocation
                                        (real_allocation_size);
    void *address_tmp = sbrk(size);
    block_header_t *current;
    block_header_t *last_block = get_block_headers_tail(NULL);

    if (address_tmp == (void *)-1) {
        return NULL;
    }
    current = superblock_add_header(address_tmp, size);
    current->previous = last_block;
    if (last_block != NULL)
        last_block->next = current;
    last_block = current;
    return current;
}
