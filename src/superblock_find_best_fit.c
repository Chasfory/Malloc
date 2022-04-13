/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** superblock_find_best_fit
*/

#include "struct_malloc.h"

block_header_t *superblock_find_best_fit(block_header_t *superblock,
                                        size_t real_allocation_size)
{
    block_header_t *tmp = superblock;
    block_header_t *min = NULL;
    block_header_t *next = NULL;

    while (tmp != NULL) {
        if (tmp->is_used) {
            tmp = tmp->next;
            continue;
        }
        if (superblock_is_big_enough_to_fit_allocation(tmp,
                real_allocation_size) == true && (min == NULL ||
                                        min->size > tmp->size)) {
            next = tmp->next;
            min = tmp;
        }
        tmp = tmp->next;
    }
    return superblock_try_split(min, next, real_allocation_size);
}
