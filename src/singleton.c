/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-malloc-laetitia.bousch
** File description:
** singleton
*/

#include <unistd.h>

#include "struct_malloc.h"

pthread_mutex_t *get_malloc_mutex(void)
{
    static pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

    return &g_mutex;
}

block_header_t *get_block_headers_head(block_header_t *new_value)
{
    static block_header_t *value = NULL;

    if (new_value != NULL) {
        value = new_value;
    }
    return value;
}

block_header_t *get_block_headers_tail(block_header_t *new_value)
{
    static block_header_t *value = NULL;

    if (new_value != NULL) {
        value = new_value;
    }
    return value;
}