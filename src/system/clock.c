/*
** EPITECH PROJECT, 2022
** clock
** File description:
** clock object
*/

#include "clock.h"

static void clock_ctor(void *clock, va_list *list)
{
    CLOCK(clock)->clock = sfClock_create();
    if (!CLOCK(clock)->clock)
        clock = NULL;
}

static void clock_dtor(void *clock)
{
    sfClock_destroy(CLOCK(clock)->clock);
    free(CLOCK(clock));
}

static float clock_time(cloc_t *clock)
{
    return (sfTime_asSeconds(sfClock_getElapsedTime(clock->clock)));
}

static const cloc_t def_clock = {
    {
    .name = "Clock",
    .size = sizeof(cloc_t),
    .ctor = &clock_ctor,
    .dtor = &clock_dtor
    },
    .time = &clock_time,
    .clock = NULL
};

const class_t *Clock = (class_t *)&def_clock;
