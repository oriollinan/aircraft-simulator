/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** copying strings and null bytes
*/

#include "my_string.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int length = my_strlen(dest);

    while (src[i] && i < nb) {
        dest[length] = src[i];
        i++;
        length++;
    }
    dest[length] = '\0';
    return (dest);
}
