/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

int output_sort(struct_t *my_struct)
{
    if (my_struct->str[0] != 'e')
        return (1);
    if (my_struct->str[1] != 'x')
        return (1);
    if (my_struct->str[2] != 'i')
        return (1);
    if (my_struct->str[3] != 't')
        return (1);
    if (my_struct->str[4] == '\n') {
        my_printf("exit\n");
        exit (0);
    }
    return (0);
}

int function_output(struct_t *my_struct)
{
    int nbr = 0;
    int i = 5;
    int j = 5;
    int error = 0;
    char release[6] = "exit";
    char *number_output = NULL;

    error = output_sort(my_struct);
    if (error == 1)
        return (0);
    for (; my_struct->str[i] >= 48 && my_struct->str[i] <= 57; i++, nbr++);
    number_output = malloc(sizeof(char) * nbr);
    for (int a = 0; a < nbr; a++, j++)
        number_output[a] = my_struct->str[j];
    my_printf("%s\n", release);
    free(my_struct->str);
    exit(my_getnbr(number_output));
}