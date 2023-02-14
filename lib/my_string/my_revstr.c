/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reversing a string
*/

#include "my_string.h"

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str);
    char temp = '\0';

    while (a < b) {
        temp = str[a];
        str[a] = str[b - 1];
        str[b - 1] = temp;
        a++;
        b--;
    }
    str[my_strlen(str)] = '\0';
    return (str);
}
