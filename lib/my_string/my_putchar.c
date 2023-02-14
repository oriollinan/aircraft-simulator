/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** prints character yay
*/

#include "my_string.h"

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
