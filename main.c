/*
** EPITECH PROJECT, 2022
** B_malloc
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char *test = malloc(sizeof(char) * 8);
    char *test2 = malloc(sizeof(char) * 9);
    char *test3 = calloc(8, sizeof(char));

    strcpy(test, "tamere\n");
    write(1, test, 7);
    test = realloc(test, sizeof(char) * 20);
    strcpy(test, "taMereSuceDesBites\n");
    write(1, test, 19);
    strcpy(test2, "tamere2\n");
    test2[8] = 0;
    test3[0] = '1';
    write(1, test2, 8);
    write(1, test3, 8);
    free(test2);
    free(test);
}