/*
** EPITECH PROJECT, 2022
** tower
** File description:
** initializes the tower struct
*/

#include "tower.h"
#include "my_arr.h"
#include "my_num.h"
#include "circle.h"
#include "entity.h"

static void set_tower(tower_t *tower, float radius)
{
    sfVector2f scale = {0.059, 0.059};

    tower->ent = (entity_t *)new(Entity, "assets/tower.png");
    tower->ent->setPosition(tower->ent, tower->pos);
    tower->ent->setScale(tower->ent, scale);
    tower->circle = (circle_t *)new(Circle, radius);
    tower->circle->pos.x = tower->pos.x - tower->circle->radius + 15;
    tower->circle->pos.y = tower->pos.y - tower->circle->radius + 15;
    tower->circle->setFillColor(tower->circle, sfTransparent);
    tower->circle->setOutlineColor(tower->circle, sfGreen);
    tower->circle->setOutlineThickness(tower->circle, 2);
    tower->circle->setPosition(tower->circle, tower->circle->pos);
}

static void tower_ctor(void *tower, va_list *list)
{
    char *str = va_arg(*list, char *);
    char **arr = my_split(str, ' ');

    TOWER(tower)->pos = (sfVector2f) {(double) my_getnbr(arr[1]),
    (double) my_getnbr(arr[2])};
    set_tower(TOWER(tower), 1980 * ((double) my_getnbr(arr[3]) / 100));
    free_arr(arr);
}

static void tower_dtor(void *tower)
{
    TOWER(tower)->circle->class.dtor(TOWER(tower)->circle);
    TOWER(tower)->ent->class.dtor(TOWER(tower)->ent);
    free(TOWER(tower));
}

static const tower_t def_tower = {
    {
    .name = "Tower",
    .size = sizeof(tower_t),
    .ctor = &tower_ctor,
    .dtor = &tower_dtor
    },
    .ent = NULL,
    .circle = NULL,
    {.x = 0, .y = 0},
};

const class_t *Tower = (class_t *)&def_tower;
