/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** prints numbers
*/

#include "my_num.h"
#include "my_string.h"

int my_put_nbr(int nb)
{
    int length;

    if (nb < 0) {
        length += my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0 && nb < 10)
        length += my_putchar(nb + '0');
    if (nb >= 10) {
        int n = 0;
        n = (nb % 10);
        nb = (nb - n) / 10;
        length += my_put_nbr(nb);
        length += my_put_nbr(n);
    }
    return (length);
}
