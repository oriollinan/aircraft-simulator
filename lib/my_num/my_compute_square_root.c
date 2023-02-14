/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** finding the square root of whole numbers
*/

int my_compute_square_root(int nb)
{
    int a = 1;

    while (nb / a != a){
        a++;
    }
    return (a);
}
