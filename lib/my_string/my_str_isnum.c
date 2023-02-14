/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** some numeral strings
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    return (0);
}
