/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** free
*/

#include <stdlib.h>
#include <unistd.h>

#include "struct_malloc.h"

block_header_t *superblock_get_previous_header(block_header_t *block)
{
    return block->previous;
}

block_header_t *concat_superblock(block_header_t *tmp)
{
    block_header_t *tmp_previous;

    tmp->is_used = false;
    tmp_previous = superblock_get_previous_header(tmp);
    if (tmp_previous == NULL) {
        return tmp;
    }
    tmp_previous->size += tmp->size + sizeof(block_header_t);
    tmp_previous->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->previous = tmp_previous;
    }
    return tmp_previous;
}

block_header_t *free_block(block_header_t *block)
{
    block_header_t *tmp = block;

    tmp = concat_superblock(tmp);
    return tmp;
}

void free(void *ptr)
{
    block_header_t *tmp;

    if (ptr == NULL) {
        return;
    }
    tmp = superblock_get_header_from_address(ptr);
    tmp->is_used = false;
    free_block(tmp);
    return;
}
