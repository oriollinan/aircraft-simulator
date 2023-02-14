/*
** EPITECH PROJECT, 2022
** my_puterror
** File description:
** displays a message on the error output
*/

#include "my_string.h"

int my_puterror(char *str)
{
    int length = 0;

    while (str[length]) {
        write(2, &str[length], 1);
        length++;
    }
    return (length);
}
