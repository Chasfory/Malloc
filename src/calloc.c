/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** calloc
*/

#include <stdlib.h>
#include <string.h>

#include "struct_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *block;
    size_t tmp = size * nmemb;

    if (size == 0 || nmemb == 0) {
        return NULL;
    }
    block = malloc(tmp);
    if (block == NULL) {
        return NULL;
    }
    memset(block, 0, tmp);
    return block;
}
