/*
** EPITECH PROJECT, 2022
** plane
** File description:
** h file for plane
*/

#ifndef PLANE_H_
    #define PLANE_H_

    #include "my_radar.h"

    #define PLANE(plane) ((plane_t *)plane)

    typedef struct cloc_s cloc_t;
    typedef struct entity_s entity_t;
    typedef struct rectangle_s rectangle_t;

    typedef struct plane_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*move)(struct plane_s *, cloc_t *);
        void (*bounds)(struct plane_s *);

        // ATTRIBUTES
        entity_t *ent;
        rectangle_t *rectangle;
        sfVector2f pos;
        sfVector2f ini_pos;
        sfVector2f des;
        sfVector2f dir;
        int delay;
        bool visible;
        float angle;
    } plane_t;

    extern const class_t *Plane;

#endif
