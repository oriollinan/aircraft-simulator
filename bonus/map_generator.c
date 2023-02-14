/*
** EPITECH PROJECT, 2022
** map_generator
** File description:
** generates a map for my radar
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

bool error_handling(int ac, char **av)
{
    int fd = 0;

    if (ac != 2)
        return (true);
    if ((fd = open(av[1], O_WRONLY)) == -1)
        return (true);
    if (close(fd) == -1)
        return (true);
    return (false);
}

void plane(int fd)
{
    int width = 0;
    int height = 0;
    int speed = rand() % 10;
    int delay = rand() % 10;
    char width_str[4];
    char height_str[4];
    char speed_str[2];
    char delay_str[2];

    write(fd, "A ", 2);
    for (int i = 0; i < 2; i++) {
        width = (rand() % 1920) - 19;
        height = (rand() % 1080) - 19;
        sprintf(width_str, "%d", width);
        write(fd, width_str, strlen(width_str));
        write(fd, " ", 1);
        sprintf(height_str, "%d", height);
        write(fd, height_str, strlen(height_str));
        write(fd, " ", 1);
    }
    sprintf(speed_str, "%d", speed);
    write(fd, speed_str, strlen(speed_str));
    write(fd, " ", 1);
    sprintf(delay_str, "%d", delay);
    write(fd, delay_str, strlen(delay_str));
    write(fd, "\n", 1);
}

void tower(int fd)
{
    int width = (rand() % 1920) - 19;
    int height = (rand() % 1080) - 19;
    int radius = (rand() % 3) + 1;
    char width_str[4];
    char height_str[4];
    char radius_str[3];

    write(fd, "T ", 2);
    sprintf(width_str, "%d", width);
    write(fd, width_str, strlen(width_str));
    write(fd, " ", 1);
    sprintf(height_str, "%d", height);
    write(fd, height_str, strlen(height_str));
    write(fd, " ", 1);
    sprintf(radius_str, "%d", radius);
    write(fd, radius_str, strlen(radius_str));
    write(fd, "\n", 1);

}

int main(int ac, char **av)
{
    srand(time(NULL));
    int amount = (rand() % 100) + 1;
    int type = 0;
    int fd = 0;

    if (error_handling(ac, av))
        return (84);
    fd = open(av[1], O_WRONLY);
    for (int i = 0; i < amount; i++) {
        type = rand() % 75;
        if (type == 0)
            tower(fd);
        else
            plane(fd);
    }
}