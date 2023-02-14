/*
** EPITECH PROJECT, 2022
** my_round_str
** File description:
** rounding a number in a str
*/

void point_check(char *str, int pos);

char *my_round_str(char *str, int pos)
{
    if (str[pos + 1] >= '5') {
        if (str[pos] == '9') {
            str[pos] = '0';
            point_check(str, pos);
        } else
            str[pos]++;
    }
    return (str);
}

void point_check(char *str, int pos)
{
    if (str[pos--] == '.')
        my_round_str(str, pos - 2);
    else
        my_round_str(str, pos--);
}
