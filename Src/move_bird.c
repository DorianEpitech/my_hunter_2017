/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** move_bird.c
*/

#include <stdlib.h>
#include "duck_hunt.h"

sfIntRect move_rectbird(sfIntRect rect, int offset, int max_value)
{
	if (rect.left != max_value - offset) {
		rect.left = rect.left + offset;
	} else {
		rect.left = 0;
	}
	return (rect);
}

void modif_statbird(bird_t *bird, sfVideoMode mode, context_t *context)
{
	bird->seconds = 0;
	sfClock_restart(bird->clock);
	if (bird->offset == 70) {
		bird->rect = move_rectbird(bird->rect, 60, 180);
		bird->offset = -1;
	}
	bird->offset = bird->offset + 1;
	sfSprite_setTextureRect(bird->s_duck, bird->rect);
	if (bird->i < mode.width - 60) {
		bird->i = bird->i + 1;
	} else {
		context->check_status = 2;
	}
}

bird_t *move_birds(context_t *context, sfVideoMode mode, bird_t *real_bird)
{
	bird_t *bird = real_bird;

	while (bird != NULL && bird->starter < context->seconds) {
		bird->time = sfClock_getElapsedTime(bird->clock);
		bird->seconds = bird->time.microseconds/1000000.0;
		while (bird->seconds > 0.00006) {
			modif_statbird(bird, mode, context);
		}
		bird = bird->next;
	}
	return (real_bird);
}

void modif_statsystem(system_t *system, context_t **context)
{
	system->seconds = 0;
	sfClock_restart(system->clock);
	if (system->offset == 20) {
		if (system->rect.left != 480) {
			system->rect.left = system->rect.left + 60;
		} else {
			system->rect.left = 0;
			(*context)->check_status = 0;
		}
		system->offset = -1;
	}
	system->offset = system->offset + 1;
	sfSprite_setTextureRect(system->s_die, system->rect);
}

system_t *move_system(system_t *system, context_t **context)
{
	if ((*context)->check_status == 1) {
		system->time = sfClock_getElapsedTime(system->clock);
		system->seconds = system->time.microseconds/1000000.0;
		while (system->seconds > 0.00006) {
			modif_statsystem(system, context);
		}
	}
	return (system);
}
