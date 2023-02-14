/*
** EPITECH PROJECT, 2022
** new
** File description:
** imitates the new function in cpp
*/

#include "my_radar.h"
#include "my_string.h"
#include "plane.h"

class_t *new(const class_t *this, ...)
{
    va_list list;
    class_t *object = malloc(this->size);

    if (!object) {
        my_puterror("malloc failed\n");
        return (NULL);
    }
    va_start(list, this);
    my_memcpy(object, this, this->size);
    if (this->ctor)
        this->ctor(object, &list);
    va_end(list);
    return (object);
}
