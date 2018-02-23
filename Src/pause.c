/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** pause.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "duck_hunt.h"

void display_pause(context_t **context, system_t **system, bird_t *bird,
	sfText *text)
{
	if ((*context)->zoom == 1) {
		display_window(bird, (*context), (*system), 0);
	} else if ((*context)->zoom == -1) {
		display_zoom(bird, (*context), (*system), 0);
	}
	sfText_setFont(text, (*system)->font);
	sfText_setColor(text, sfBlack);
	sfText_setString(text, "PAUSE");
	sfText_setCharacterSize(text, 450);
	sfText_setPosition(text, (sfVector2f){300, 200});
	sfRenderWindow_drawText((*context)->window, text, NULL);
	sfRenderWindow_display((*context)->window);
}

bird_t *manage_pause(context_t **context, system_t **system, sfEvent event,
	bird_t *bird)
{
	sfText *text =sfText_create();
	sfClock *clock = sfClock_create();
	float tmp = 0;
	sfTime time;

	if (event.key.code == sfKeyEscape) {
		(*system)->pause = -(*system)->pause;
		while ((*system)->pause == 1 &&
			sfRenderWindow_isOpen((*context)->window)) {
			time = sfClock_getElapsedTime(clock);
			tmp = time.microseconds/1000000.0;
			bird = analyse_events(context, event, bird, system);
			display_pause(context, system, bird, text);
		}
	}
	(*context)->seconds_pause = (*context)->seconds_pause + tmp;
	sfText_destroy(text);
	sfClock_destroy(clock);
	return (bird);
}
