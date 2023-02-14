/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** function that displays the number given as a parameter.
** It must be able to display all the possible values of an int
*/

#include "my_string.h"

int my_put_uns_int(unsigned int nb)
{
    int num = 1;
    int length;

    if (nb < 0 && nb >= -2147483648) {
        length += my_putchar('-');
        nb = (-1) * nb;
    }
    while ((nb / num) >= 10 && nb <= 2147483647)
        num = num * 10;
    while (num >= 1) {
        length += my_putchar((nb / num) % 10 + 48);
        num /= 10;
    }
    return (length);
}
