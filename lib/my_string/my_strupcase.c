/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** capitalizing strings
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
