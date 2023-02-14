/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** needle in a haystack
*/

#include "my_string.h"

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int b = 0;
    int c = my_strlen(to_find);
    int position = 0;

    while (str[a] != '\0'){
        int d = a;
        while (str[a] == to_find[b] && to_find[b] != '\0'){
            a++;
            b++;
        }
        position = a - b;
        if (c == b){
            return (str + position);
        }
        a = d + 1;
        b = 0;
    }
    return (NULL);
}
