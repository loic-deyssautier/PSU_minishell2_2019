/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

void sub_array_loop(struct_t *struc, int y, int nb)
{
    if (struc->str[struc->count] == '/')
        nb++;
    if (struc->str[struc->count] != '\0') {
        struc->arg[y][struc->x] = struc->str[struc->count];
        struc->x++;
    }
}

int array_loop(struct_t *struc, int y)
{
    int nb = 0;

    for (; struc->str[struc->i] != ' ' && struc->str[struc->i] != '\0';)
        struc->i++;
    struc->arg[y] = malloc(sizeof(char) * struc->i);
    if (!struc->arg[y]) {
        my_printf("Error, malloc2\n");
        return (84);
    }
    for (; struc->count < struc->i; struc->count++)
        sub_array_loop(struc, y, nb);
    struc->i++;
    struc->x = 0;
    return (0);
}

int order_in_array(struct_t *my_struct)
{
    my_struct->size = 2;
    my_struct->x = 0;
    int y = 0;
    my_struct->i = 0;
    my_struct->count = 0;
    int nbr = 0;

    for (int j = 0; my_struct->str[j] != '\0'; j++) {
        if (my_struct->str[j] == ' ')
            my_struct->size++;
        else if (my_struct->str[j] == '/')
            nbr++;
    }
    my_struct->arg = malloc(sizeof(char *) * my_struct->size);
    if (!my_struct->arg) {
        my_printf("Error, malloc1\n");
        return (84);
    }
    for (; y < (my_struct->size - 1); y++, my_struct->count++)
        array_loop(my_struct, y);
    my_struct->arg[y] = NULL;
    return (0);
}

int hub_function(struct_t *my_struct, int a)
{
    int error = 0;

    function_output(my_struct);
    my_struct->str[(my_strlen(my_struct->str) - 1)] = '\0';
    error = cd_sort(my_struct, a);
    if (error == 1)
        return (error);
    error = order_in_array(my_struct);
    return (error);
}

int argument_sorting(struct_t *my_struct, char **env)
{
    my_struct->str = NULL;
    size_t len = 0;
    int read = 0;
    int error = 0;
    int a = 0;

    my_printf("$> ");
    read = getline(&my_struct->str, &len, stdin);
    if (read == -1) {
        my_printf("exit\n");
        return (2);
    }
    if (my_struct->str[0] == '\n')
        return (error);
    error = hub_function(my_struct, a);
    return (error);
}