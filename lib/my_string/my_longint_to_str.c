/*
** EPITECH PROJECT, 2022
** my_int_to_str.c
** File description:
** converts an integer to a string
*/

char *my_longint_to_str(char *str, long int nb)
{
    int num = 1;
    int count = 0;

    if (nb < 0) {
        str[count] = '-';
        nb = (-1) * nb;
    }
    while ((nb / num) >= 10)
        num = num * 10;
    while (num >= 1) {
        str[count] = (nb / num) % 10 + 48;
        num = num / 10;
        count++;
    }
    return (str);
}
