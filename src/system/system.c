/*
** EPITECH PROJECT, 2022
** system
** File description:
** runs the game
*/

#include "system.h"
#include "game.h"
#include "file.h"
#include "clock.h"

static void system_ctor(void *system, va_list *list)
{
    SYS(system)->file = (file_t *)new(File, va_arg(*list, char *), '\n');
    if (!SYS(system)->file) {
        system = NULL;
        return;
    }
    SYS(system)->game = (game_t *)new(Game, SYS(system)->file->file_arr);
    if (!SYS(system)->game) {
        system = NULL;
        return;
    }
    SYS(system)->clock = (cloc_t *)new(Clock);
    if (!SYS(system)->clock)
        system = NULL;
}

static void system_dtor(void *system)
{
    SYS(system)->game->class.dtor(SYS(system)->game);
    SYS(system)->clock->class.dtor(SYS(system)->clock);
    SYS(system)->file->class.dtor(SYS(system)->file);
}

static void system_run(system_t *system)
{
    system->game->start(system->game, system->clock);
}

static const system_t def_system = {
    {
    .name = "System",
    .size = sizeof(system_t),
    .ctor = &system_ctor,
    .dtor = &system_dtor
    },
    .run = &system_run,
    .game = NULL,
    .file = NULL,
    .clock = NULL
};

const class_t *System = (class_t *)&def_system;
