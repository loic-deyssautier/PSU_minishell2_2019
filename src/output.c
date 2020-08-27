/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

void output_exit(struct_t *struct_s)
{
    char release[5] = "exit";
    int count = 0;

    for (int i = 0; i <= 4; ++i) {
        if (struct_s->str[i] == release[i])
            ++count;
    }
    if (count >= 4) {
        free(struct_s->str);
        write(1, "exit\n", 5);
        exit(0);
    }
}

void function_output(struct_t *struct_s)
{
    output_exit(struct_s);
}