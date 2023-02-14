/*
** EPITECH PROJECT, 2022
** circle
** File description:
** h file for circle
*/

#ifndef CIRCLE_H_
    #define CIRCLE_H_

    #include "my_radar.h"

    #define CIRCLE(circle) ((circle_t *)circle)

    typedef struct circle_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*setPosition)(struct circle_s *, sfVector2f);
        void (*setFillColor)(struct circle_s *, sfColor);
        void (*setOutlineColor)(struct circle_s *, sfColor);
        void (*setOutlineThickness)(struct circle_s *, float);
        void (*setRotation)(struct circle_s *, float);
        void (*setRadius)(struct circle_s *, float);
        sfFloatRect (*getBounds)(struct circle_s *);

        // ATTRIBUTES
        sfCircleShape *circle;
        sfVector2f pos;
        float radius;
    } circle_t;

    extern const class_t *Circle;

#endif
