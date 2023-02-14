/*
** EPITECH PROJECT, 2022
** my_split
** File description:
** splits a str into an array
*/

#include "my_arr.h"

int biggest_length(char *str, char separator, int i)
{
    static int length = 0;

    for (int x = i; str[x] && str[x] != separator; x++)
        length = (x - i >= length) ? x - i + 1 : length;
    return (length);
}

void fill_arr(char *str, char separator, char **arr, int i)
{
    int x = 0;
    static int y = 0;

    for (int a = i; str[a] && str[a] != separator; a++) {
        arr[y][x] = str[a];
        x++;
    }
    y++;
}

char **my_new_split(char *str, char separator)
{
    char **arr = NULL;
    int length = 0;
    int rows = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != separator && ((str[i - 1] &&
        str[i - 1] == separator) || !str[i - 1])) {
            length = biggest_length(str, separator, i);
            rows++;
        }
    }
    arr = my_arr_ini(length, rows);
    for (int i = 0; str[i]; i++) {
        if (str[i] != separator && ((str[i - 1] &&
        str[i - 1] == separator) || !str[i - 1]))
            fill_arr(str, separator, arr, i);
    }
    return (arr);
}
