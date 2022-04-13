/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** get_number_of_pages_to_fit_the_allocation
*/

#include <unistd.h>

#include "struct_malloc.h"

size_t get_number_of_pages_to_fit_the_allocation(size_t real_allocation_size)
{
    size_t nbr_page = 0;
    size_t page = get_page_size();

    while (nbr_page < real_allocation_size) {
        nbr_page += page;
    }
    return nbr_page;
}
