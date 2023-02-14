/*
** EPITECH PROJECT, 2022
** my_intlen
** File description:
** returns the amount of numbers in a number
*/

int my_intlen(int nb)
{
    int i = 0;

    while (nb >= 10) {
        nb = nb / 10;
        i++;
    }
    while (nb < 1) {
        if (nb == 0)
            return (1);
        nb *= 10;
        i++;
    }
    if (i == 0);
        i++;
    return (i);
}
