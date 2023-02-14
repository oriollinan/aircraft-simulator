/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** flight simulator
*/

#include "my_radar.h"
#include "my_string.h"
#include "system.h"

int display_help(void)
{
    my_putstr("Air traffic simulation panel\n"
    "USAGE\n"
    " ./my_radar [OPTIONS] path_to_script\n"
    "  path_to_script The path to the script file.\n"
    "OPTIONS\n"
    " -h\t\t\tprint the usage and quit.\n"
    "USER INTERACTIONS\n"
    " ‘L’ key\t\tenable/disable hitboxes and areas.\n"
    " ‘S’ key\t\tenable/disable sprites.");
    return (0);
}

int main(int ac, char **av)
{
    system_t *system = NULL;

    if (ac != 2) {
        my_puterror("wrong number of \n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_help());
    if (error_handling(ac, av) == true)
        return (84);
    system = (system_t *)new(System, av[1]);
    if (!system)
        return (84);
    system->run(system);
    system->class.dtor(system);
    return (0);
}
