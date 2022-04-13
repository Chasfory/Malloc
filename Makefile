##
## EPITECH PROJECT, 2022
## B_malloc
## File description:
## Makefile
##

SRC			=	src/malloc.c
SRC			+=	src/calloc.c
SRC			+=	src/realloc.c
SRC			+=	src/reallocarray.c
SRC			+=	src/free.c
SRC			+=	src/find_next_power_of_two.c
SRC			+=	src/get_number_of_pages_to_fit_the_allocation.c
SRC			+=	src/get_page_size.c
SRC			+=	src/superblock_add_header.c
SRC			+=	src/superblock_create.c
SRC			+=	src/superblock_find_best_fit.c
SRC			+=	src/superblock_get_address_from_header.c
SRC			+=	src/superblock_get_header_from_address.c
SRC			+=	src/superblock_is_big_enough_to_fit_allocation.c
SRC			+=	src/superblock_split.c
SRC			+=	src/singleton.c

SRC_TEST	=	tests/test_unitaires.c

TEST_OBJ	=	$(SRC:.c=.o)

TEST_NAME	=	unit_tests

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy_malloc.so

CFLAGS		+=	-Wall -Wextra -fPIC

CPPFLAGS	+=	-iquote ./include

LDFLAGS		=	-shared

TESTS_LDFLAGS	=	-L -libmy_malloc -lcriterion

CC			=	gcc


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g3
debug: re

units_tests:	all $(TEST_OBJ)
	$(CC) -o $(TEST_NAME) $(TEST_OBJ) $(TESTS_LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

./PHONY: all clean fclean