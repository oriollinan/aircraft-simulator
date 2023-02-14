/*
** EPITECH PROJECT, 2022
** rectangle
** File description:
** h file for rectangle
*/

#ifndef RECTANGLE_H_
    #define RECTANGLE_H_

    #include "my_radar.h"

    #define RECT(rectangle) ((rectangle_t *)rectangle)

    typedef struct rectangle_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*setPosition)(struct rectangle_s *, sfVector2f);
        void (*setFillColor)(struct rectangle_s *, sfColor);
        void (*setOutlineColor)(struct rectangle_s *, sfColor);
        void (*setOutlineThickness)(struct rectangle_s *, float);
        void (*setRotation)(struct rectangle_s *, float);
        void (*setSize)(struct rectangle_s *, sfVector2f);
        sfFloatRect (*getBounds)(struct rectangle_s *);

        // ATTRIBUTES
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
    } rectangle_t;

    extern const class_t *Rectangle;

#endif
