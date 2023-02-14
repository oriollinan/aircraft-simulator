/*
** EPITECH PROJECT, 2022
** my_split.c
** File description:
** turns a string into array
*/

#include "my_arr.h"
#include "my_string.h"

int diff_strlen(char const *str, char separator)
{
    int i = 0;
    int word_counter = 0;

    while (str[i] != '\0') {
        if (str[i] == separator && str[i + 1] != separator) {
            word_counter++;
        }
        i++;
    }
    if (str[0] != separator)
        word_counter++;
    if (str[my_strlen(str) - 1] == separator)
        word_counter--;
    return (word_counter);
}

int word_check(char const *str, int start_letter, char separator)
{
    if (str[start_letter] == separator)
        return (1);
    return (0);
}

char **str_malloc(int words, int length, char const *str)
{
    int counter1 = 0;
    int counter2 = 0;
    char **res = malloc(sizeof(char *) * (words + 1));

    while (counter1 < words) {
        res[counter1] = NULL;
        res[counter1] = malloc(sizeof(char) * (length + 1));
        counter2 = 0;
        while (counter2 <= length) {
            res[counter1][counter2] = '\0';
            counter2++;
        }
        counter1++;
    }
    res[words] = NULL;
    return (res);
}

char **word_array(int words, char **res, char const *str, char separator)
{
    int counter1 = 0;
    int counter2 = 0;
    int start_letter = 0;

    while (counter1 < words) {
        while (str[start_letter] &&
        word_check(str, start_letter, separator) != 1) {
            res[counter1][counter2] = str[start_letter];
            start_letter++;
            counter2++;
        }
        while (str[start_letter] &&
        word_check(str, start_letter, separator) == 1)
            start_letter++;
        if (counter2 != 0 || !str[start_letter]) {
            counter2 = 0;
            counter1++;
        }
    }
    return (res);
}

char **my_split(char const *str, char separator)
{
    char **res = NULL;
    int words = diff_strlen(str, separator);
    int length = my_strlen(str);
    res = str_malloc(words, length, str);
    res = word_array(words, res, str, separator);
    return (res);
}
