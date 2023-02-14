/*
** EPITECH PROJECT, 2022
** events
** File description:
** h file for events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include "my_radar.h"

    #define EVENTS(events) ((events_t *)events)

    typedef struct game_s game_t;
    typedef struct plane_s plane_t;
    typedef struct tower_s tower_t;
    typedef struct rectangle_s rectangle_t;

    typedef struct events_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*IsEvent)(game_t *);
        void (*crash)(plane_t **, tower_t **, rectangle_t **);
        bool (*IsOver)(plane_t **);
        

        // ATTRIBUTES
        sfEvent event;
    } events_t;

    extern const class_t *Events;

#endif
