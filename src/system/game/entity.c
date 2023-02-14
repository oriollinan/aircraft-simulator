/*
** EPITECH PROJECT, 2022
** entity
** File description:
** handles the entities
*/

#include "entity.h"

static void entity_ctor(void *entity, va_list *list)
{
    ENT(entity)->texture = sfTexture_createFromFile(va_arg(*list, char *),
    NULL);
    ENT(entity)->sprite = sfSprite_create();
    sfSprite_setTexture(ENT(entity)->sprite, ENT(entity)->texture, sfFalse);
}

static void entity_dtor(void *entity)
{
    sfSprite_destroy(ENT(entity)->sprite);
    sfTexture_destroy(ENT(entity)->texture);
    free(ENT(entity));
}

static void entity_set_scale(entity_t *ent, sfVector2f scale)
{
    sfSprite_setScale(ent->sprite, scale);
}

static void entity_set_position(entity_t *ent, sfVector2f pos)
{
    sfSprite_setPosition(ent->sprite, pos);
}

static void entity_set_rotation(entity_t *ent, float angle)
{
    sfSprite_setRotation(ent->sprite, angle);
}

static const entity_t def_entity = {
    {
    .name = "Entity",
    .size = sizeof(entity_t),
    .ctor = &entity_ctor,
    .dtor = &entity_dtor
    },
    .setScale = &entity_set_scale,
    .setPosition = &entity_set_position,
    .setRotation = &entity_set_rotation,
    .texture = NULL,
    .sprite = NULL
};

const class_t *Entity = (class_t *)&def_entity;
