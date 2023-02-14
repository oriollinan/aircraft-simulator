/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** comparing strings
*/

#include "my_string.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] != '\0' && s2[a] != '\0') {
        if (s1[a] > s2[a])
            return (1);
        if (s2[a] > s1[a])
            return (-1);
        a++;
    }
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s2) > my_strlen(s1))
        return (-1);
    return (0);
}
