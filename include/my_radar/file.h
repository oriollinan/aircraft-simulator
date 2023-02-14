/*
** EPITECH PROJECT, 2022
** file
** File description:
** h file for file
*/

#ifndef FILE_H_
    #define FILE_H_

    #include "my_radar.h"

    #define FILE(file) ((file_t *)file)

    typedef struct file_s {
        // INHERITANCE
        class_t class;

        // METHODS
        char *(*read)(char *);
        char **(*split)(char *, char);

        // ATTRIBUTES
        char *path;
        char *file_str;
        char **file_arr;
    } file_t;

    extern const class_t *File;

#endif
