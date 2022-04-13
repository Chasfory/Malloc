/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** realloc
*/

#include <stdlib.h>
#include <string.h>

#include "struct_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *dest;
    block_header_t *current;

    if (ptr == NULL)
        return malloc(size);
    current = superblock_get_header_from_address(ptr);
    if (current->size >= size) {
        return ptr;
    }
    dest = malloc(size);
    if (dest == NULL) {
        return NULL;
    }
    memcpy(dest, ptr, current->size);
    free(ptr);
    return dest;
}
