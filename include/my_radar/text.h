/*
** EPITECH PROJECT, 2022
** text
** File description:
** h file for text
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include "my_radar.h"

    #define TEXT(text) ((text_t *)text)

    typedef struct text_s {
        // INHERITANCE
        class_t class;

        // METHODS
        void (*setString)(struct text_s *, char *);
        void (*setPosition)(struct text_s *, sfVector2f);

        // ATTRIBUTES
        sfText *text;
        sfFont *font;
    } text_t;

    extern const class_t *Text;

#endif
