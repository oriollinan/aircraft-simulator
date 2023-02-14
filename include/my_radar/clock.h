/*
** EPITECH PROJECT, 2022
** clok
** File description:
** h file for clock
*/

#ifndef CLOCK_H_
    #define CLOCK_H_

    #include "my_radar.h"

    #define CLOCK(clock) ((cloc_t *)clock)

    typedef struct cloc_s {
        // INHERITANCE
        class_t class;

        // METHODS
        float (*time)(struct cloc_s *);

        // ATTRIBUTES
        sfClock *clock;
    } cloc_t;

    extern const class_t *Clock;

#endif
