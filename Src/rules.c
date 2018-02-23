/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** rules.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "duck_hunt.h"

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i = i + 1;
	}
}

int rules(char **av, system_t *system)
{
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		my_putstr("GAME BACKGROUND :\nA little city 'Fletch' is attac");
		my_putstr("k by ducks every day at 6:00 pm.\nThey recruit you");
		my_putstr(" for kill all the ducks who want to go in the city");
		my_putstr(".\n");
		my_putstr("\nGAME RULES :\nYou have to kill all the ducks on ");
		my_putstr("the screen before they reach the city on the right");
		my_putstr(" of the screen.\nYour weapon have a scope, use it ");
		my_putstr("if you want to increase your accuracy.\n\nGAME COM");
		my_putstr("MANDS :\n-Shot = Mouse Left Button\n-Scope = Mouse");
		my_putstr(" Right Button\n-Pause = Echap Key\n");
	} else {
		my_putstr("This game don't take arguments\nIf you want some ");
		my_putstr("help type -h\n");
	}
	destroy_system(system);
	return (0);
}
