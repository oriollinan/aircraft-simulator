/*
** EPITECH PROJECT, 2022
** game
** File description:
** game class
*/

#include "game.h"
#include "my_arr.h"
#include "my_string.h"
#include "my_num.h"
#include "clock.h"
#include "plane.h"
#include "tower.h"
#include "window.h"
#include "events.h"
#include "rectangle.h"
#include "entity.h"
#include "text.h"

static void arr_plane_and_tower(game_t *game, char **arr)
{
    int plane_amount = 0;
    int tower_amount = 0;

    for (int i = 0; arr[i]; i++) {
        if (arr[i][0] == 'A')
            plane_amount++;
        if (arr[i][0] == 'T')
            tower_amount++;
    }
    game->planes = malloc(sizeof(plane_t *) * (plane_amount + 1));
    game->towers = malloc(sizeof(tower_t *) * (tower_amount + 1));
    if (!game->planes || !game->towers) {
        game = NULL;
        my_puterror("malloc failed\n");
        return;
    }
    game->planes[plane_amount] = NULL;
    game->towers[tower_amount] = NULL;
}

static void create_plane_and_tower(plane_t **planes,
tower_t **towers, char *str)
{
    static int plane_amount = 0;
    static int tower_amount = 0;

    if (str[0] == 'A') {
        planes[plane_amount] = (plane_t *)new(Plane, str);
        plane_amount++;
    }
    if (str[0] == 'T') {
        towers[tower_amount] = (tower_t *)new(Tower, str);
        tower_amount++;
    }
    if (!planes[plane_amount - 1] || !towers[tower_amount - 1]) {
        planes = NULL;
        towers = NULL;
        my_puterror("new failed\n");
    }
}

static void fill_plane_and_tower(game_t *game, char **arr)
{
    arr_plane_and_tower(game, arr);
    if (!game)
        return;
    for (int i = 0; arr[i]; i++) {
        create_plane_and_tower(game->planes, game->towers, arr[i]);
        if (!game->planes || !game->towers) {
            game = NULL;
            return;
        }
    }
}

static void set_quadtree(rectangle_t **rectangles, int i)
{
    static sfVector2f pos = {0, 0};

    rectangles[i]->setPosition(rectangles[i], pos);
    pos.x += 960;
    if (pos.x == 1920) {
        pos.x = 0;
        pos.y += 540;
    }
}

static void set_rectangles(game_t *game)
{
    game->rectangles = malloc(sizeof(rectangle_t *) * 5);
    if (!game->rectangles) {
        game = NULL;
        my_puterror("malloc failed\n");
        return;
    }
    for (int i = 0; i < 4; i++) {
        game->rectangles[i] = (rectangle_t *)new(Rectangle, 960.0, 540.0);
        if (!game->rectangles[i]) {
            game = NULL;
            my_puterror("new failed\n");
            return;
        }
    set_quadtree(game->rectangles, i);
    }
    game->rectangles[4] = NULL;
}

static void game_ctor(void *game, va_list *list)
{
    char **arr = va_arg(*list, char **);

    GAME(game)->window = (window_t *)new(Window);
    GAME(game)->events = (events_t *)new(Events);
    GAME(game)->ent = (entity_t *)new(Entity, "assets/map.jpeg");
    GAME(game)->text = (text_t *)new(Text, "assets/font.ttf");
    fill_plane_and_tower(GAME(game), arr);
    if (!GAME(game))
        return;
    set_rectangles(GAME(game));
}

static void game_dtor(void *game)
{
    GAME(game)->ent->class.dtor(GAME(game)->ent);
    GAME(game)->window->class.dtor(GAME(game)->window);
    GAME(game)->events->class.dtor(GAME(game)->events);
    GAME(game)->text->class.dtor(GAME(game)->text);
    for (int i = 0; GAME(game)->planes[i]; i++)
        GAME(game)->planes[i]->class.dtor(GAME(game)->planes[i]);
    free(GAME(game)->planes);
    for (int i = 0; GAME(game)->towers[i]; i++)
        GAME(game)->towers[i]->class.dtor(GAME(game)->towers[i]);
    free(GAME(game)->towers);
    for (int i = 0; GAME(game)->rectangles[i]; i++)
        GAME(game)->rectangles[i]->class.dtor(GAME(game)->rectangles[i]);
    free(GAME(game)->rectangles);
    free(GAME(game));
}

static void game_start(game_t *game, cloc_t *clock)
{
    while (game->window->IsOpen(game->window) == sfTrue) {
        game->events->IsEvent(game);
        for (int i = 0; game->planes[i]; i++) {
            game->planes[i]->move(game->planes[i], clock);
            game->planes[i]->bounds(game->planes[i]);
        }
        game->time(game, clock);
        game->window->clear(game->window);
        game->window->draw(game);
        game->window->display(game->window);
    }
}

static void game_time(game_t *game, cloc_t *clock)
{
    int size = my_intlen((int) clock->time(clock));
    sfVector2f pos = {1920, 0};
    char *time = my_malloc_ini(size);

    pos.x = 1840 - (15 * size);
    time = my_int_to_str(time, (int) clock->time(clock));
    game->text->setString(game->text, time);
    game->text->setPosition(game->text, pos);
    free(time);
}

static const game_t def_game = {
    {
    .name = "Game",
    .size = sizeof(game_t),
    .ctor = &game_ctor,
    .dtor = &game_dtor
    },
    .start = &game_start,
    .time = &game_time,
    .window = NULL,
    .events = NULL,
    .planes = NULL,
    .towers = NULL,
    .rectangles = NULL,
    .ent = NULL,
    .text = NULL,
    .entity_hidden = false,
    .hitbox_hidden = false
};

const class_t *Game = (class_t *)&def_game;
