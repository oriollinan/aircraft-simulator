/*
** EPITECH PROJECT, 2022
** error_handling.c
** File description:
** handles the errors
*/

#include "my_radar.h"
#include "my_string.h"

long int file_size(char *file)
{
    struct stat fi;

    if (stat(file, &fi) != -1) {
        if (fi.st_mode & S_IFMT == S_IFDIR)
            return (0);
        return (fi.st_size);
    }
    return (0);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size == 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    buf = my_malloc_ini(size);
    if (read(fd, buf, size) == -1) {
        free(buf);
        return (NULL);
    }
    if (close(fd) == -1) {
        free(buf);
        return (NULL);
    }
    return (buf);
}

bool error_handling(int ac, char **av)
{
    if (ac != 2)
        return (true);
    if (read_file(av[1], file_size(av[1])) == NULL)
        return (true);
    return (false);
}
