/*
** EPITECH PROJECT, 2022
** my_strdup_range
** File description:
** duplicate strings but only a certain range
*/

#include "my_string.h"

char *my_strdup_range(char const *src, int start, int end)
{
    char *res;
    int i = 0;

    if (start > my_strlen(src) || end > my_strlen(src))
        return (NULL);
    if (end == 0)
        end = my_strlen(src);
    res = malloc(sizeof(char) * (end - start + 1));
    while (src[start] != '\0' && start <= end) {
        res[i] = src[start];
        i++;
        start++;
    }
    res[i] = '\0';
    return (res);
}
