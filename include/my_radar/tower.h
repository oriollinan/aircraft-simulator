/*
** EPITECH PROJECT, 2022
** tower
** File description:
** h file for towers
*/

#ifndef TOWER_H_
    #define TOWER_H_

    #include "my_radar.h"

    #define TOWER(tower) ((tower_t *)tower)

    typedef struct entity_s entity_t;
    typedef struct circle_s circle_t;

    typedef struct tower_s {
        // INHERITANCE
        class_t class;

        // ATTRIBUTES
        entity_t *ent;
        circle_t *circle;
        sfVector2f pos;
    } tower_t;

    extern const class_t *Tower;

#endif
