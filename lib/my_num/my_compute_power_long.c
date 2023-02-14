/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** Write an recursive function that returns the first
** argument raised to the power p, where p is the second argument.
*/

unsigned long int my_compute_power_long(unsigned long int nb, int p)
{
    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (p == 1) {
        return (nb);
    }
    if (p == 2) {
        return (nb * nb);
    }

    nb = nb * my_compute_power_long(nb, p - 1);
    return (nb);
}
