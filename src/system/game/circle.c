/*
** EPITECH PROJECT, 2022
** circle
** File description:
** handles the circle
*/

#include "circle.h"

static void circle_ctor(void *circle, va_list *list)
{
    CIRCLE(circle)->circle = sfCircleShape_create();
    CIRCLE(circle)->radius = (float) va_arg(*list, double);
    CIRCLE(circle)->setRadius(CIRCLE(circle), CIRCLE(circle)->radius);
}

static void circle_dtor(void *circle)
{
    sfCircleShape_destroy(CIRCLE(circle)->circle);
    free(CIRCLE(circle));
}

static void circle_set_position(circle_t *circle, sfVector2f pos)
{
    circle->pos = pos;
    sfCircleShape_setPosition(circle->circle, circle->pos);
}

static void circle_set_fillcolor(circle_t *circle, sfColor color)
{
    sfCircleShape_setFillColor(circle->circle, color);
}

static void circle_set_outlinecolor(circle_t *circle, sfColor color)
{
    sfCircleShape_setOutlineColor(circle->circle, color);
}

static void circle_set_outlinethickness(circle_t *circle, float thickness)
{
    sfCircleShape_setOutlineThickness(circle->circle, thickness);
}

static void circle_set_rotation(circle_t *circle, float angle)
{
    sfCircleShape_setRotation(circle->circle, angle);
}

static void circle_set_radius(circle_t *circle, float radius)
{
    sfCircleShape_setRadius(circle->circle, radius);
    circle->radius = radius;
}

static sfFloatRect circle_get_bounds(circle_t *circle)
{
    sfVector2f pos = sfCircleShape_getPosition(circle->circle);
    float hypotenuse = hypot(circle->radius * 2, circle->radius * 2);
    sfFloatRect bounds = {pos.x, pos.y, hypotenuse, hypotenuse};
    return (bounds);
}

static const circle_t def_circle = {
    {
    .name = "Circle",
    .size = sizeof(circle_t),
    .ctor = &circle_ctor,
    .dtor = &circle_dtor
    },
    .setPosition = &circle_set_position,
    .setFillColor = &circle_set_fillcolor,
    .setOutlineColor = &circle_set_outlinecolor,
    .setOutlineThickness = &circle_set_outlinethickness,
    .setRotation = &circle_set_rotation,
    .setRadius = &circle_set_radius,
    .getBounds = &circle_get_bounds,
    .circle = NULL,
    .pos = {.x = 0, .y = 0},
    .radius = 0
};

const class_t *Circle = (class_t *)&def_circle;
