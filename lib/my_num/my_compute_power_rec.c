/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** doing powers using recursive functions
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    nb = nb * my_compute_power_rec(nb, p - 1);
    return (nb);
}
