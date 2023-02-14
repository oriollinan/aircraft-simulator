/*
** EPITECH PROJECT, 2022
** window
** File description:
** everything related to windows
*/

#include "window.h"
#include "game.h"
#include "plane.h"
#include "tower.h"
#include "entity.h"
#include "rectangle.h"
#include "circle.h"
#include "text.h"

static void window_ctor(void *window, va_list *list)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    WINDOW(window)->window = sfRenderWindow_create(video_mode,
    "My_Radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW(window)->window, 60);
    sfRenderWindow_setMouseCursorVisible(WINDOW(window)->window, sfFalse);
}

static void window_dtor(void *window)
{
    sfRenderWindow_destroy(WINDOW(window)->window);
    free(WINDOW(window));
}

static sfBool window_isopen(window_t *window)
{
    return (sfRenderWindow_isOpen(window->window));
}

static void window_clear(window_t *window)
{
    sfRenderWindow_clear(window->window, sfBlack);
}

static void draw_entity(game_t *game)
{
    for (int i = 0; game->planes[i]; i++) {
        if (game->planes[i]->visible)
            sfRenderWindow_drawSprite(game->window->window,
            game->planes[i]->ent->sprite, NULL);
    }
    for (int i = 0; game->towers[i]; i++)
        sfRenderWindow_drawSprite(game->window->window,
        game->towers[i]->ent->sprite, NULL);
}

static void draw_hitbox(game_t *game)
{
    for (int i = 0; game->planes[i]; i++) {
        if (game->planes[i]->visible)
            sfRenderWindow_drawRectangleShape(game->window->window,
            game->planes[i]->rectangle->rect, NULL);
    }
    for (int i = 0; game->towers[i]; i++)
        sfRenderWindow_drawCircleShape(game->window->window,
        game->towers[i]->circle->circle, NULL);
}

static void window_draw(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->ent->sprite, NULL);
    sfRenderWindow_drawText(game->window->window, game->text->text, NULL);
    if (!game->entity_hidden)
        draw_entity(game);
    if (!game->hitbox_hidden)
        draw_hitbox(game);
}

static void window_display(window_t *window)
{
    sfRenderWindow_display(window->window);
}

static void window_close(window_t *window)
{
    sfRenderWindow_close(window->window);
}

static const window_t def_window = {
    {
    .name = "Window",
    .size = sizeof(window_t),
    .ctor = &window_ctor,
    .dtor = &window_dtor
    },
    .clear = &window_clear,
    .draw = &window_draw,
    .display = &window_display,
    .IsOpen = &window_isopen,
    .close = &window_close,
    .window = NULL
};

const class_t *Window = (class_t *)&def_window;
