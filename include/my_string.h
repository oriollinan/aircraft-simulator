/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** handles functinos dealing with strings
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>

    int my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *src);
    int my_showmem(char const *str, int size);
    int my_showstr(char const *str);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    char *my_strdup(char const *src);
    char *my_malloc_ini(int nb);
    char *my_int_to_str(char *str, int nb);
    char *my_double_to_str(char *str, double nb, int precision);
    char **my_str_swap(char **arr, int dest, int src);
    char *my_round_str(char *str, int pos);
    char *my_longint_to_str(char *str, long int nb);
    int my_stralphalen(char *str);
    int my_strcmp_nsens(char const *s1, char const *s2);
    char *my_strdup_range(char const *src, int start, int end);
    char *my_char_to_str(char letter);
    char *my_realloc(char *str, int nb);
    int my_puterror(char *str);
    void my_memcpy(void *dest, const void *src, size_t n);

#endif
