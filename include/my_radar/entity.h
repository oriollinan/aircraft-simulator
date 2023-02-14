/*
** EPITECH PROJECT, 2022
** entity
** File description:
** h file for entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "my_radar.h"

    #define ENT(entity) ((entity_t *)entity)

    typedef struct entity_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*setScale)(struct entity_s *, sfVector2f);
        void (*setPosition)(struct entity_s *, sfVector2f);
        void (*setRotation)(struct entity_s *, float);

        // ATTRIBUTES
        sfTexture *texture;
        sfSprite *sprite;
    } entity_t;

    extern const class_t *Entity;

#endif
