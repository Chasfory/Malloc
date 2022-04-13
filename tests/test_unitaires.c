/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** test_unitaires
*/

#include <criterion/criterion.h>
#include <unistd.h>

#include "struct_malloc.h"

Test(find_next_power_of_two, simple) {
    size_t tmp = 0;

    tmp = find_next_power_of_two(5);
    cr_expect_str_eq(tmp, 6);
}

Test(superblock_split, second) {
    block_header_t *tmp;

    tmp->size = 10;
    tmp->is_used = false;
    tmp->next = NULL;
    tmp = superblock_split(tmp, 5);
    cr_expect_str_eq(tmp->size, 5);
    cr_expect_str_eq(tmp->next->next, NULL);
}

Test(get_number_of_pages_to_fit_the_allocation, three) {
    size_t tmp = 0;

    tmp = get_number_of_pages_to_fit_the_allocation(8000);
    cr_expect_str_eq(tmp, 2);
}

Test(get_page_size, four) {
    size_t tmp = 0;

    tmp = get_page_size();
    cr_expect_str_eq(tmp, 8192);
}

Test(superblock_add_header, five) {
    block_header_t *tmp;

    tmp = superblock_add_header(malloc(5), 5);
    cr_expect_str_eq(tmp->size, 5);
}

Test(superblock_create, six) {
    block_header_t *tmp;

    tmp = superblock_create(5);
    cr_expect_str_eq(tmp->size, 5);
}

Test(superblock_is_big_enough_to_fit_allocation, seven) {
    block_header_t *tmp;
    bool str;

    tmp->size = 10;
    str = superblock_is_big_enough_to_fit_allocation(5);
    cr_expect_str_eq(str, false);
}

/*Test(superblock_get_address_from_header, nine) {
    block_header_t *tmp;
    void *address;

    tmp->is_used = true;
    tmp->next = NULL;
    tmp->size = 5;
    address = superblock_get_address_from_header(tmp);
    cr_expect_str_eq(address, regarder comment voir);
}*/