/*
** EPITECH PROJECT, 2022
** my_realloc
** File description:
** reallocates memory to a str
*/

#include "my_string.h"

char *my_realloc(char *str, int nb)
{
    char *res = my_malloc_ini(nb + 1);

    res[nb] = '\0';
    if (str) {
        res = my_strcpy(res, str);
        free(str);
    }
    return (res);
}
