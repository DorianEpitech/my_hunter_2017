/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** shot.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "duck_hunt.h"

bird_t *touch_first(bird_t *bird)
{
	bird_t *result = bird;

	result = bird->next;
	destroy_bird(bird, 1);
	return (result);
}

bird_t *touch(bird_t *bird, int check, bird_t *tmp, int i)
{
	bird_t *result = bird;

	if (check == 0) {
		return (touch_first(bird));
	} else if (tmp->next == NULL) {
		while (i < check - 1) {
			result = result->next;
			i = i + 1;
		}
		destroy_bird(result->next, 1);
		result->next = NULL;
	} else {
		while (i < check - 1) {
			result = result->next;
			i = i + 1;
		}
		destroy_bird(result->next, 1);
		result->next = result->next->next;
	}
	return (bird);
}

bird_t *detect_touch_nozoom(bird_t *bird, context_t **context,
	system_t **system)
{
	int rdm = rand()%200 - 100;
	int check = 0;
	sfVector2i mouse = sfMouse_getPositionRenderWindow((*context)->window);
	bird_t *tmp = bird;

	sfMusic_play((*context)->tir);
	while (tmp != NULL && tmp->starter < (*context)->seconds) {
		if (mouse.y + rdm > tmp->y && mouse.y + rdm < tmp->y + 70
		&& mouse.x + rdm > tmp->i && mouse.x + rdm < tmp->i + 70) {
			(*system)->pos_x = tmp->i;
			(*system)->pos_y = tmp->y;
			(*system)->alive = (*system)->alive - 1;
			(*context)->check_status = 1;
			bird = touch(bird, check, tmp, 0);
		}
		check = check + 1;
		tmp = tmp->next;
	}
	return (bird);
}

bird_t *detect_touch_zoom(bird_t *bird, context_t **context, system_t **system)
{
	int check = 0;
	sfVector2i mouse = sfMouse_getPositionRenderWindow((*context)->window);
	bird_t *tmp = bird;

	sfMusic_play((*context)->tir);
	while (tmp != NULL && tmp->starter < (*context)->seconds) {
		if (mouse.y > tmp->y && mouse.y < tmp->y + 70
		&& mouse.x > tmp->i && mouse.x < tmp->i + 70) {
			(*system)->pos_x = tmp->i;
			(*system)->pos_y = tmp->y;
			(*system)->alive = (*system)->alive - 1;
			(*context)->check_status = 1;
			bird = touch(bird, check, tmp, 0);
		}
		check = check + 1;
		tmp = tmp->next;
	}
	return (bird);
}
