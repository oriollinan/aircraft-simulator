/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** copying the string using malloc
*/

#include "my_string.h"

char *my_strdup(char const *src)
{
    char *res = malloc(sizeof(char) * ((my_strlen(src)) + 1));
    int i = 0;

    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}
