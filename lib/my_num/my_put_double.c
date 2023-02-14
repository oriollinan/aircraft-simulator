/*
** EPITECH PROJECT, 2022
** my_put_double
** File description:
** displays a double
*/

#include "my_num.h"
#include "my_string.h"

int my_put_double(double nb, int precision)
{
    int dec_nb = 0;
    int dec_places = precision;
    int num = (int) nb;

    dec_places = my_compute_power_rec(10, dec_places);
    dec_nb = (int) (nb * dec_places) % dec_places;
    my_put_nbr(num);
    my_putchar('.');
    my_put_nbr(dec_nb);
    return (my_intlen(num) + dec_places + 1);
}
