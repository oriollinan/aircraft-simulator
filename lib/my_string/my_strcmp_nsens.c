/*
** EPITECH PROJECT, 2022
** my_strcmp_nsens
** File description:
** strcmp but its not case sensitive
*/

#include "my_string.h"

int upper_to_lower(int letter1, int letter2, int *ncase2)
{
    if ('A' <= letter1 && letter1 <= 'Z')
        letter1 += 32;
    if ('A' <= letter2 && letter2 <= 'Z')
        *ncase2 += letter2 + 32;
    else
        *ncase2 = letter2;
    return (letter1);
}

int my_strcmp_nsens(char const *s1, char const *s2)
{
    int a = 0;
    int ncase1 = 0;
    int ncase2 = 0;

    while (s1[a] != '\0' && s2[a] != '\0') {
        ncase1 = upper_to_lower(s1[a], s2[a], &ncase2);
        if (ncase1 > ncase2)
            return (1);
        if (ncase2 > ncase1)
            return (-1);
        a++;
    }
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s2) > my_strlen(s1))
        return (-1);
    return (0);
}
