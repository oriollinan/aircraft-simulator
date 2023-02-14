/*
** EPITECH PROJECT, 2022
** plane
** File description:
** plane class ini
*/

#include "plane.h"
#include "my_string.h"
#include "my_arr.h"
#include "my_num.h"
#include "clock.h"
#include "entity.h"
#include "rectangle.h"

static void transform_plane(plane_t *plane)
{
    plane->angle = atan(plane->dir.y / plane->dir.x) * 180 / M_PI;

    if (plane->dir.x < 0)
        plane->angle += 180;
    plane->ent = (entity_t *)new(Entity, "assets/plane.png");
    plane->ent->setScale(plane->ent, (sfVector2f) {0.07, 0.07});
    plane->ent->setPosition(plane->ent, plane->pos);
    plane->ent->setRotation(plane->ent, plane->angle);
}

static void set_rectangle(plane_t *plane)
{
    plane->rectangle = (rectangle_t *)new(Rectangle, 20.0, 20.0);
    plane->rectangle->setPosition(plane->rectangle, plane->pos);
    plane->rectangle->setFillColor(plane->rectangle, sfTransparent);
    plane->rectangle->setOutlineColor(plane->rectangle, sfYellow);
    plane->rectangle->setOutlineThickness(plane->rectangle, 1);
    plane->rectangle->setRotation(plane->rectangle, plane->angle);
}

static void set_vectors(plane_t *plane, char **arr)
{
    sfVector2f vector = {0, 0};

    plane->pos = (sfVector2f) {(double) my_getnbr(arr[1]),
    (double) my_getnbr(arr[2])};
    plane->ini_pos = plane->pos;
    plane->des = (sfVector2f) {(double) my_getnbr(arr[3]),
    (double) my_getnbr(arr[4])};
    vector.x = plane->des.x - plane->pos.x;
    vector.y = plane->des.y - plane->pos.y;
    float module = hypot(vector.x, vector.y);
    int speed = my_getnbr(arr[5]);
    if (speed < 0)
        speed *= -1;
    plane->dir = (sfVector2f) {vector.x / module, vector.y / module};
    plane->dir.x *= speed;
    plane->dir.y *= speed;
}

static void plane_ctor(void *plane, va_list *list)
{
    char *str = va_arg(*list, char *);
    char **arr = my_split(str, ' ');

    set_vectors(PLANE(plane), arr);
    PLANE(plane)->delay = my_getnbr(arr[6]);
    transform_plane(PLANE(plane));
    set_rectangle(PLANE(plane));
    free_arr(arr);
}

static void plane_dtor(void *plane)
{
    PLANE(plane)->rectangle->class.dtor(PLANE(plane)->rectangle);
    PLANE(plane)->ent->class.dtor(PLANE(plane)->ent);
    free(PLANE(plane));
}

static bool not_moving(plane_t *plane, cloc_t *clock)
{
    sfVector2f def = {-100, -100};

    if (plane->delay > clock->time(clock)) {
        plane->visible = false;
        return (true);
    }
    if ((int) plane->pos.x == -100 && (int) plane->pos.y == -100)
        return (true);
    if (plane->dir.x == 0 && plane->dir.y == 0) {
        plane->pos = def;
        plane->ent->setPosition(plane->ent, def);
        plane->rectangle->setPosition(plane->rectangle, def);
        return (true);
    }
    return (false);
}

static void plane_move(plane_t *plane, cloc_t *clock)
{
    sfVector2f def = {-100, -100};

    if (not_moving(plane, clock))
        return;
    if (hypot(plane->pos.x - plane->ini_pos.x,
    plane->pos.y - plane->ini_pos.y) >=
    hypot(plane->des.x - plane->ini_pos.x,
    plane->des.y - plane->ini_pos.y)) {
        plane->visible = false;
        plane->dir = (sfVector2f) {0, 0};
        plane->pos = def;
        plane->ent->setPosition(plane->ent, def);
        plane->rectangle->setPosition(plane->rectangle, def);
        return;
    }
    plane->visible = true;
    plane->pos.x += plane->dir.x;
    plane->pos.y += plane->dir.y;
    plane->ent->setPosition(plane->ent, plane->pos);
    plane->rectangle->setPosition(plane->rectangle, plane->pos);
}

static void plane_bounds(plane_t *plane)
{
    if (!plane->visible)
        return;
    if (plane->pos.x <= -20)
        plane->pos.x = 1920;
    if (plane->pos.x > 1920)
        plane->pos.x = -20;
    if (plane->pos.y <= -20)
        plane->pos.y = 1080;
    if (plane->pos.y > 1080)
        plane->pos.y = -20;
}

static const plane_t def_plane = {
    {
    .name = "Plane",
    .size = sizeof(plane_t),
    .ctor = &plane_ctor,
    .dtor = &plane_dtor
    },
    .move = &plane_move,
    .bounds = &plane_bounds,
    .ent = NULL,
    .rectangle = NULL,
    {.x = 0, .y = 0},
    {.x = 0, .y = 0},
    {.x = 0, .y = 0},
    {.x = 0, .y = 0},
    .visible = true,
    .angle = 0
};

const class_t *Plane = (class_t *)&def_plane;
