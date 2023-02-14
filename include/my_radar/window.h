/*
** EPITECH PROJECT, 2022
** window
** File description:
** h file for window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include "my_radar.h"

    #define WINDOW(window) ((window_t *)window)

    typedef struct game_s game_t;

    typedef struct window_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*clear)(struct window_s *);
        void (*draw)(game_t *);
        void (*display)(struct window_s *);
        sfBool (*IsOpen)(struct window_s *);
        void (*close)(struct window_s *);

        // ATTRIBUTES
        sfRenderWindow *window;
    } window_t;

    extern const class_t *Window;

#endif
