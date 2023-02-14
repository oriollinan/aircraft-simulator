/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displaying str characters one by one
*/

#include "my_string.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (i);
}
