/*
** EPITECH PROJECT, 2022
** system
** File description:
** h file for system
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include "my_radar.h"

    #define SYS(system) ((system_t *)system)

    typedef struct game_s game_t;
    typedef struct file_s file_t;
    typedef struct cloc_s cloc_t;

    typedef struct system_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*run)(struct system_s *);

        // ATTRIBUTES
        game_t *game;
        file_t *file;
        cloc_t *clock;
    } system_t;

    extern const class_t *System;

#endif
