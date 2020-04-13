/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

void cd_function(struct_t *my_struct, int a, char *cd_memory, int nb)
{
    int i = 3;

    for (; my_struct->str[a] != '\n' && my_struct->str[a] != '\0'; a++);
    a++;
    cd_memory = malloc(sizeof(char) * a);
    if (!cd_memory)
        write(2, "Error, malloc\n", 15);
    for (; my_struct->str[i] != '\n' && my_struct->str[i] != '\0'; i++, nb++)
        cd_memory[nb] = my_struct->str[i];
    cd_memory[nb] = '\0';
    if (chdir(cd_memory) != 0)
        perror(cd_memory);
    free(cd_memory);
}

int cd_sort(struct_t *my_struct, int a)
{
    int nb = 0;
    char *cd_memory = NULL;

    if (my_struct->str[0] != 'c' || my_struct->str[1] != 'd')
        return (0);
    if (my_strlen(my_struct->str) == 2)
        return (1);
    if (my_struct->str[3] == ' ')
        return (1);
    if (my_struct->str[3] == '.' && my_struct->str[4] == '.') {
        chdir("..");
        return (1);
    }
    cd_function(my_struct, a, cd_memory, nb);
    return (1);
}