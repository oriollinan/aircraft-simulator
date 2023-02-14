/*
** EPITECH PROJECT, 2022
** my_malloc_ini
** File description:
** creates a malloc and initialize to '\0'
*/

#include "my_string.h"

char *my_malloc_ini(int nb)
{
    char *str;

    str = malloc(sizeof(char) * nb + 1);
    for (int i = 0; i < nb + 1; i++)
        str[i] = '\0';
    return (str);
}
