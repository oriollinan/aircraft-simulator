/*
** EPITECH PROJECT, 2022
** my_longintlen
** File description:
** returns the amount of numbers in a number
*/

int my_longintlen(long int nb)
{
    int i = 1;
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
    return (i);
}
