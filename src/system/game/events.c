/*
** EPITECH PROJECT, 2022
** events
** File description:
** handles the events
*/

#include "events.h"
#include "my_string.h"
#include "game.h"
#include "window.h"
#include "plane.h"
#include "tower.h"
#include "rectangle.h"
#include "circle.h"

static void events_ctor(void *events, va_list *list)
{
    EVENTS(events)->event;
}

static void events_dtor(void *events)
{
    free(EVENTS(events));
}

static void is_events(game_t *game)
{
    if (game->events->IsOver(game->planes))
        game->window->close(game->window);
    while (sfRenderWindow_pollEvent(game->window->window,
    &game->events->event)) {
        if (game->events->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            game->window->close(game->window);
        game->hitbox_hidden = sfKeyboard_isKeyPressed(sfKeyL);
        game->entity_hidden = sfKeyboard_isKeyPressed(sfKeyS);
    }
    game->events->crash(game->planes, game->towers, game->rectangles);
}

static bool check_tower(tower_t **tower, sfFloatRect plane1, sfFloatRect plane2)
{
    sfFloatRect tow;
    bool in_tower = false;

    for (int t = 0; tower[t]; t++) {
        tow = tower[t]->circle->getBounds(tower[t]->circle);
        if (sfFloatRect_intersects(&tow, &plane1, NULL))
            in_tower = true;
        if (sfFloatRect_intersects(&tow, &plane2, NULL))
            in_tower = true;
    }
    return (in_tower);
}

static void plane_in_rect(plane_t **planes, tower_t **tower,
sfFloatRect rect, int j)
{
    sfFloatRect plane1;
    sfFloatRect plane2;

    plane1 = planes[j]->rectangle->getBounds(planes[j]->rectangle);
    if (!sfFloatRect_intersects(&rect, &plane1, NULL))
        return;
    for (int i = j + 1; planes[i]; i++) {
        plane2 = planes[i]->rectangle->getBounds(planes[i]->rectangle);
        if (sfFloatRect_intersects(&rect, &plane2, NULL)
        && sfFloatRect_intersects(&plane1, &plane2, NULL)
        && (!check_tower(tower, plane1, plane2))) {
            planes[j]->visible = false;
            planes[j]->pos = (sfVector2f) {-100, -100};
            planes[j]->dir = (sfVector2f) {0, 0};
            planes[i]->visible = false;
            planes[i]->pos = (sfVector2f) {-100, -100};
            planes[i]->dir = (sfVector2f) {0, 0};
        }
    }
}

static void plane_crash(plane_t **planes, tower_t **tower,
rectangle_t **rectangles)
{
    sfFloatRect rect;

    for (int r = 0; rectangles[r]; r++) {
        rect = rectangles[r]->getBounds(rectangles[r]);
        for (int j = 0; planes[j]; j++)
            plane_in_rect(planes, tower, rect, j);
    }
}

static bool event_isover(plane_t **planes)
{
    for (int i = 0; planes[i]; i++) {
        if (planes[i]->pos.x != -100 && planes[i]->pos.y != -100)
            return (false);
    }
    return (true);
}

static const events_t def_events = {
    {
    .name = "Events",
    .size = sizeof(events_t),
    .ctor = &events_ctor,
    .dtor = &events_dtor
    },
    .IsEvent = &is_events,
    .crash = &plane_crash,
    .IsOver = &event_isover
};

const class_t *Events = (class_t *)&def_events;
