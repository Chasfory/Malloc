/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** realloc_array
*/

#include <stdlib.h>

#include "struct_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) {
        return NULL;
    }
    return realloc(ptr, nmemb * size);
}
