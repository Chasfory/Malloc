/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** malloc
*/

#include <stdlib.h>

#include "struct_malloc.h"

void *malloc_bis(size_t size)
{
    block_header_t *tmp_block;
    block_header_t *start_block = get_block_headers_head(NULL);

    size = find_next_power_of_two(size);
    tmp_block = superblock_find_best_fit(start_block, size);
    if (tmp_block == NULL) {
        size = find_next_power_of_two(size + sizeof(block_header_t));
        tmp_block = superblock_create(size);
        if (tmp_block == NULL) {
            pthread_mutex_unlock(get_malloc_mutex());
            return NULL;
        }
        tmp_block->is_used = true;
        tmp_block = superblock_try_split(tmp_block, NULL, size);
        pthread_mutex_unlock(get_malloc_mutex());
        return superblock_get_address_from_header(tmp_block);
    }
    pthread_mutex_unlock(get_malloc_mutex());
    return superblock_get_address_from_header(tmp_block);
}

void *malloc(size_t size)
{
    block_header_t *tmp_block;
    block_header_t *start_block = get_block_headers_head(NULL);

    pthread_mutex_lock(get_malloc_mutex());
    if (start_block == NULL) {
        size = find_next_power_of_two(size + sizeof(block_header_t));
        start_block = superblock_create(size);
        if (get_block_headers_head(start_block) == NULL) {
            pthread_mutex_unlock(get_malloc_mutex());
            return NULL;
        }
        start_block->is_used = true;
        tmp_block = superblock_try_split(start_block, NULL, size);
        pthread_mutex_unlock(get_malloc_mutex());
        return superblock_get_address_from_header(tmp_block);
    }
    return malloc_bis(size);
}
