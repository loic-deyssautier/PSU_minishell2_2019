/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_strlen function
*/

int my_strlen(const char *str)
{
    int count;
    for (count = 0; str[count] != 0; count++);
    return (count);
}