/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** h file for my radar oop
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <fcntl.h>
    #include <time.h>
    #include <stdarg.h>
    #include <string.h>
    #include <stdbool.h>

    typedef struct class_s {
        char const *name;
        size_t size;
        void (*ctor)(void *, va_list *);
        void (*dtor)(void *);
    } class_t;

    void my_radar(int ac, char **av);
    class_t *new(const class_t *this, ...);
    bool error_handling(int ac, char **av);
    char *read_file(char *path, int size);
    long int file_size(char *file);
    char **get_ent(int ac, char **av);

#endif
