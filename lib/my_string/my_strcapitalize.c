/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** capitalizing the first letter of every word
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (31 < str[i] && str[i] < 64)
            i++;
        if ((64 < str[i] && str[i] < 91) &&
            (31 < str[i - 1] && str[i - 1] < 64)) {
            i++;
        }
        if ((96 < str[i] && str[i] < 123) &&
            (31 < str[i - 1] && str[i - 1] < 64)) {
            str[i] = str[i] - 32;
        }
        if ((64 < str[i] && str[i] < 91) &&
            (64 < str[i - 1] && str[i - 1] < 123)) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}
