/*
** EPITECH PROJECT, 2022
** my_stralphalen.c
** File description:
** finds the length of the str alpha chars
*/

int my_stralphalen(char *str)
{
    int length = 0;

    while (str[length] && (('A' <= str[length] && str[length] <= 'Z') ||
    ('a' <= str[length] && str[length] <= 'z')))
        length++;
    return (length);
}
