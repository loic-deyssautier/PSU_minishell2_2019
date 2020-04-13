/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_putchar function
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}