/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** counting the amount of characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str && str[i] != '\0')
        i++;
    return (i);
}
