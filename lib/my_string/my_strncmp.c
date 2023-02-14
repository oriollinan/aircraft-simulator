/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** string comparison but its only n values
*/

#include "my_string.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;

    while (s1[a] != '\0' && s2[a] != '\0' && a <= n) {
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
