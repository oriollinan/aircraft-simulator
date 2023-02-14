/*
** EPITECH PROJECT, 2022
** my_char_to_str
** File description:
** turns a char into a str
*/

#include "my_string.h"

char *my_char_to_str(char letter)
{
    int i = 0;
    char *str = my_malloc_ini(2);
    str[1] = '\0';

    while (i != letter)
        i++;
    str[0] = i;
    return (str);
}
