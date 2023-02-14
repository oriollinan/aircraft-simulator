/*
** EPITECH PROJECT, 2022
** game
** File description:
** h file for game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "my_radar.h"

    #define GAME(game) ((game_t *)game)

    typedef struct cloc_s cloc_t;
    typedef struct window_s window_t;
    typedef struct events_s events_t;
    typedef struct plane_s plane_t;
    typedef struct tower_s tower_t;
    typedef struct rectangle_s rectangle_t;
    typedef struct entity_s entity_t;
    typedef struct text_s text_t;

    typedef struct game_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*start)(struct game_s *, cloc_t *);
        void (*time)(struct game_s *, cloc_t *);

        // ATTRIBUTES
        window_t *window;
        events_t *events;
        plane_t **planes;
        tower_t **towers;
        rectangle_t **rectangles;
        entity_t *ent;
        text_t *text;
        bool entity_hidden;
        bool hitbox_hidden;
    } game_t;

    extern const class_t *Game;

#endif
