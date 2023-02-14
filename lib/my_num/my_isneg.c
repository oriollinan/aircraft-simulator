/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** checking negative numbers
*/

#include "my_num.h"

bool my_isneg(int n)
{
    if (n >= 0)
        return (false);
    else
        return (true);
}
