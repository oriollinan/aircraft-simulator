/*
** EPITECH PROJECT, 2022
** my_num
** File description:
** handles functions dealing with nums
*/

#ifndef MY_NUM_H_
    #define MY_NUM_H_

    #include <stdbool.h>

    unsigned long int my_compute_power_long(unsigned long int nb, int p);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_intlen(int nb);
    int my_is_prime(int nb);
    int my_longintlen(long int nb);
    bool my_isneg(int n);
    int my_put_double(double nb, int precision);
    int my_put_nbr(int nb);
    void my_sort_int_array(int *array, int size);
    int my_put_uns_int(unsigned int nb);

#endif
