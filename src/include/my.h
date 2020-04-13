/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** libmy
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct
{
    char **arg;
    char *str;
    char *way;
    int nb_arg;
    int pid;
    int child_pid;
    int count;
    int x;
    int y;
    int i;
    int nb;
    int size;
    int error;
    int h;
} struct_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
int my_getnbr(char const *str);

int argument_sorting(struct_t *my_struct, char **env);
int body(char **env);
int array_loop(struct_t *struc, int y);
int order_in_array(struct_t *my_struct);
void sub_array_loop(struct_t *struc, int y, int nb);
int function_output(struct_t *my_struct);
int cd_sort(struct_t *my_struct, int a);
int path_detection(struct_t *my_struct, char **env);
int hub_function(struct_t *my_struct, int a);
int path_sort(struct_t *my_struct, char **env, int a);
int with_path(char **env, struct_t *my_struct);

#endif /* !LIBMY_H_ */