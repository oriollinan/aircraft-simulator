/*
** EPITECH PROJECT, 2022
** my_str_swap
** File description:
** swaping two chars in a string
*/

#include "my_string.h"

char **my_str_swap(char **arr, int dest, int src)
{
    char *temp;

    if (my_strlen(arr[dest]) > my_strlen(arr[src]))
        temp = malloc(my_strlen(arr[dest]) + 1);
    else
        temp = malloc(my_strlen(arr[src]) + 1);
    temp = my_strcpy(temp, arr[dest]);
    arr[dest] = my_strcpy(arr[dest], arr[src]);
    arr[src] = my_strcpy(arr[src], temp);
    free(temp);
    return (arr);
}
