/*
** EPITECH PROJECT, 2022
** my_arr_ini
** File description:
** initiang and creating a 2d array
*/

#include "my_arr.h"

void free_arr(char **arr)
{
    for (int a = 0; arr[a]; a++)
        free(arr[a]);
    free(arr);
}

char **my_arr_ini(int x, int y)
{
    char **arr = malloc(sizeof(char *) * (y + 1));

    if (!arr)
        return (NULL);
    for (int i = 0; i < y; i++) {
        arr[i] = malloc(sizeof(char) * (x + 1));
        if (!arr[i])
            return (NULL);
        for (int j = 0; j <= x; j++)
            arr[i][j] = '\0';
    }
    arr[y] = NULL;
    return (arr);
}
