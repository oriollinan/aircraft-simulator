/*
** EPITECH PROJECT, 2022
** rectangle
** File description:
** creates rectangles to check hitbox
*/

#include "rectangle.h"

static void rectangle_ctor(void *rectangle, va_list *list)
{
    RECT(rectangle)->rect = sfRectangleShape_create();
    RECT(rectangle)->size = (sfVector2f) {(float) va_arg(*list, double),
    (float) va_arg(*list, double)};
    RECT(rectangle)->setSize(RECT(rectangle), RECT(rectangle)->size);
}

static void rectangle_dtor(void *rectangle)
{
    sfRectangleShape_destroy(RECT(rectangle)->rect);
    free(RECT(rectangle));
}

static void rectangle_set_position(rectangle_t *rectangle, sfVector2f pos)
{
    rectangle->pos = pos;
    sfRectangleShape_setPosition(rectangle->rect, rectangle->pos);
}

static void rectangle_set_fillcolor(rectangle_t *rectangle, sfColor color)
{
    sfRectangleShape_setFillColor(rectangle->rect, color);
}

static void rectangle_set_outlinecolor(rectangle_t *rectangle, sfColor color)
{
    sfRectangleShape_setOutlineColor(rectangle->rect, color);
}

static void rectangle_set_outlinethickness(rectangle_t *rectangle,
float thickness)
{
    sfRectangleShape_setOutlineThickness(rectangle->rect, thickness);
}

static void rectangle_set_rotation(rectangle_t *rectangle, float angle)
{
    sfRectangleShape_setRotation(rectangle->rect, angle);
}

static void rectangle_set_size(rectangle_t *rectangle, sfVector2f size)
{
    sfRectangleShape_setSize(rectangle->rect, size);
    rectangle->size = size;
}

static sfFloatRect rectangle_get_bounds(rectangle_t *rectangle)
{
    sfVector2f pos = sfRectangleShape_getPosition(rectangle->rect);
    float hypotenuse = hypot(rectangle->size.x, rectangle->size.y);
    sfFloatRect bounds = {pos.x, pos.y, hypotenuse, hypotenuse};
    return (bounds);
}

static const rectangle_t def_rectangle = {
    {
    .name = "Rectangle",
    .size = sizeof(rectangle_t),
    .ctor = &rectangle_ctor,
    .dtor = &rectangle_dtor
    },
    .setPosition = &rectangle_set_position,
    .setFillColor = &rectangle_set_fillcolor,
    .setOutlineColor = &rectangle_set_outlinecolor,
    .setOutlineThickness = &rectangle_set_outlinethickness,
    .setRotation = &rectangle_set_rotation,
    .setSize = &rectangle_set_size,
    .getBounds = &rectangle_get_bounds,
    .rect = NULL,
    .pos = {.x = 0, .y = 0},
    .size = {.x = 0, .y = 0}
};

const class_t *Rectangle = (class_t *)&def_rectangle;
