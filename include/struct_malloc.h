/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** struct_malloc
*/

#ifndef STRUCT_MALLOC_H_
    #define STRUCT_MALLOC_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <pthread.h>

    #define MIN_HEADERS_AFTER_SPLIT (4)

typedef struct block_header_s {
    struct block_header_s *next;
    struct block_header_s *previous;
    size_t size;
    bool is_used;
} block_header_t;

size_t find_next_power_of_two(size_t size);
size_t get_number_of_pages_to_fit_the_allocation(size_t real_allocation_size);
size_t get_page_size(void);
block_header_t *superblock_create(size_t real_allocation_size);
block_header_t *superblock_add_header(void *address, size_t superblock_size);
block_header_t *superblock_split(block_header_t *superblock,
                                size_t real_allocation_size);
block_header_t *superblock_find_best_fit(block_header_t *superblock,
                                        size_t real_allocation_size);
block_header_t *superblock_get_header_from_address(void *address);
void *superblock_get_address_from_header(block_header_t *header);
block_header_t *superblock_try_split(block_header_t *min,
                            block_header_t *next, size_t real_allocation_size);
bool superblock_is_big_enough_to_fit_allocation(block_header_t *header,
                                                size_t real_allocation_size);
block_header_t *get_block_headers_head(block_header_t *new_value);
block_header_t *get_block_headers_tail(block_header_t *new_value);
pthread_mutex_t *get_malloc_mutex(void);

#endif /* !STRUCT_MALLOC_H_ */