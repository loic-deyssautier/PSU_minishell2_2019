/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

int array_loop(struct_t *struc, int y, int i)
{
    int nb = 0;

    for (; struc->str[struc->i] != ' ' && struc->str[struc->i] != '\0' &&\
    struc->str[struc->i] != ';';)
        ++struc->i;
    struc->arg[i][y] = malloc(sizeof(char) * struc->i);
    if (!struc->arg[i][y]) {
        write(2, "Error, malloc in array_loop\n", 28);
        return (84);
    }
    for (; struc->count < struc->i; ++struc->count) {
        if (struc->str[struc->count] != '\0') {
            struc->arg[y][struc->x] = struc->str[struc->count];
            struc->x++;
        }
    }
    ++struc->i;
    struc->x = 0;
    return (0);
}

int *realloc_int(struct_t *my_struct)
{
    int *array;
    int i = 0;

    array = malloc(sizeof(int) * (my_struct->semicolons + 1));
    for (; i < (my_struct->semicolons - 1); ++i)
        array[i] = my_struct->size[i];
    array[i] = 2;
    return (array);
}

int order_in_array(struct_t *my_struct)
{
    int y = 0;

    my_struct->size = malloc(sizeof(int) * 1);
    my_struct->size[1] = 2;
    for (int j = 0; my_struct->str[j] != '\0'; ++j) {
        if (my_struct->str[j] == ' ')
            ++my_struct->size[my_struct->semicolons];
        if (my_struct->str[j] == ';') {
            ++my_struct->semicolons;
            my_struct->size = realloc_int(my_struct);
        }
    }
    my_struct->arg = malloc(sizeof(char **) * (my_struct->semicolons + 1));
    if (!my_struct->arg) {
            write(2, "Error, malloc 1 in order_in_array\n", 33);
            return (84);
    }
    for (int i = 0; i <= my_struct->semicolons; ++i) {
        my_struct->arg[i] = malloc(sizeof(char *) * my_struct->size[i]);
        if (!my_struct->arg[i]) {
            write(2, "Error, malloc 2 in order_in_array\n", 33);
            return (84);
        }
    }
    for (int i = 0; i <= my_struct->semicolons; ++i) {
        for (; y < (my_struct->size - 1); y++, my_struct->count++)
            array_loop(my_struct, y, i);
        my_struct->arg[i][y] = NULL;
    }
    return (0);
}

int hub_function(struct_t *my_struct, int a)
{
    int error = 0;
    my_struct->x = 0;
    my_struct->semicolons = 0;

    function_output(my_struct);
    my_struct->str[(my_strlen(my_struct->str) - 1)] = '\0';
    if (cd_sort(my_struct, a) == 1)
        return (error);
    my_struct->i = 0;
    my_struct->count = 0;
    error = order_in_array(my_struct);
    return (error);
}

int argument_sorting(struct_t *my_struct, char **env)
{
    my_struct->str = NULL;
    size_t len = 0;
    int error = 0;
    int a = 0;

    write(1, "$> ", 3);
    if (getline(&my_struct->str, &len, stdin) == -1) {
        write(1, "exit\n", 5);
        return (2);
    }
    if (my_struct->str[0] == '\n')
        return (error);
    error = hub_function(my_struct, a);
    return (error);
}