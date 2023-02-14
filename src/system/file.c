/*
** EPITECH PROJECT, 2022
** file
** File description:
** gets the file
*/

#include "file.h"
#include "my_arr.h"
#include "my_string.h"

static void file_ctor(void *file, va_list *list)
{
    FILE(file)->path = va_arg(*list, char *);
    if (!FILE(file)->path) {
        file = NULL;
        return;
    }
    FILE(file)->file_str = FILE(file)->read(FILE(file)->path);
    if (!FILE(file)->file_str) {
        file = NULL;
        return;
    }
    FILE(file)->file_arr = FILE(file)->split(FILE(file)->file_str,
    va_arg(*list, int));
}

static void file_dtor(void *file)
{
    free_arr(FILE(file)->file_arr);
    free(FILE(file)->file_str);
    free(FILE(file));
}

static char *file_read(char *path)
{
    char *buf = NULL;
    int fd = 0;
    long int size = file_size(path);

    if (size == 0) {
        my_puterror("wrong file size\n");
        return (NULL);
    }
    if ((fd = open(path, O_RDONLY)) == -1) {
        my_puterror("could not open file\n");
        return (NULL);
    }
    buf = my_malloc_ini((int) size);
    if (read(fd, buf, (int) size) == -1 || close(fd) == -1) {
        free(buf);
        my_puterror("could not read file\n");
        return (NULL);
    }
    return (buf);
}

static char **file_split(char *str, char separator)
{
    return (my_split(str, separator));
}

static const file_t def_file = {
    {
    .name = "File",
    .size = sizeof(file_t),
    .ctor = &file_ctor,
    .dtor = &file_dtor
    },
    .read = &file_read,
    .split = &file_split,
    .path = NULL,
    .file_str = NULL,
    .file_arr = NULL
};

const class_t *File = (class_t *)&def_file;
