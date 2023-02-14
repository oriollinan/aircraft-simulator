/*
** EPITECH PROJECT, 2022
** my_arrlen
** File description:
** returns length of an array
*/

int my_arrlen(char **arr)
{
    int length = 0;

    while (arr[length])
        length++;
    return (length);
}
