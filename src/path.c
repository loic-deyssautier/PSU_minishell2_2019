/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** function
*/

#include "include/my.h"

int command_execution(struct_t *my_struct, char **env)
{
    my_struct->h = (2 + my_strlen(my_struct->str));
    my_struct->pid = getpid();
    my_struct->child_pid = fork();
    wait(NULL);
    if (my_struct->child_pid != 0)
        my_struct->error = -1;
    if (my_struct->child_pid == 0) {
        execve(my_struct->way, my_struct->arg, env);
        exit(1);
    }
    return (0);
}

int path_sort(struct_t *my_struct, char **env, int a)
{
    int z = 5;
    int c = 5;
    int e = 0;

    for (; env[a][z] != '\0' && my_struct->error == -1; z++, c++) {
        for (; env[a][z] != ':' && env[a][z] != '\0'; z++, my_struct->h++);
        my_struct->way = malloc(sizeof(char) * my_struct->h);
        if (!my_struct->way)
            my_printf("Error, malloc");
        for (; env[a][c] != ':' && env[a][z] != '\0'; e++, c++)
            my_struct->way[e] = env[a][c];
        my_struct->way[e] = '/';
        e++;
        for (int i = 0; i < my_strlen(my_struct->str); i++, e++)
            my_struct->way[e] = my_struct->str[i];
        my_struct->way[e] = '\0';
        if (access(my_struct->way, X_OK) == 0 && my_struct->error == -1) {
            command_execution(my_struct, env);
            my_struct->error = 0;
        }
        e = 0;
    }
    if (my_struct->error == -1)
        perror(my_struct->arg[0]);
    return (0);
}

int path_detection(struct_t *my_struct, char **env)
{
    my_struct->way = NULL;
    int a = 0;
    int b = 0;
    int c = 0;
    char path_string[] = "PATH";
    my_struct->h = (5 + my_strlen(my_struct->str));

    for (; env[a] != NULL; a++) {
        for (; env[a][b] == path_string[b]; b++, c++) {
            if (c == 4) {
                path_sort(my_struct, env, a);
                return (0);
            }
        }
    b = 0;
    }
    return (0);
}
