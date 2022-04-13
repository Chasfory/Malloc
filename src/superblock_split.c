/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_split
*/

#include "struct_malloc.h"

block_header_t *superblock_try_split(block_header_t *min,
                            block_header_t *next, size_t real_allocation_size)
{
    if (min == NULL) {
        return NULL;
    }
    min->next = next;
    if (min->size > (sizeof(block_header_t) * MIN_HEADERS_AFTER_SPLIT
                    + real_allocation_size)) {
        superblock_split(min, real_allocation_size);
    } else {
        min->is_used = true;
    }
    return min;
}

block_header_t *superblock_split(block_header_t *superblock,
                                size_t real_allocation_size)
{
    block_header_t *tmp = ((void *)superblock) + sizeof(block_header_t)
        + real_allocation_size;

    superblock->is_used = true;
    tmp->is_used = false;
    tmp->size = superblock->size - real_allocation_size -
                sizeof(block_header_t);
    tmp->next = superblock->next;
    tmp->previous = superblock;
    if (tmp->next != NULL)
        tmp->next->previous = tmp;
    else
        get_block_headers_tail(tmp);
    superblock->size = real_allocation_size;
    superblock->next = tmp;
    return superblock;
}
