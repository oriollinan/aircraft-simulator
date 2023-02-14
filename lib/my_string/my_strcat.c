/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** copying strings and null bytes
*/

#include "my_string.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = my_strlen(dest);

    while (src[i]) {
        dest[n] = src[i];
        i++;
        n++;
    }
    dest[n] = '\0';
    return (dest);
}
