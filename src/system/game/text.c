/*
** EPITECH PROJECT, 2022
** text
** File description:
** file for text and fonts
*/

#include "text.h"

static void text_ctor(void *text, va_list *list)
{
    TEXT(text)->font = sfFont_createFromFile(va_arg(*list, char *));
    TEXT(text)->text = sfText_create();
    sfText_setFont(TEXT(text)->text, TEXT(text)->font);
}

static void text_dtor(void *text)
{
    sfFont_destroy(TEXT(text)->font);
    sfText_destroy(TEXT(text)->text);
    free(TEXT(text));
}

static void text_set_string(text_t *text, char *str)
{
    sfText_setString(text->text, str);
}

static void text_set_position(text_t *text, sfVector2f pos)
{
    sfText_setPosition(text->text, pos);
}

static const text_t def_text = {
    {
    .name = "Text",
    .size = sizeof(text_t),
    .ctor = &text_ctor,
    .dtor = &text_dtor
    },
    .setString = &text_set_string,
    .setPosition = &text_set_position,
    .text = NULL,
    .font = NULL
};

const class_t *Text = (class_t *)&def_text;
