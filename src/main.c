/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main function
*/

#include "include/my.h"

int with_path(char **env, struct_t *my_struct)
{
    my_struct->pid = getpid();
    my_struct->child_pid = fork();
    wait(NULL);
    if (my_struct->child_pid == 0) {
        for (int i = 0; my_struct->str[i] != '\0'; i++) {
            if (my_struct->str[i] == ' ')
                my_struct->str[i] = '\0';
        }
        execve(my_struct->str, my_struct->arg, env);
        free(my_struct->str);
        for (int i = (my_struct->size - 1); i >= 0; i--)
            free(my_struct->arg[i]);
        free(my_struct->arg);
        exit(1);
    }
    return (0);
}

int body(char **env)
{
    struct_t my_struct;
    int error = 0;
    my_struct.error = -1;

    for (; 1; error = 0, my_struct.error = -1) {
        error = argument_sorting(&my_struct, env);
        if (error == 84)
            return (84);
        if (error == 2)
            return (0);
        if (error != 1) {
            if (my_strlen(my_struct.str) != 1 && my_struct.str[0] != '/')
                path_detection(&my_struct, env);
            else if (my_struct.str[0] == '/')
                with_path(env, &my_struct);
        }
    }
    return (0);
}

int main(int argc, char **argv, char **env)
{
    int result = 0;

    if (argc == 1)
        result = body(env);
    return (result);
}